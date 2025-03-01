#ifndef FRIEND_H
#define FRIEND_H

#include "chatmessage.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QListWidgetItem>
#include <QWidget>
#include "protocol.h"
#include <QPushButton>
class Online;
namespace Ui {
class Friend;
}

class Friend : public QWidget
{
    Q_OBJECT

public:
    explicit Friend(QWidget *parent = nullptr);
    ~Friend();
    void showAllOnlineUsr(PDU *pdu);
    // 刷新好友列表
    void updateFriendList(PDU *pdu);
    void updateMsg(const PDU *pdu);
    void updateGroupMsg(const PDU *pdu);
    QString m_strSearchName;
    void onRefreshListClicked();
    QListWidget *getFriendListWidget() const;

private slots:
    void on_sendmsg_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_searchBtn_clicked();

    void on_pushButton_clicked();

    void onDeleteFriendClicked();

    void onItemSelectionChanged();

    void on_privatechatBtn_clicked();

    void on_groupchatBtn_clicked();

private:
    Ui::Friend *ui;

    Online* m_pOnline;



    void dealMessage(ChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QString ip ,ChatMessage::User_Type type); //用户发送文本
    void dealMessageTime(QString curMsgTime); //处理时间
    QString strChatName;
    QString strLoginName;
    QWidget *widget_side;
    QPushButton *pushButton;
    QPropertyAnimation *m_propertyAnimation;
    QPropertyAnimation *m_propertyAnimation2;
    bool m_bSideflag = false;
    QListWidget *friendListWidget; // 新增的成员变量
    QPushButton *deleteFriendButton;
    QPushButton *refreshListButton;

signals:

    void PushText(int, QString = "");
};

#endif // FRIEND_H
