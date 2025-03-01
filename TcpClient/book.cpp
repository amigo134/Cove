#include "book.h"
#include "opewidget.h"
#include "ui_book.h"
#include "protocol.h"
#include "tcpclient.h"
#include "friend.h"
#include <QCheckBox>
#include<QDebug>
#include <QMessageBox>
#include<QFileDialog>
#include<QFile>
#include <QListWidget>
Book::Book(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Book)
{

    ui->setupUi(this);
    m_pDownload = false;
    sharePB = new QPushButton( this);
    sharePB->setFixedSize(60, 40);
    QIcon icon(":/images/images/share.png"); // 替换为实际的图标路径
    sharePB->setIcon(icon);
    sharePB->setIconSize(QSize(48, 48));
    sharePB->move(this->width()+100, this->height()+100);
    QString styleSheet = R"(
QPushButton{
    padding:4px;
    padding-left:12px;
    padding-right:12px;
    color: rgb(255, 255, 255);
    background-color: rgb(255, 255, 255);
    border:1px outset rgb(255, 255, 255);
    border-radius:18px;
}
QPushButton:hover {
    background-color: rgb(240, 250, 255);
}
QPushButton:pressed {
    background-color: rgb(240, 250, 255);
}
)";
    sharePB->setStyleSheet(styleSheet);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTimer = new QTimer;
    connect(m_pTimer, SIGNAL(timeout()),
            this, SLOT(uploadFileData()));
    connect(sharePB, &QPushButton::clicked, this, &Book::onShareButtonClicked);


}

Book::~Book()
{
    delete ui;
}

void Book::onItemChanged(QTableWidgetItem *item)
{
    disconnect(ui->tableWidget, &QTableWidget::itemChanged, this, &Book::onItemChanged);
    if (item) {
        // 获取输入的文件夹名称
        QString strDirName = item->text();
        if (!strDirName.isEmpty()) {
            // 创建文件夹
            qDebug()<<strDirName;

            QString strLoginName = TcpClient::getInstance().strLoginName();
            QString strCurPath = TcpClient::getInstance().strCurPath();
            PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
            pdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_REQUEST;
            // 用户名、新文件夹名称放在caData， 当前路径放在caMsg
            strncpy(pdu->caData, strLoginName.toUtf8().toStdString().c_str(), strLoginName.toUtf8().size());
            strncpy(pdu->caData + 32, strDirName.toUtf8().toStdString().c_str(), strDirName.toUtf8().size());
            memcpy((char *)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
            TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
        else
        {
            ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
        }
}

}

void Book::updateFileList(const PDU *pdu)
{
    if(NULL == pdu)
    {
        return ;
    }
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount > 1) {
        // 从第二行开始清除
        for (int row = 1; row < rowCount; ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                // 移除单元格的内容
                delete ui->tableWidget->takeItem(row, col);
            }
        }
        // 调整表格行数为 1
        ui->tableWidget->setRowCount(1);
    }
    FileInfoStruct *pFileInfo = NULL;
    int iFileCount = pdu->uiMsgLen / sizeof(FileInfoStruct);

    ui->tableWidget->setRowCount(iFileCount-1);
    for(int i = 2; i < iFileCount; i++)
    {
        QCheckBox *checkBox = new QCheckBox(ui->tableWidget);
        ui->tableWidget->setCellWidget(i-1, 0, checkBox);
        pFileInfo = (FileInfoStruct *)(pdu->caMsg) + i;
        // 插入文件名
        QTableWidgetItem *fileNameItem = new QTableWidgetItem(pFileInfo->caFileName);
        qDebug()<<pFileInfo->caFileName<<"名字";
        ui->tableWidget->setItem(i-1, 1, fileNameItem);
        // 插入文件大小

        if(0 == pFileInfo->fileType)
        {
            QIcon icon(":/map/map/folder.png");
            fileNameItem->setIcon(icon);
            QTableWidgetItem *fileSizeItem = new QTableWidgetItem("-");
            ui->tableWidget->setItem(i-1, 2, fileSizeItem);
        }
        else if(1 == pFileInfo->fileType)
        {

            QIcon icon(":/map/map/file.png");
            fileNameItem->setIcon(icon);
            QTableWidgetItem *fileSizeItem = new QTableWidgetItem(convertFileSize(pFileInfo->fileSize));
            ui->tableWidget->setItem(i-1, 2, fileSizeItem);

        }

        qDebug()<<pFileInfo->fileSize;



        // 插入文件类型
        QTableWidgetItem *fileTypeItem = new QTableWidgetItem(getFileInfo(pFileInfo->fileType,pFileInfo->caFileName));
        ui->tableWidget->setItem(i-1, 3, fileTypeItem);

        // 插入最后修改时间
        QTableWidgetItem *lastModifiedItem = new QTableWidgetItem(pFileInfo->lastModified);
        ui->tableWidget->setItem(i-1, 4, lastModifiedItem);

    }
}

