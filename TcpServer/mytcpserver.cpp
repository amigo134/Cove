#include "mytcpserver.h"
#include <QThread>
#include <QMetaObject>
#include <QObject>
MyTcpServer::MyTcpServer() {}

MyTcpServer &MyTcpServer::getInstance()
{
    static MyTcpServer instance;
    return instance;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "new client connected";
    MyTcpSocket *pTcpSocket = new MyTcpSocket;
    pTcpSocket ->setSocketDescriptor(socketDescriptor);
    m_tcpSocketList.append(pTcpSocket);
    QThread * thread = new QThread();
    connect(pTcpSocket,SIGNAL(disconnected()),thread,SLOT(quit()));
    connect(pTcpSocket,SIGNAL(offline(MyTcpSocket*)),this,SLOT(deleteSocket(MyTcpSocket*)));
    pTcpSocket->moveToThread(thread);
    thread->start();
    emit newConnection();

}

void MyTcpServer::resend(const char *pername, PDU *pdu)
{
    if(NULL == pername || NULL ==pdu)
    {
        return;
    }
    QString strName=pername;
    for(int i=0;i<m_tcpSocketList.size();i++)
    {
        if(strName == m_tcpSocketList.at(i)->strName())
        {
            // m_tcpSocketList.at(i)->write((char*)pdu,pdu->uiPDULen);
            QMetaObject::invokeMethod(m_tcpSocketList.at(i), [pdu, socket = m_tcpSocketList.at(i)]() {
                if (pdu) {
                    socket->write((char*)pdu, pdu->uiPDULen);
                }
            }, Qt::QueuedConnection);
            break;
        }
    }
}

void MyTcpServer::deleteSocket(MyTcpSocket *mysocket)
{
    QList<MyTcpSocket *>::iterator iter=m_tcpSocketList.begin();
    for(;iter !=m_tcpSocketList.end();iter++)
    {
        if(mysocket == *iter)
        {
            (*iter)->deleteLater();
            *iter=NULL;
            m_tcpSocketList.erase(iter);
            break;
        }
    }
    for(int i=0;i<m_tcpSocketList.size();i++)
    {
        qDebug()<<m_tcpSocketList.at(i)->strName();
    }
}
