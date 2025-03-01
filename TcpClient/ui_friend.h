/********************************************************************************
** Form generated from reading UI file 'friend.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIEND_H
#define UI_FRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mytextedit.h"

QT_BEGIN_NAMESPACE

class Ui_Friend
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *joinmeetBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *joinmeet_label;
    QLineEdit *usrname;
    QPushButton *searchBtn;
    QGroupBox *createmeetBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *privatechatBtn;
    QGroupBox *groupchat;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *groupchatBtn;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *ip;
    QLabel *label_2;
    QLineEdit *port;
    QPushButton *connServer;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget_2;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_6;
    QListWidget *listWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    MyTextEdit *plainTextEdit;
    QPushButton *sendmsg;

    void setupUi(QWidget *Friend)
    {
        if (Friend->objectName().isEmpty())
            Friend->setObjectName(QString::fromUtf8("Friend"));
        Friend->resize(675, 675);
        verticalLayout_4 = new QVBoxLayout(Friend);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget = new QWidget(Friend);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 6, 5, 3);
        joinmeetBox = new QGroupBox(widget);
        joinmeetBox->setObjectName(QString::fromUtf8("joinmeetBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(joinmeetBox->sizePolicy().hasHeightForWidth());
        joinmeetBox->setSizePolicy(sizePolicy);
        joinmeetBox->setCursor(QCursor(Qt::ArrowCursor));
        horizontalLayout_2 = new QHBoxLayout(joinmeetBox);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        joinmeet_label = new QLabel(joinmeetBox);
        joinmeet_label->setObjectName(QString::fromUtf8("joinmeet_label"));

        horizontalLayout_2->addWidget(joinmeet_label);

        usrname = new QLineEdit(joinmeetBox);
        usrname->setObjectName(QString::fromUtf8("usrname"));

        horizontalLayout_2->addWidget(usrname);

        searchBtn = new QPushButton(joinmeetBox);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_2->addWidget(searchBtn);


        horizontalLayout->addWidget(joinmeetBox);

        createmeetBox = new QGroupBox(widget);
        createmeetBox->setObjectName(QString::fromUtf8("createmeetBox"));
        sizePolicy.setHeightForWidth(createmeetBox->sizePolicy().hasHeightForWidth());
        createmeetBox->setSizePolicy(sizePolicy);
        createmeetBox->setCursor(QCursor(Qt::ArrowCursor));
        horizontalLayout_3 = new QHBoxLayout(createmeetBox);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        privatechatBtn = new QPushButton(createmeetBox);
        privatechatBtn->setObjectName(QString::fromUtf8("privatechatBtn"));
        privatechatBtn->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_3->addWidget(privatechatBtn);


        horizontalLayout->addWidget(createmeetBox);

        groupchat = new QGroupBox(widget);
        groupchat->setObjectName(QString::fromUtf8("groupchat"));
        sizePolicy.setHeightForWidth(groupchat->sizePolicy().hasHeightForWidth());
        groupchat->setSizePolicy(sizePolicy);
        groupchat->setCursor(QCursor(Qt::ArrowCursor));
        horizontalLayout_4 = new QHBoxLayout(groupchat);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(3, 3, 3, 3);
        groupchatBtn = new QPushButton(groupchat);
        groupchatBtn->setObjectName(QString::fromUtf8("groupchatBtn"));
        groupchatBtn->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_4->addWidget(groupchatBtn);


        horizontalLayout->addWidget(groupchat);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_4);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        ip = new QLineEdit(groupBox_4);
        ip->setObjectName(QString::fromUtf8("ip"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ip->sizePolicy().hasHeightForWidth());
        ip->setSizePolicy(sizePolicy1);
        ip->setMinimumSize(QSize(0, 0));

        horizontalLayout_7->addWidget(ip);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        port = new QLineEdit(groupBox_4);
        port->setObjectName(QString::fromUtf8("port"));
        sizePolicy1.setHeightForWidth(port->sizePolicy().hasHeightForWidth());
        port->setSizePolicy(sizePolicy1);
        port->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_7->addWidget(port);

        connServer = new QPushButton(groupBox_4);
        connServer->setObjectName(QString::fromUtf8("connServer"));

        horizontalLayout_7->addWidget(connServer);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(400, 0));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        tabWidget->setPalette(palette);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_5 = new QVBoxLayout(tab_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab_5);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 641, 572));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget_2 = new QListWidget(scrollAreaWidgetContents);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout_3->addWidget(listWidget_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        sizePolicy3.setHeightForWidth(tab_6->sizePolicy().hasHeightForWidth());
        tab_6->setSizePolicy(sizePolicy3);
        verticalLayout_6 = new QVBoxLayout(tab_6);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(tab_6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget->setAutoScrollMargin(0);
        listWidget->setItemAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_6->addWidget(listWidget);

        widget_2 = new QWidget(tab_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);
        widget_2->setMaximumSize(QSize(16777215, 100));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new MyTextEdit(widget_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMaximumSize(QSize(16777215, 80));
        QPalette palette1;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        plainTextEdit->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        plainTextEdit->setFont(font);
        plainTextEdit->setPlaceholderText(QString::fromUtf8("\345\274\200\345\247\213\350\201\212\345\244\251\345\220\247~"));

        verticalLayout_7->addWidget(plainTextEdit);

        sendmsg = new QPushButton(widget_2);
        sendmsg->setObjectName(QString::fromUtf8("sendmsg"));

        verticalLayout_7->addWidget(sendmsg);


        verticalLayout_6->addWidget(widget_2);

        tabWidget->addTab(tab_6, QString());

        horizontalLayout_5->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_4->addWidget(widget);


        retranslateUi(Friend);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Friend);
    } // setupUi

    void retranslateUi(QWidget *Friend)
    {
        Friend->setWindowTitle(QCoreApplication::translate("Friend", "Form", nullptr));
        joinmeetBox->setTitle(QCoreApplication::translate("Friend", "\346\237\245\346\211\276\345\245\275\345\217\213", nullptr));
        joinmeet_label->setText(QCoreApplication::translate("Friend", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        searchBtn->setText(QCoreApplication::translate("Friend", "\346\220\234\347\264\242", nullptr));
        createmeetBox->setTitle(QCoreApplication::translate("Friend", "\345\274\200\345\247\213\347\247\201\350\201\212", nullptr));
        privatechatBtn->setText(QCoreApplication::translate("Friend", "\347\247\201\350\201\212", nullptr));
        groupchat->setTitle(QCoreApplication::translate("Friend", "\345\274\200\345\247\213\347\276\244\350\201\212", nullptr));
        groupchatBtn->setText(QCoreApplication::translate("Friend", "\347\276\244\350\201\212", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Friend", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("Friend", "IP:", nullptr));
        ip->setText(QCoreApplication::translate("Friend", "192.168.1.126", nullptr));
        label_2->setText(QCoreApplication::translate("Friend", "Port:", nullptr));
        port->setText(QCoreApplication::translate("Friend", "8888", nullptr));
        connServer->setText(QCoreApplication::translate("Friend", "\350\277\236\346\216\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Friend", "\345\234\250\347\272\277\344\272\272\346\225\260", nullptr));
        sendmsg->setText(QCoreApplication::translate("Friend", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Friend", "\350\201\212\345\244\251\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friend: public Ui_Friend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIEND_H