QString Book::convertFileSize(qint64 bytes)
{
    const qint64 kb = 1024;
    const qint64 mb = kb * 1024;
    const qint64 gb = mb * 1024;

    if (bytes >= gb) {
        return QString("%1 GB").arg(static_cast<double>(bytes) / gb, 0, 'f', 2);
    } else if (bytes >= mb) {
        return QString("%1 MB").arg(static_cast<double>(bytes) / mb, 0, 'f', 2);
    } else if (bytes >= kb) {
        return QString("%1 KB").arg(static_cast<double>(bytes) / kb, 0, 'f', 2);
    } else {
        return QString("%1 B").arg(bytes);
    }
}

QString Book::getFileInfo(int fileType, const QString &fileName)
{
    if (fileType == 0) {
        return QString("文件夹");
    } else if (fileType == 1) {
        int dotIndex = fileName.lastIndexOf('.');
        QString extension;
        if (dotIndex != -1) {
            extension = fileName.mid(dotIndex + 1).toLower();
        }

        QString fileTypeStr;
        if (extension == "txt") {
            fileTypeStr = "文本文件";
        } else if (extension == "jpg" || extension == "png" || extension == "jpeg") {
            fileTypeStr = "图像文件";
        } else if (extension == "mp3" || extension == "wav") {
            fileTypeStr = "音频文件";
        } else if (extension == "mp4" || extension == "avi") {
            fileTypeStr = "视频文件";
        } else if (extension == "pdf") {
            fileTypeStr = "PDF 文件";
        } else {
            fileTypeStr = "未知类型";
        }

        if (!extension.isEmpty()) {
            return QString("%1").arg(fileTypeStr);
        } else {
            return QString("无后缀文件 (%1)").arg(fileTypeStr);
        }
    }
    return "无效的文件类型参数";
}

void Book::updateLocalDownloadFileName()
{
    m_pFile.setFileName(m_strSaveFilePath);
}



void Book::on_m_pCreateDirPB_clicked()
{

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // 创建可编辑的表格项
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->tableWidget->setItem(row, 1, item);
    connect(ui->tableWidget, &QTableWidget::itemChanged, this, &Book::onItemChanged);
    // 选中该单元格并开始编辑
    ui->tableWidget->setCurrentItem(item);
    ui->tableWidget->editItem(item);




}


