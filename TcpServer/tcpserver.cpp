#include "tcpserver.h"
#include "ui_tcpserver.h"


#include <QFile>
#include <QMessageBox>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    loadConfig();
    MyTcpServer::getInstance().listen(QHostAddress(m_strIP),m_usPort);
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::loadConfig()
{
    QFile file(":/server.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray badata=file.readAll();
        QString strData = badata.toStdString().c_str();
        file.close();
        strData.replace("\r\n"," ");
        QStringList strList = strData.split(" ");
        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();
        qDebug()<< m_strIP;
    }
    else
    {
        QMessageBox::critical(this,"open config","open config failed");
    }
}
