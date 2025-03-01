#include "tcpclient.h"
#include "ui_tcpclient.h"
#include "opewidget.h"
#include <QDebug>
#include <QHostAddress>
#include <QMessageBox>
#include "friend.h"
#include "book.h"
TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();
    connect(&m_tcpSocket,SIGNAL(connected()),this,SLOT(showConnect()));
    connect(&m_tcpSocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    //连接服务器
    m_tcpSocket.connectToHost(QHostAddress(m_strIP),m_usPort);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{
    QFile file(":/client.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray badata=file.readAll();
        QString strData = badata.toStdString().c_str();
        file.close();
        strData.replace("\r\n"," ");
        QStringList strList = strData.split(" ");
        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();


    }
    else
    {
        QMessageBox::critical(this,"open config","open config failed");
    }

}

TcpClient &TcpClient::getInstance()
{
    static TcpClient instance;
    instance.setWindowFlags(instance.windowFlags() | Qt::FramelessWindowHint);
    instance.setAttribute(Qt::WA_TranslucentBackground);
    return instance;
}

void TcpClient::showConnect()
{
    QMessageBox::information(this,"连接服务器","连接服务器成功");
}

void TcpClient::recvMsg()
{


    if(i&&OpeWidget::getInstance().pBook()->pDownload())
    {

        QByteArray buffer = m_tcpSocket.readAll();
        // 简化命名使用
        Book *pBook = OpeWidget::getInstance().pBook();
        pBook->m_pFile.write(buffer);
        pBook->m_iRevice += buffer.size();
        if(pBook->m_iTotal == pBook->m_iRevice)
        {
            pBook->m_pFile.close();
            pBook->m_iTotal = 0;
            pBook->m_iRevice = 0;
            pBook->setPDownload(false);
            QMessageBox::information(&OpeWidget::getInstance(), "下载文件", "下载文件成功");
        }
        else if(pBook->m_iTotal < pBook->m_iRevice)
        {
            pBook->m_pFile.close();
            pBook->m_iTotal = 0;
            pBook->m_iRevice = 0;
            pBook->setPDownload(false);
            QMessageBox::critical(&OpeWidget::getInstance(), "下载文件", "下载文件失败：传输的文件错误");
        }
        //其他情况代表数据还未下载完成
        return ;
    }
    i=true;
    qDebug()<<m_tcpSocket.bytesAvailable();
    uint uiPDULen = 0;
    m_tcpSocket.read((char *)&uiPDULen,sizeof(uint));
    uint uiMsgLen = uiPDULen-sizeof(PDU);
    PDU *pdu = mkPDU(uiMsgLen);
    m_tcpSocket.read((char *)pdu+sizeof(uint),uiPDULen-sizeof(uint));
    qDebug()<< pdu->uiMsgType <<(char *)pdu->caMsg;

    switch(pdu->uiMsgType)
    {
    case ENUM_MSG_TYPE_REGIST_RESPOND:
    {
        if(0 == strcmp(pdu->caData,REGIST_OK))
        {
            QMessageBox::information(this,"注册",REGIST_OK);

        }
        else if(0 == strcmp(pdu->caData,REGIST_FAILED))
        {
            QMessageBox::warning(this,"注册",REGIST_FAILED);
        }
        break;
    }
    case ENUM_MSG_TYPE_LOGIN_RESPOND:
    {
        if(0 == strcmp(pdu->caData,LOGIN_OK))
        {
            m_strCurPath = QString("./%1").arg(m_strLoginName);
            QMessageBox::information(this,"登录",LOGIN_OK);
            OpeWidget::getInstance().show();
            this->hide();
        }
        else if(0 == strcmp(pdu->caData,LOGIN_FAILED))
        {
            QMessageBox::warning(this,"登录",LOGIN_FAILED);
        }
        break;
    }
    case ENUM_MSG_TYPE_ALL_ONLINE_RESPOND:
    {
        OpeWidget::getInstance().pFriend()->showAllOnlineUsr(pdu);
        break;
    }
    case ENUM_MSG_TYPE_SEARCH_USR_RESPOND:
    {
        if(0 == strcmp(pdu->caData,SEARCH_USR_NO))
        {
            QMessageBox::information(&OpeWidget::getInstance(),"搜索",OpeWidget::getInstance().pFriend()->m_strSearchName+": "+SEARCH_USR_NO);

        }
        else if(0 == strcmp(pdu->caData,SEARCH_USR_ONLINE))
        {
            QMessageBox::information(&OpeWidget::getInstance(),"搜索",OpeWidget::getInstance().pFriend()->m_strSearchName+": "+SEARCH_USR_ONLINE);
        }
        else if(0 == strcmp(pdu->caData,SEARCH_USR_OFFLINE))
        {
            QMessageBox::information(&OpeWidget::getInstance(),"搜索",OpeWidget::getInstance().pFriend()->m_strSearchName+": "+SEARCH_USR_OFFLINE);
        }
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
    {
        char caName[32]={'\0'};
        strncpy(caName,pdu->caData+32,32);
        int ret=QMessageBox::information(&OpeWidget::getInstance(),"添加好友",QString("%1 want to add you as friend ?").arg(caName),QMessageBox::Yes,QMessageBox::No);
        PDU *respdu=mkPDU(0);
        memcpy(respdu->caData,pdu->caData,64);
        if(QMessageBox::Yes ==ret)
        {
            respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_AGREE;
        }
        else if(QMessageBox::No == ret)
        {
            respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_REFUSE;
        }
        m_tcpSocket.write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        pdu=NULL;
        break;

    }
    case ENUM_MSG_TYPE_ADD_FRIEND_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(),"添加好友",pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_AGREE_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(),"添加好友",pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REFUSE_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(),"添加好友",pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND:{
        OpeWidget::getInstance().pFriend()->updateFriendList(pdu);

        break;
    }
    case ENUM_MSG_TYPE_DELETE_FRIEND_RESPOND: {
        QMessageBox::information(&OpeWidget::getInstance(), "删除好友", pdu->caData);
        OpeWidget::getInstance().pFriend()->onRefreshListClicked();
        break;
    }
    // 接受转发回来的消息
    case ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST:{
        char Name[32] = {'\0'};//登录者的名称
        strncpy(Name, pdu->caData + 32, 32);
        QMessageBox::information(&OpeWidget::getInstance(), "删除好友", QString("%1 已经删除了您的好友").arg(Name));
        OpeWidget::getInstance().pFriend()->onRefreshListClicked();
        break;
    }
    case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
    {
        OpeWidget::getInstance().pFriend()->updateMsg(pdu);
        break;
    }
    case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
    {
        OpeWidget::getInstance().pFriend()->updateGroupMsg(pdu);
        break;
    }
    case ENUM_MSG_TYPE_CREATE_DIR_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(), "创建文件夹", pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_FLUSH_DIR_RESPOND:{
        OpeWidget::getInstance().pBook()->updateFileList(pdu);
        break;
    }
    case ENUM_MSG_TYPE_DEL_DIR_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(), "删除文件夹", pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_RENAME_DIR_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(), "重命名文件", pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_ENTER_DIR_RESPOND:{

        // 如果请求成功了
        if(0 == strcmp(ENTER_DIR_OK,pdu->caData))
        {
            setStrCurPath(OpeWidget::getInstance().pBook()->enterPath());

            OpeWidget::getInstance().pBook()->updateFileList(pdu);
        }
        else
        {
            QMessageBox::information(&OpeWidget::getInstance(), "进入文件夹", pdu->caData);
        }
        break;
    }
    case ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(), "上传文件", pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND:
    {
        char caFileName[32] = {'\0'};
        sscanf(pdu->caData, "%s %lld", caFileName, &(OpeWidget::getInstance().pBook()->m_iTotal));
        // 如果是有效数据
        if(strlen(caFileName) > 0 && OpeWidget::getInstance().pBook()->m_iTotal > 0)
        {
            OpeWidget::getInstance().pBook()->setPDownload(true);//标记开始下载文件
            OpeWidget::getInstance().pBook()->m_iRevice = 0;
            OpeWidget::getInstance().pBook()->updateLocalDownloadFileName();
            // 只写模式打开文件，文件如果不存在则会被创建
            if(!OpeWidget::getInstance().pBook()->m_pFile.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(this, "下载文件", "下载文件失败：本地文件无法操作");
                // 由于服务器已经开始发送下载文件的数据了，这个时候应该怎么办呢？【】
                return ;
            }
        }
        break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_RESPOND:
    {
        QMessageBox::information(&OpeWidget::getInstance(), "分享文件", pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_NOTE:
    {
        qDebug() << "开始准备接受文件";
        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath, (char*)pdu->caMsg, pdu->uiMsgLen);
        // aa/bb/cc/a.txt
        qDebug() << pPath;
        char *pos = strrchr(pPath, '/'); //找到最后一个 / 出现的位置
        qDebug() << pos;
        if(NULL != pos)
        {
            pos++; // 向右移动一位，因为 / 这个字符我们不需要，只需要文件名称，即a.txt
            QString strNote = QString("%1 share file -> %2\n do you accecpt").arg(pdu->caData).arg(pos);
            int ret = QMessageBox::question(&OpeWidget::getInstance(), "共享文件", strNote);
            if(QMessageBox::Yes == ret)
            {
                PDU *retPdu = mkPDU(pdu->uiMsgLen);
                retPdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_NOTE_REQUEST;
                memcpy(retPdu->caMsg, pdu->caMsg, pdu->uiMsgLen);
                QString strName = TcpClient::getInstance().strLoginName();
                strcpy(retPdu->caData, strName.toUtf8().toStdString().c_str());
                m_tcpSocket.write((char*)retPdu,retPdu->uiPDULen);
            }
        }

        break;
    }
    default:
        break;
    }

    free(pdu);
    pdu=NULL;
}
#if 0
void TcpClient::on_send_pb_clicked()
{
    QString strMsg = ui->name_le->text();
    if(!strMsg.isEmpty())
    {
        PDU *pdu = mkPDU(strMsg.size());
        pdu->uiMsgType=8888;
        memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
    else
    {
        QMessageBox::warning(this,"信息发送","发送的信息不能为空");
    }
}
#endif

void TcpClient::on_login_pb_clicked()
{
    QString strName=ui->name_le->text();
    QString strPwd=ui->pwd_le->text();
    if(!strName.isEmpty() && !strPwd.isEmpty())
    {
        m_strLoginName=strName;
        PDU *pdu=mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;
        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
    else
    {
        QMessageBox::warning(this,"登录","登录失败:用户名或密码为空");
    }

}


void TcpClient::on_cancel_pb_clicked()
{

}


void TcpClient::on_regist_pb_clicked()
{
    QString strName=ui->name_le->text();
    QString strPwd=ui->pwd_le->text();
    if(!strName.isEmpty() && !strPwd.isEmpty())
    {
        PDU *pdu=mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;
        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
    else
    {
        QMessageBox::warning(this,"注册","注册失败:用户名或密码为空");
    }

}

void TcpClient::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标按下时的位置
        m_dragStartPosition = event->globalPos() - frameGeometry().topLeft();
        m_isDragging = true;
        event->accept();
    }
}

void TcpClient::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging && (event->buttons() & Qt::LeftButton)) {
        // 计算窗口需要移动的距离
        move(event->globalPos() - m_dragStartPosition);
        event->accept();
    }
}

void TcpClient::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
        event->accept();
    }
}

void TcpClient::setStrCurPath(const QString &newStrCurPath)
{
    m_strCurPath = newStrCurPath;
}

QString TcpClient::strCurPath() const
{
    return m_strCurPath;
}

QString TcpClient::strLoginName() const
{
    return m_strLoginName;
}

QTcpSocket &TcpClient::tcpSocket()
{
    return m_tcpSocket;
}