void Book::on_m_pFlushFilePB_clicked()
{
    QString strCurPath = TcpClient::getInstance().strCurPath();
    PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
    pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_DIR_REQUEST;
    strncpy((char*)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
    TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
}





void Book::on_m_pDelDirPB_clicked()
{
    QString strCurPath = TcpClient::getInstance().strCurPath();
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow != -1) {
        // 假设要获取第 1 列（索引为 0）的数据
        int targetColumn = 1;
        QTableWidgetItem *item = ui->tableWidget->item(currentRow, targetColumn);
        if (item) {
            QString strDelName = item->text();
            qDebug() << "Data at row " << currentRow << ", column " << targetColumn << ": " << strDelName;
            PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
            pdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_REQUEST;
            strncpy(pdu->caData, strDelName.toUtf8().toStdString().c_str(), strDelName.toUtf8().size());
            memcpy((char*)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
            TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;

        } else {
            qDebug() << "No item at row " << currentRow << ", column " << targetColumn;
        }
    } else {
        qDebug() << "No row is selected.";


}

}

void Book::on_m_pRenamePB_clicked()
{
    // 获取当前选中的行
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow != -1) {
        // 假设要获取第 1 列（索引为 0）的数据
        int targetColumn = 1;
        QTableWidgetItem *item = ui->tableWidget->item(currentRow, targetColumn);
        if (item) {
            oldName = item->text();
            qDebug() << "Data at row " << currentRow << ", column " << targetColumn << ": " << oldName;


            connect(ui->tableWidget, &QTableWidget::itemChanged, this, &Book::rename);
            // 选中该单元格并开始编辑
            ui->tableWidget->setCurrentItem(item);
            ui->tableWidget->editItem(item);
        } else {
            qDebug() << "No item at row " << currentRow << ", column " << targetColumn;
        }
    } else {
        qDebug() << "No row is selected.";
    }
}

void Book::rename(QTableWidgetItem *item)
{
    disconnect(ui->tableWidget, &QTableWidget::itemChanged, this, &Book::rename);
    if (item) {
        // 获取输入的文件夹名称
        QString strDirName = item->text();
        if (!strDirName.isEmpty()) {
            // 创建文件夹
            qDebug()<<strDirName;

            QString strCurPath = TcpClient::getInstance().strCurPath();
            PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
            pdu->uiMsgType = ENUM_MSG_TYPE_RENAME_DIR_REQUEST;
            // 用户名、新文件夹名称放在caData， 当前路径放在caMsg
            strncpy(pdu->caData, oldName.toUtf8().toStdString().c_str(), oldName.toUtf8().size());
            strncpy(pdu->caData + 32, strDirName.toUtf8().toStdString().c_str(), strDirName.toUtf8().size());
            memcpy((char *)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
            TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
}
}


void Book::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    // 获取当前选中的行
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow != -1) {
        // 假设要获取第 1 列（索引为 0）的数据
        int targetColumn = 1;
        QTableWidgetItem *item = ui->tableWidget->item(currentRow, targetColumn);
        if (item) {
            QString data = item->text();
            qDebug() << "Data at row " << currentRow << ", column " << targetColumn << ": " << data;


            QString strDirName = index.data().toString();
            qDebug() << "Data at row " << currentRow << ", column " << targetColumn << ": " << strDirName;
            QString strCurPath = TcpClient::getInstance().strCurPath();
            // 缓存数据
            m_enterPath = QString("%1/%2").arg(strCurPath).arg(strDirName);
            PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
            pdu->uiMsgType = ENUM_MSG_TYPE_ENTER_DIR_REQUEST;
            strncpy(pdu->caData, strDirName.toUtf8().toStdString().c_str(), strDirName.toUtf8().size());
            memcpy((char*)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
            TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        } else {
            qDebug() << "No item at row " << currentRow << ", column " << targetColumn;
        }
    } else {
        qDebug() << "No row is selected.";
    }
}

QString Book::enterPath() const
{
    return m_enterPath;
}


void Book::on_m_returnPB_clicked()
{
    // 当前目录
    QString strCurPath = TcpClient::getInstance().strCurPath();
    // 用户根目录
    QString strRootPath = "./" + TcpClient::getInstance().strLoginName();
    // 如果当前目录就是用户根目录，代表没有上级目录了
    if(strCurPath == strRootPath)
    {
        QMessageBox::warning(this, "返回", "返回上一级失败：当前已经在用户根目录了");
        return ;
    }
    // ./alice/aa/bb -> ./alice/aa
    int idx = strCurPath.lastIndexOf('/');
    strCurPath.remove(idx, strCurPath.size()-idx);
    // 更新当前所在目录位置
    TcpClient::getInstance().setStrCurPath(strCurPath);
    // 刷新目录文件为当前目录位置的文件
    on_m_pFlushFilePB_clicked();
}


void Book::on_m_pUploadPB_clicked()
{
    // 当前目录
    QString strCurPath = TcpClient::getInstance().strCurPath();
    m_strUploadFilePath = QFileDialog::getOpenFileName();
    if(m_strUploadFilePath.isEmpty())
    {
        QMessageBox::warning(this, "上传文件", "上传文件名称不能为空");
        return ;
    }
    int idx = m_strUploadFilePath.lastIndexOf('/');
    QString fileName = m_strUploadFilePath.right(m_strUploadFilePath.size() - idx - 1);
    QFile file(m_strUploadFilePath);
    qint64 fileSize = file.size();//文件的大小
    PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
    pdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST;
    memcpy((char*)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.toUtf8().size());
    sprintf(pdu->caData, "%s %lld", fileName.toUtf8().toStdString().c_str(), fileSize);
    qDebug() << (char*)pdu->caMsg;
    TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
    // 1s后上传文件，防止粘包
    m_pTimer->start(1000);
}

void Book::uploadFileData()
{
    m_pTimer->stop();
    QFile file(m_strUploadFilePath);
    // 如果打开文件失败
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "上传文件", "打开文件失败");
        return;
    }
    // 有人做过实验，4096传输数据时效率最高
    char *pBuffer = new char[4096];
    qint64 ret = 0;
    while(true)
    {
        // 读取文件中的数据
        ret = file.read(pBuffer, 4096);
        // 如果读取到了文件中的数据，则发送给服务器
        if(ret > 0 && ret <= 4096)
        {
            TcpClient::getInstance().tcpSocket().write(pBuffer, ret);
        }
        // 如果文件读取结束了，就结束循环
        else if(ret == 0)
        {
            break;
        }
        // 如果ret < 0 或者 ret > 4096,则代表读取错误了
        else
        {
            QMessageBox::warning(this, "上传文件", "上传文件失败：读取文件内容失败");
            break;
        }
    }
    delete []pBuffer;
    pBuffer = NULL;
}



