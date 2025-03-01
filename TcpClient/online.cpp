#include "online.h"
#include "tcpclient.h"
#include "ui_online.h"
#include <QDebug>
Online::Online(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Online)
{
    ui->setupUi(this);
}

Online::~Online()
{
    delete ui;
}

void Online::showUsr(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    ui->online_lw->clear();
    int uiSize = pdu->uiMsgLen/32;
    char caTmp[32];
    for(int i=0;i<uiSize;i++)
    {
        memcpy(caTmp,(char *)(pdu->caMsg)+i*32,32);
        ui->online_lw->addItem(caTmp);

    }
}

void Online::on_addFriend_pb_clicked()
{
    QListWidgetItem *pItem=ui->online_lw->currentItem();
    if(NULL == pItem) return;
    qDebug() << pItem->text();
    QString strPerUsrName = pItem->text();
    QString strLoginName = TcpClient::getInstance().strLoginName();
    PDU *pdu =mkPDU(0);
    pdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_REQUEST;
    strncpy(pdu->caData,strPerUsrName.toStdString().c_str(),strPerUsrName.size());
    strncpy(pdu->caData+32,strLoginName.toStdString().c_str(),strLoginName.size());
    TcpClient::getInstance().tcpSocket().write((char*)pdu,pdu->uiPDULen);
    free(pdu);
    pdu=NULL;
}

