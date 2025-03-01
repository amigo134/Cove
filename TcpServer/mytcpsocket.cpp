#include "mytcpsocket.h"
#include "mytcpserver.h"
#include <QDir>
MyTcpSocket::MyTcpSocket(QObject *parent)
    : QTcpSocket{parent}
{
    m_pTimer = new QTimer;
    m_bUpload = false;//定义最开始不是上传文件的状态
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    connect(this,SIGNAL(disconnected()),this,SLOT(clientOffline()));
    connect(m_pTimer, SIGNAL(timeout()),
            this, SLOT(sendFileDataToClient()));
}

void MyTcpSocket::recvMsg()
{
    int flag=1;
    // 如果是上传文件
    if(m_bUpload)
    {
        // 上传的文件过大可能会导致客户端崩溃
        // 这里需要readAll多次，因为可能文件还没有发送完成
        flag=0;
        PDU *pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND;
        // 写入文件
        QByteArray buff = readAll();
        m_file.write(buff);
        m_iRecved += buff.size();

        qDebug() << QString("第 %1 次传入文件,接受数据大小:%2").arg(m_iCount).arg(buff.size());
        m_iCount++;
        // 读取文件内容完成，向客户端发送信息上传成功
        if(m_iTotal == m_iRecved)
        {
            m_bUpload = false;
            m_file.close();
            strcpy(pdu->caData, UPLOAD_FILE_OK);
            write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
        // 读取数据错误的情况下不再读取了，向客户端发送信息提示结束上传
        else if(m_iTotal < m_iRecved)
        {
            m_bUpload = false;
            m_file.close();
            strcpy(pdu->caData, UPLOAD_FILE_FAIL);
            write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
        // 其他情况代表文件上传未完成，等待结束数据
        return ;
    }
    qDebug()<<this->bytesAvailable();
    uint uiPDULen = 0;

    this->read((char *)&uiPDULen,sizeof(uint));
    uint uiMsgLen = uiPDULen-sizeof(PDU);
    PDU *pdu = mkPDU(uiMsgLen);
    this->read((char *)pdu+sizeof(uint),uiPDULen-sizeof(uint));
    qDebug()<< pdu->uiMsgType <<(char *)pdu->caMsg;
    PDU *respdu = mkPDU(0);
    switch(pdu->uiMsgType)
    {
    case ENUM_MSG_TYPE_REGIST_REQUEST:
    {
        char caName[32]={'\0'};
        char caPwd[32]={'\0'};
        strncpy(caName,pdu->caData,32);
        strncpy(caPwd,pdu->caData+32,32);
        qDebug()<< caName <<caPwd;
        bool ret = OpeDB::getInstance().handleRegist(caName,caPwd);

        respdu->uiMsgType=ENUM_MSG_TYPE_REGIST_RESPOND;
        if(ret)
        {
            strcpy(respdu->caData,REGIST_OK);
            QDir dir;
            qDebug()<<"create dir :"<<dir.mkdir(QString("./%1").arg(caName));
        }
        else
        {
            strcpy(respdu->caData,REGIST_FAILED);
        }
        break;
    }
    case ENUM_MSG_TYPE_LOGIN_REQUEST:  {
        char caName[32]={'\0'};
        char caPwd[32]={'\0'};
        strncpy(caName,pdu->caData,32);
        strncpy(caPwd,pdu->caData+32,32);
        qDebug()<< caName <<caPwd;
        bool ret = OpeDB::getInstance().handleLogin(caName,caPwd);
        respdu->uiMsgType=ENUM_MSG_TYPE_LOGIN_RESPOND;
        if(ret)
        {
            strcpy(respdu->caData,LOGIN_OK);
            m_strName=caName;
        }
        else
        {
            strcpy(respdu->caData,LOGIN_FAILED);
        }
        break;}
    case ENUM_MSG_TYPE_ALL_ONLINE_REQUEST:  {
        QStringList ret=OpeDB::getInstance().handleALLOnline();
        uint uiMsgLen = ret.size()*32;
        respdu = mkPDU(uiMsgLen);
        respdu->uiMsgType=ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;
        for(int i=0;i<ret.size();i++)
        {
            memcpy((char *)(respdu->caMsg)+i*32,ret.at(i).toStdString().c_str(),ret.at(i).size());
        }
        break;}
    case ENUM_MSG_TYPE_SEARCH_USR_REQUEST:{
        int ret = OpeDB::getInstance().handleSearchUsr(pdu->caData);
        respdu=mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USR_RESPOND;
        if(-1 == ret)
        {
            strcpy(respdu->caData,SEARCH_USR_NO);
        }
        else if(1 == ret)
        {
            strcpy(respdu->caData,SEARCH_USR_ONLINE);
        }
        else if(0 == ret)
        {
            strcpy(respdu->caData,SEARCH_USR_OFFLINE);
        }
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
    {
        char pername[32]={'\0'};
        char name[32]={'\0'};
        strncpy(pername,pdu->caData,32);
        strncpy(name,pdu->caData+32,32);
        int ret=OpeDB::getInstance().handleAddFriend(pername,name);
        respdu=mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
        if(-1 == ret)
        {
            strcpy(respdu->caData,UNKNOW_ERROR);
        }
        else if(0 == ret)
        {
            strcpy(respdu->caData,EXIST_FRIEND);
        }
        else if(1 == ret)
        {
            flag=0;
            MyTcpServer::getInstance().resend(pername,pdu);
        }
        else if(2 == ret)
        {
            strcpy(respdu->caData,ADD_FRIEND_OFFLINE);
        }
        else if(3 == ret)
        {
            strcpy(respdu->caData,ADD_FRIEND_NO_EXIST);
        }
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_AGREE:
    {
        char pername[32]={'\0'};
        char name[32]={'\0'};
        strncpy(pername,pdu->caData,32);
        strncpy(name,pdu->caData+32,32);
        bool ret=OpeDB::getInstance().handleAgreeFriend(pername,name);
        respdu=mkPDU(0);
        respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_AGREE_RESPOND;
        if(ret)
        {
            strcpy(respdu->caData,ADD_FRIEND_AGREE_SUCCEED);

        }
        else
        {
            strcpy(respdu->caData,ADD_FRIEND_AGREE_FAILED);

        }
         MyTcpServer::getInstance().resend(name,respdu);
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REFUSE:
    {
        flag=0;
        char pername[32]={'\0'};
        char name[32]={'\0'};
        strncpy(pername,pdu->caData,32);
        strncpy(name,pdu->caData+32,32);
        respdu=mkPDU(0);
        respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_REFUSE_RESPOND;
        strcpy(respdu->caData,ADD_FRIEND_REFUSE);
        MyTcpServer::getInstance().resend(name,respdu);
        break;
    }
    case ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST:{
        char caLoginName[32] = {'\0'};
        strncpy(caLoginName, pdu->caData, 32);
        QStringList ret = OpeDB::getInstance().handleFlushFriend(caLoginName);
        uint uiMsgLen = ret.size() * 32;
        respdu = mkPDU(uiMsgLen);
        respdu -> uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND;
        for(int i = 0; i < ret.size(); i++)
        {
            // 记住，这里放的应该的char*，而不是int[], 因为是要复制char*的内容过来
            memcpy((char*)(respdu->caMsg) + i * 32
                   , ret.at(i).toStdString().c_str()
                   , ret.at(i).size());
        }
        break;
    }
    case ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST:
    {
        char pername[32]={'\0'};
        char name[32]={'\0'};
        strncpy(pername,pdu->caData,32);
        strncpy(name,pdu->caData+32,32);
        bool ret=OpeDB::getInstance().handleDelFriend(pername,name);
        respdu=mkPDU(0);
        respdu->uiMsgType=ENUM_MSG_TYPE_DELETE_FRIEND_RESPOND;
        strcpy(respdu->caData,DELETE_FRIEND_OK);
        MyTcpServer::getInstance().resend(pername,pdu);
        break;
    }
    case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:{
        // 获取客户端传输过来的好友名称
        char perName[32] = {'\0'};
        strncpy(perName, pdu->caData, 32);
        MyTcpServer::getInstance().resend(perName, pdu);
        break;
    }
    case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
    {
        char Name[32] = {'\0'};
        strncpy(Name, pdu->caData, 32);
        QStringList strNameList=OpeDB::getInstance().handleFlushFriend(Name);

        for(int i = 0; i < strNameList.size(); i++)
        {
            MyTcpServer::getInstance().resend(strNameList.at(i).toStdString().c_str(), pdu);
        }
        break;
    }
    case ENUM_MSG_TYPE_CREATE_DIR_REQUEST:
    {
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
        QString strCurPath = QString("%1").arg((char*)pdu->caMsg);
        QDir dir;
        bool ret = dir.exists(strCurPath);
        if(ret)
        {
            // 获取客户端传输过来的名称
            char caLoginName[32] = {'\0'};
            char caDirName[32] = {'\0'};
            // 前32位是登录者名称，后32位是新增文件夹名称
            strncpy(caLoginName, pdu->caData, 32);
            strncpy(caDirName, pdu->caData + 32, 32);
            QString strNewPath = strCurPath + "/" + caDirName;
            ret = dir.exists(strNewPath);
            // 如果要新建的文件夹已经存在了
            if(ret)
            {
                strcpy(respdu->caData, FILE_NAME_EXIST);
            }
            else
            {
                ret = dir.mkdir(strNewPath);
                if(!ret)
                {
                    strcpy(respdu->caData, CREATE_DIR_ERROR);

                }
                else
                {
                    strcpy(respdu->caData, CREATE_DIR_OK);
                }
            }
        }
        else
        {
            strcpy(respdu->caData, CUR_DIR_NOT_EXIST);
        }
    }
    case ENUM_MSG_TYPE_FLUSH_DIR_REQUEST:
    {

        char *pCurPath = new char[pdu->uiMsgLen];

        memcpy(pCurPath, (char*)pdu->caMsg, pdu->uiMsgLen);

        QDir dir(pCurPath);
        QFileInfoList fileInfoList = dir.entryInfoList();
        int iFileCount = fileInfoList.size();

        qDebug()<<fileInfoList.size()<<"个数";
        respdu = mkPDU(sizeof(FileInfoStruct) * iFileCount);

        respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_DIR_RESPOND;


        FileInfoStruct *pFileInfo = NULL;
        for(int i = 0; i < iFileCount; i++)
        {
            // 获取返回PDU中第i块FileInfo的内存区域，向里面塞入数据
            pFileInfo = (FileInfoStruct *)respdu->caMsg + i;

            pFileInfo->fileSize = fileInfoList[i].size();


           strcpy(pFileInfo->lastModified, fileInfoList[i].lastModified().toString("yyyy-MM-dd hh:mm:ss").toUtf8().toStdString().c_str());

            strcpy(pFileInfo->caFileName, fileInfoList[i].fileName().toUtf8().toStdString().c_str());
            qDebug()<<pFileInfo->caFileName<<"名字";
            if(fileInfoList[i].isDir())
            {
                pFileInfo->fileType = 0;
            }
            else if(fileInfoList[i].isFile())
            {
                pFileInfo->fileType = 1;
            }
            else
            {
                pFileInfo->fileType = 2;
            }

        }
        free(pCurPath);
        pCurPath=NULL;
        break;
    }
    case ENUM_MSG_TYPE_DEL_DIR_REQUEST:
    {
        char caName[32] = {'\0'};
        strcpy(caName, pdu->caData);
        char *curPath = new char[pdu->uiMsgLen];
        memcpy(curPath, pdu->caMsg, pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(curPath).arg(caName);
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_RESPOND;
        // 文件对象
        QFileInfo fileInfo(strPath);
        if(fileInfo.isDir())
        {
            QDir dir;
            dir.setPath(strPath);
            // 删文件包括其中的内容
            bool ret = dir.removeRecursively();
            // 如果删除失败
            if(!ret)
            {

                memcpy(respdu->caData, DEL_DIR_SYSTEM_ERROR, strlen(DEL_DIR_SYSTEM_ERROR));
            }
            else
            {

                memcpy(respdu->caData, DEL_DIR_OK, strlen(DEL_DIR_OK));
            }
        }
        else
        {
            QDir dir;
            // 删除文件目录中的该文件
            bool ret = dir.remove(strPath);
            // 如果删除失败
            if(!ret)
            {

                memcpy(respdu->caData, DEL_FILE_SYSTEM_ERROR, strlen(DEL_FILE_SYSTEM_ERROR));
            }
            else
            {

                memcpy(respdu->caData, DEL_FILE_OK, strlen(DEL_FILE_OK));
            }
        }
        break;
    }
    case ENUM_MSG_TYPE_RENAME_DIR_REQUEST:
    {
        char caOldName[32] = {'\0'};
        char caNewName[32] = {'\0'};
        strncpy(caOldName, pdu->caData, 32);
        strncpy(caNewName, pdu->caData + 32, 32);

        char *curPath = new char[pdu->uiMsgLen];
        memcpy(curPath, (char*)pdu->caMsg, pdu->uiMsgLen);
        QString strOldPath = QString("%1/%2").arg(curPath).arg(caOldName);
        QString strNewPath = QString("%1/%2").arg(curPath).arg(caNewName);
        QDir dir;
        bool ret = dir.rename(strOldPath, strNewPath);
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_RENAME_DIR_RESPOND;
        // 如果重命名成功
        if(ret)
        {
            strcpy(respdu->caData, RENAME_FILE_OK);
        }
        else
        {
            strcpy(respdu->caData, RENAME_FILE_FIAL);
        }
        break;
    }
    case ENUM_MSG_TYPE_ENTER_DIR_REQUEST:
    {
        flag=0;
        char caEnterName[32] = {'\0'};
        strncpy(caEnterName, pdu->caData, 32);

        char *caCurPath = new char[pdu->uiMsgLen];
        memcpy(caCurPath, (char*)pdu->caMsg, pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(caCurPath).arg(caEnterName);
        QFileInfo fileInfo(strPath);
        if(fileInfo.isFile())
        {
            PDU *retPdu = mkPDU(0);
            retPdu->uiMsgType = ENUM_MSG_TYPE_ENTER_DIR_RESPOND;
            strcpy(retPdu->caData, ENTER_DIR_FAIL);
            write((char*)retPdu, retPdu->uiPDULen);
            free(retPdu);
            retPdu = NULL;
        }
        else if(fileInfo.isDir())
        {
            QDir dir(strPath);
            QFileInfoList fileInfoList = dir.entryInfoList();
            int iFileCount = fileInfoList.size();

            qDebug()<<fileInfoList.size()<<"个数";
            PDU *retPdu = mkPDU(sizeof(FileInfoStruct) * iFileCount);
            retPdu->uiMsgType = ENUM_MSG_TYPE_ENTER_DIR_RESPOND;
            FileInfoStruct *pFileInfo = NULL;
            for(int i = 0; i < iFileCount; i++)
            {
                // 获取返回PDU中第i块FileInfo的内存区域，向里面塞入数据
                pFileInfo = (FileInfoStruct *)retPdu->caMsg + i;
                pFileInfo->fileSize = fileInfoList[i].size();
                strcpy(pFileInfo->lastModified, fileInfoList[i].lastModified().toString("yyyy-MM-dd hh:mm:ss").toUtf8().toStdString().c_str());
                strcpy(pFileInfo->caFileName, fileInfoList[i].fileName().toUtf8().toStdString().c_str());
                qDebug()<<pFileInfo->caFileName<<"名字";

                if(fileInfoList[i].isDir())
                {
                    pFileInfo->fileType = 0;
                }
                else if(fileInfoList[i].isFile())
                {
                    pFileInfo->fileType = 1;
                }
                else
                {
                    pFileInfo->fileType = 2;
                }
            }
            strcpy(retPdu->caData, ENTER_DIR_OK);
            write((char*)retPdu, retPdu->uiPDULen);
            free(retPdu);
            retPdu = NULL;
        }
        break;
        }
    case ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST:
        {
            char caFileName[64] = {'\0'};
            qint64 fileSize = 0;
            sscanf(pdu->caData, "%s %lld", caFileName, &fileSize);
            char *curPath = new char[pdu->uiMsgLen];
            memcpy(curPath, (char*)pdu->caMsg, pdu->uiMsgLen);
            QString strPath = QString("%1/%2").arg(curPath).arg(caFileName);
            delete []curPath;
            curPath = NULL;
            m_file.setFileName(strPath);
            // 以只写的方式打开文件，如果文件不存在，则自动创建文件
            if(m_file.open(QIODevice::WriteOnly))
            {
                m_bUpload = true;
                m_iTotal = fileSize;
                m_iRecved = 0;
                m_iCount = 1;
            }
            break;
        }
    case ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST:
        {
            flag=0;
            char caFileName[32] = {'\0'};
            strcpy(caFileName, pdu->caData);
            char *curPath = new char[pdu->uiMsgLen];
            memcpy(curPath, pdu->caMsg, pdu->uiMsgLen);
            QString strPath = QString("%1/%2").arg(curPath).arg(caFileName);
            delete []curPath;
            curPath = NULL;
            QFileInfo fileInfo(strPath);
            qint64 fileSize = fileInfo.size();
            PDU *retPdu = mkPDU(0);
            retPdu->uiMsgType = ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND;
            sprintf(retPdu->caData, "%s %lld", caFileName, fileSize);
            write((char*)retPdu, retPdu->uiPDULen);
            free(retPdu);
            retPdu = NULL;
            // 借用 m_file对象进行下载文件，因为目前是单线程阻塞的，所以不影响
            m_file.setFileName(strPath);
            m_file.open(QIODevice::ReadOnly);
            // 定时器设置1s后发送数据
            m_pTimer->start(1000);
            break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_REQUEST:
    {
        char caSendName[32] = {'\0'};
        int num = 0;
        sscanf(pdu->caData, "%s %d", caSendName, &num);
        qDebug()<<num<<"数量";
        int size = num * 32;
        PDU *retPdu = mkPDU(pdu->uiMsgLen - size);//下载文件的路径的大小
        retPdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_NOTE;
        strcpy(retPdu->caData, caSendName);
        memcpy((char*)retPdu->caMsg, (char*)(pdu->caMsg) + size, pdu->uiMsgLen - size);
        char caRecvName[32] = {'\0'};
        for(int i = 0; i < num ; i++)
        {
            memcpy(caRecvName, (char*)(pdu->caMsg) + i * 32, 32);
            qDebug() << "要转发给该好友文件:"
                     <<caRecvName;
            MyTcpServer::getInstance().resend(caRecvName, retPdu);
        }
        free(retPdu);
        retPdu = NULL;
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_RESPOND;
        strcpy(respdu->caData, "send share file msg ok");
        write((char*)respdu, respdu->uiPDULen);
        break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_NOTE_REQUEST:
    {
        QString strRecvPath = QString("./%1").arg(pdu->caData);
        QString strShareFilePath = QString("%1").arg((char*)pdu->caMsg);
        int index = strShareFilePath.lastIndexOf('/');
        QString fileName = strShareFilePath.right(strShareFilePath.size() - index - 1);
        strRecvPath = strRecvPath + "/" + fileName;
        QFileInfo qFileInfo(strShareFilePath);
        if(qFileInfo.isFile())
        {
            QFile::copy(strShareFilePath, strRecvPath);
        }
        else if(qFileInfo.isDir())
        {
            copyDir(strShareFilePath, strRecvPath);
        }
        respdu = mkPDU(0);
        respdu->uiMsgLen = ENUM_MSG_TYPE_SHARE_FILE_NOTE_RESPOND;
        strcpy(respdu->caData, "copy file ok");
    }
    default:
        break;
    }
    if(flag!=0)
    this->write((char*)respdu,respdu->uiPDULen);
    free(respdu);
    respdu=NULL;
    free(pdu);
    pdu=NULL;

}
void MyTcpSocket::copyDir(QString sourceDir, QString targetDir)
{
    QDir dir;
    dir.mkdir(targetDir);//创建目标文件夹，防止文件夹不存在
    dir.setPath(sourceDir);
    QFileInfoList fileInfoList = dir.entryInfoList();
    QString sourceTemp;
    QString targetTemp;
    for(int i = 0; i < fileInfoList.size(); i++)
    {
        sourceTemp = sourceDir + "/" + fileInfoList.at(i).fileName();
        targetTemp = targetDir + "/" + fileInfoList.at(i).fileName();
        if(fileInfoList.at(i).isFile())
        {
            QFile::copy(sourceTemp, targetTemp);
        }
        else if(fileInfoList.at(i).isDir())
        {
            // 不复制 . 和 ..目录
            if(QString(".") == fileInfoList.at(i).fileName()
                || QString("..") == fileInfoList.at(i).fileName())
            {
                continue;
            }
            copyDir(sourceTemp, targetTemp);
        }
    }
}

void MyTcpSocket::clientOffline()
{
    OpeDB::getInstance().handleOffline(m_strName.toStdString().c_str());
    emit offline(this);
}

void MyTcpSocket::sendFileDataToClient()
{
    m_pTimer->stop();
    char *pBuffer = new char[4096];
    qint64 ret = 0;
    while(true)
    {
        ret = m_file.read(pBuffer, 4096);
        if(ret > 0 && ret <= 4096)
        {
            write(pBuffer, ret);
        }
        // 文件内容读取完成
        else if(0 == ret)
        {
            m_file.close();
            break;
        }
        // 文件读取出错
        else
        {
            m_file.close();
            // 实际开发应该记录到日志文件中
            qDebug() << "发送文件失败";
            break;
        }
    }
    delete []pBuffer;
    pBuffer = NULL;
}

QString MyTcpSocket::strName() const
{
    return m_strName;
}