void Book::on_m_pDownloadFilePB_clicked()
{
    // 获取当前选中的行
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow != -1) {
        // 假设要获取第 1 列（索引为 0）的数据
        int targetColumn = 1;
        QTableWidgetItem *item = ui->tableWidget->item(currentRow, targetColumn);
        if (item) {
            QString strDownloadName = item->text();
            QString strCurPath = TcpClient::getInstance().strCurPath();

            QString strSaveFilePath = QFileDialog::getSaveFileName();
            if(strSaveFilePath.isEmpty())
            {
                QMessageBox::warning(this, "下载文件", "请指定要保存的位置");
                m_strSaveFilePath.clear();
                return ;
            }
            m_strSaveFilePath = strSaveFilePath;
            PDU *pdu = mkPDU(strCurPath.toUtf8().size() + 1);
            pdu->uiMsgType = ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST;
            strcpy(pdu->caData, strDownloadName.toUtf8().toStdString().c_str());
            memcpy((char*)pdu->caMsg, strCurPath.toUtf8().toStdString().c_str(), strCurPath.size());
            TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
            free(pdu);
            pdu = NULL;


        } else {
            qDebug() << "No item at row " << currentRow << ", column " << targetColumn;
        }
    } else {
        qDebug() << "No row is selected.";
    }
}

