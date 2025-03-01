#include "chatmessage.h"
#include "friend.h"
#include "ui_friend.h"
#include <QDebug>
#include <QDateTime>
#include <online.h>
#include "protocol.h"
#include "tcpclient.h"
Friend::Friend(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Friend)
{
     strChatName="";
    ui->setupUi(this);
    ui->tabWidget->tabBarClicked(0);
    ui->privatechatBtn->setDisabled(true);
    m_pOnline = new Online(ui->tab_5);
    strLoginName=TcpClient::getInstance().strLoginName();
    if(strChatName.isEmpty())
    {
        qDebug()<<"为空";
    }



    // 创建 widget_side
    widget_side = new QWidget(ui->tab_6);
    widget_side->setFixedSize(200,ui->tab_6 ->height()); // 设置大小
    // 创建垂直布局用于管理 widget_side 内的控件
    QVBoxLayout *layout = new QVBoxLayout(widget_side);
    // 创建 friendListWidget 并将其添加到 widget_side 中
    friendListWidget = new QListWidget(widget_side);
    friendListWidget->setGeometry(0, 0, widget_side->width(), widget_side->height() - 20);
    friendListWidget->setStyleSheet("background-color: #F0F0F0;");
    widget_side->setStyleSheet("background-color: #F0F0F0;");
    // 可以添加一些示例数据到列表中
    friendListWidget->addItem("Friend 1");
    friendListWidget->addItem("Friend 2");
    friendListWidget->addItem("Friend 3");
    layout->addWidget(friendListWidget);
    // 创建删除好友按钮
    deleteFriendButton = new QPushButton("删除好友", widget_side);
    layout->addWidget(deleteFriendButton);
    connect(deleteFriendButton, &QPushButton::clicked, this, &Friend::onDeleteFriendClicked);

    // 创建刷新列表按钮
    refreshListButton = new QPushButton("刷新列表", widget_side);
    layout->addWidget(refreshListButton);
    connect(refreshListButton, &QPushButton::clicked, this, &Friend::onRefreshListClicked);

    // 创建 pushButton
    pushButton = new QPushButton(">>", ui->tab_6);
    pushButton->setFixedSize(30, 50);
    // 左侧停靠
    widget_side->move(-widget_side->width(), 0);
    pushButton->move(-1, widget_side->height() / 2);

    // 创建侧边栏动画
    m_propertyAnimation = new QPropertyAnimation(widget_side,"geometry");
    m_propertyAnimation->setEasingCurve(QEasingCurve::InOutSine);
    m_propertyAnimation->setDuration(800);
    m_propertyAnimation2 = new QPropertyAnimation(pushButton,"geometry");
    m_propertyAnimation2->setEasingCurve(QEasingCurve::InOutSine);
    m_propertyAnimation2->setDuration(800);
    // 连接按钮的点击信号到槽函数
    connect(pushButton, &QPushButton::clicked, this, &Friend::on_pushButton_clicked);
    connect(friendListWidget, &QListWidget::itemSelectionChanged, this, &Friend::onItemSelectionChanged);


}


Friend::~Friend()
{
    delete ui;
}

void Friend::showAllOnlineUsr(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    m_pOnline->showUsr(pdu);

}

void Friend::on_sendmsg_clicked()
{
    QString msg = ui->plainTextEdit->toPlainText().trimmed();
    if(msg.size() == 0)
    {
        qDebug() << "empty";
        return;
    }
    qDebug()<<msg;
    ui->plainTextEdit->setPlainText("");
    QString time = QString::number(QDateTime::currentDateTimeUtc().toTime_t());
    ChatMessage *message = new ChatMessage(ui->listWidget);
    QListWidgetItem *item = new QListWidgetItem();
    dealMessageTime(time);
    dealMessage(message, item, msg, time,strLoginName,ChatMessage::User_Me);
    emit PushText(0, msg);
    PDU *pdu = mkPDU(msg.toUtf8().size() + 1);//+1是因为转为char后需要多一个 \0结束符
    if(!strChatName.isEmpty())
    {
    pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
    // 先复制好友的名称
    memcpy(pdu->caData, strChatName.toStdString().c_str(), strChatName.size());
    memcpy(pdu->caData + 32, strLoginName.toStdString().c_str(), strLoginName.size());
    strcpy((char*)pdu->caMsg, msg.toUtf8().toStdString().c_str());
    TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    }
    else
    {
        pdu->uiMsgType = ENUM_MSG_TYPE_GROUP_CHAT_REQUEST;
        memcpy(pdu->caData, strLoginName.toStdString().c_str(), strLoginName.size());
        strcpy((char*)pdu->caMsg, msg.toUtf8().toStdString().c_str());
        TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    }
    free(pdu);
    pdu=NULL;

    //ui->sendmsg->setDisabled(true);
}