void Book::onShareButtonClicked()
{
    // 获取当前选中的行
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow != -1) {
        // 假设要获取第 1 列（索引为 0）的数据
        int targetColumn = 1;
        QTableWidgetItem *item = ui->tableWidget->item(currentRow, targetColumn);
        if (item) {
            QString strShareName = item->text();
            // 创建选择好友的对话框
            QDialog dialog(this);
            dialog.setWindowTitle("选择好友分享");
            // 设置对话框的固定大小
            dialog.setFixedSize(500, 400); // 增大对话框的尺寸


            // 创建全选复选框
            QCheckBox *selectAllCheckBox = new QCheckBox("全选", &dialog);


            // 创建好友列表
            QListWidget *friendListWidget = new QListWidget(&dialog);
            friendListWidget->setSpacing(5); // 设置列表项之间的间距
            QStringList friendList;
            QListWidget *listWidget =OpeWidget::getInstance().pFriend()->getFriendListWidget();
            if (!listWidget) {
                return ;
            }


            for (int i = 0; i < listWidget->count(); ++i) {
                QListWidgetItem *item = listWidget->item(i);
                if (item) {
                    // 获取 QListWidgetItem 的文本并添加到 QStringList 中
                    friendList.append(item->text());
                }
            }
            for (const QString &friendName : friendList) {
                QListWidgetItem *item = new QListWidgetItem();
                QCheckBox *checkBox = new QCheckBox(friendName);
                friendListWidget->addItem(item);
                friendListWidget->setItemWidget(item, checkBox);
            }


            // 连接全选复选框的信号和槽
            connect(selectAllCheckBox, &QCheckBox::stateChanged, [=](int state) {
                for (int i = 0; i < friendListWidget->count(); ++i) {
                    QListWidgetItem *item = friendListWidget->item(i);
                    QCheckBox *checkBox = qobject_cast<QCheckBox*>(friendListWidget->itemWidget(item));
                    if (checkBox) {
                        checkBox->setChecked(state == Qt::Checked);
                    }
                }
            });


            // 创建分享和取消按钮
            QPushButton *shareFileButton = new QPushButton("分享文件", &dialog);
            QPushButton *cancelButton = new QPushButton("取消分享", &dialog);


            // 连接分享和取消按钮的信号和槽
            connect(shareFileButton, &QPushButton::clicked, [&]() {
                QStringList selectedFriends;
                for (int i = 0; i < friendListWidget->count(); ++i) {
                    QListWidgetItem *item = friendListWidget->item(i);
                    QCheckBox *checkBox = qobject_cast<QCheckBox*>(friendListWidget->itemWidget(item));
                    if (checkBox && checkBox->isChecked()) {
                        selectedFriends.append(checkBox->text());
                    }
                }
                qDebug() << "选择的好友:" << selectedFriends;
                QString strName = TcpClient::getInstance().strLoginName();
                QString strCurPath = TcpClient::getInstance().strCurPath();
                QString strPath = strCurPath + "/" + strShareName;
                int num = selectedFriends.size();//选中的好友数

                // msg存放好友信息和文件路径
                PDU *pdu = mkPDU(32 * num + strPath.toUtf8().size() + 1);
                // data存放好友数量和当前用户名称
                pdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_REQUEST;
                sprintf(pdu->caData, "%s %d", strName.toUtf8().toStdString().c_str(), num);
                for(int i = 0; i < num; i++)
                {
                    memcpy((char*)pdu->caMsg + i*32
                           , selectedFriends.at(i).toUtf8().toStdString().c_str()
                           , selectedFriends.at(i).toUtf8().size());
                }
                memcpy((char*)pdu->caMsg + num*32, strPath.toUtf8().toStdString().c_str(), strPath.toUtf8().size());
                TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
                free(pdu);
                pdu = NULL;
                dialog.accept();
            });


            connect(cancelButton, &QPushButton::clicked, [&]() {
                dialog.reject();
            });
            // 布局管理
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addWidget(selectAllCheckBox);
            mainLayout->addWidget(friendListWidget);


            QHBoxLayout *buttonLayout = new QHBoxLayout;
            buttonLayout->addWidget(shareFileButton);
            buttonLayout->addWidget(cancelButton);


            mainLayout->addLayout(buttonLayout);
            dialog.setLayout(mainLayout);


            // 显示对话框
            dialog.exec();




        } else {
            qDebug() << "No item at row " << currentRow << ", column " << targetColumn;
        }
    } else {
        qDebug() << "No row is selected.";
    }

}

bool Book::pDownload()
{
    return m_pDownload;
}

void Book::setPDownload(bool newPDownload)
{
    m_pDownload = newPDownload;
}