void Friend::dealMessage(ChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QString ip, ChatMessage::User_Type type)
{
    ui->listWidget->addItem(item);
    messageW->setFixedWidth(ui->listWidget->width());
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, ip, type);
    ui->listWidget->setItemWidget(item, messageW);
}

void Friend::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        ChatMessage* messageW = (ChatMessage *)ui->listWidget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
        //        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        ChatMessage* messageTime = new ChatMessage(ui->listWidget);
        QListWidgetItem* itemTime = new QListWidgetItem();
        ui->listWidget->addItem(itemTime);
        QSize size = QSize(ui->listWidget->width() , 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}

QListWidget *Friend::getFriendListWidget() const
{
    return friendListWidget;
}



void Friend::on_tabWidget_tabBarClicked(int index)
{
    if(index==0)
    {

        PDU *pdu=mkPDU(0);
        pdu->uiMsgType=ENUM_MSG_TYPE_ALL_ONLINE_REQUEST;
        TcpClient::getInstance().tcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;

    }
    if(index==1)
    {
        onRefreshListClicked();
    }
}


void Friend::on_searchBtn_clicked()
{
     m_strSearchName=ui->usrname->text();
    if(!m_strSearchName.isEmpty())
    {
        qDebug()<<m_strSearchName;
        PDU *pdu=mkPDU(0);
        memcpy(pdu->caData,m_strSearchName.toStdString().c_str(),m_strSearchName.size());
        pdu->uiMsgType=ENUM_MSG_TYPE_SEARCH_USR_REQUEST;
        TcpClient::getInstance().tcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
}

void Friend::on_pushButton_clicked()
{
    onRefreshListClicked();
    //显示侧边栏
    if(!m_bSideflag)
    {
        m_propertyAnimation->setStartValue(QRect(-this->rect().width(),0,widget_side->width(),widget_side->height()));
        m_propertyAnimation->setEndValue(QRect(0,0,widget_side->width(),widget_side->height()));
        m_propertyAnimation->start();
        m_propertyAnimation2->setStartValue(QRect(-1,widget_side->height()/2-pushButton->height()/2,pushButton->width(),pushButton->height()));
        m_propertyAnimation2->setEndValue(QRect(widget_side->width()-2,widget_side->height()/2-pushButton->height()/2,pushButton->width(),pushButton->height()));
        m_propertyAnimation2->start();
        pushButton->setText("<<");
        m_bSideflag = !m_bSideflag;
    }
    else
    {
        m_propertyAnimation->setStartValue(QRect(0,0,widget_side->width(),widget_side->height()));
        m_propertyAnimation->setEndValue(QRect(-this->rect().width(),0,widget_side->width(),widget_side->height()));
        m_propertyAnimation->start();
        m_propertyAnimation2->setStartValue(QRect(widget_side->width()-2,widget_side->height()/2-pushButton->height()/2,pushButton->width(),pushButton->height()));
        m_propertyAnimation2->setEndValue(QRect(-1,widget_side->height()/2-pushButton->height()/2,pushButton->width(),pushButton->height()));
        m_propertyAnimation2->start();
        pushButton->setText(">>");
        m_bSideflag = !m_bSideflag;
    }


}

void Friend::onDeleteFriendClicked()
{
    if(friendListWidget->currentItem())
    {
    QString strName=friendListWidget->currentItem()->text();
    qDebug()<<strName;

    PDU *pdu = mkPDU(0);
    pdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST;
    memcpy(pdu->caData, strName.toStdString().c_str(), strName.size());
    memcpy(pdu->caData + 32, TcpClient::getInstance().strLoginName().toStdString().c_str(), TcpClient::getInstance().strLoginName().size());
    TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
    }
}

void Friend::onRefreshListClicked()
{

    QString loginName = TcpClient::getInstance().strLoginName();
    PDU *pdu = mkPDU(0);
    pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST;
    strcpy(pdu->caData, loginName.toStdString().c_str());
    TcpClient::getInstance().tcpSocket().write((char*)pdu, pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
}

void Friend::onItemSelectionChanged()
{
    // 检查是否有选中项
    if (!friendListWidget->selectedItems().isEmpty()) {
        ui->privatechatBtn->setEnabled(true);

    } else {
        ui->privatechatBtn->setEnabled(false);
    }
}



void Friend::updateFriendList(PDU *pdu)
{
    if(NULL == pdu)
    {
        return ;
    }
    friendListWidget->clear();
    int uiSize = pdu->uiMsgLen / 32;
    for(int i = 0; i < uiSize; i++)
    {
        char caName[32] = {'\0'};
        // 注意，这里的 pdu->caMsg 也应该是 char * 才对，因为他复制的是 char *的内容
        memcpy(caName, (char*)(pdu->caMsg) + i * 32, 32);
        qDebug()<<caName;
        friendListWidget->addItem(caName);
    }


}

void Friend::updateMsg(const PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    char perName[32] = {'\0'};

    strncpy(perName, pdu->caData+32, 32);
    strChatName=perName;
    QString time = QString::number(QDateTime::currentDateTimeUtc().toTime_t());
    ChatMessage *message = new ChatMessage(ui->listWidget);
    QListWidgetItem *item = new QListWidgetItem();
    dealMessageTime(time);
    dealMessage(message, item, (char *)(pdu->caMsg), time,perName,ChatMessage::User_She);

}

void Friend::updateGroupMsg(const PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    char perName[32] = {'\0'};

    strncpy(perName, pdu->caData, 32);
    QString time = QString::number(QDateTime::currentDateTimeUtc().toTime_t());
    ChatMessage *message = new ChatMessage(ui->listWidget);
    QListWidgetItem *item = new QListWidgetItem();
    dealMessageTime(time);
    dealMessage(message, item, (char *)(pdu->caMsg), time,perName,ChatMessage::User_She);
}


void Friend::on_privatechatBtn_clicked()
{
    strChatName=friendListWidget->currentItem()->text();
    qDebug()<<strChatName;

    QLabel* messageTime = new QLabel(ui->listWidget);
    QListWidgetItem* itemTime = new QListWidgetItem();
    ui->listWidget->addItem(itemTime);
    QSize size = QSize(ui->listWidget->width(), 40);
    messageTime->resize(size);
    itemTime->setSizeHint(size);
    QString startChatMsg = QString("与 %1 开始聊天了").arg(strChatName);
    messageTime->setText(startChatMsg);
    // 设置文本居中对齐
    messageTime->setAlignment(Qt::AlignCenter);
    ui->listWidget->setItemWidget(itemTime, messageTime);



    ChatMessage* messageTime1 = new ChatMessage(ui->listWidget);
    QListWidgetItem* itemTime1 = new QListWidgetItem();
    ui->listWidget->addItem(itemTime1);
    QSize size1 = QSize(ui->listWidget->width() , 40);
    messageTime1->resize(size1);
    itemTime1->setSizeHint(size1);
    QString time = QString::number(QDateTime::currentDateTimeUtc().toTime_t());
    messageTime1->setText(time,time, size);
    ui->listWidget->setItemWidget(itemTime1, messageTime1);

}

void Friend::on_groupchatBtn_clicked()
{
    strChatName="";
}

