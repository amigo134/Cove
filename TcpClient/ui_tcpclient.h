/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *name_le;
    QLineEdit *pwd_le;
    QPushButton *login_pb;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *regist_pb;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *cancel_pb;
    QPushButton *close_pb;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(554, 501);
        widget = new QWidget(TcpClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 551, 501));
        widget->setStyleSheet(QString::fromUtf8("QPushButton#login_pb{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"	color:rgba(255, 255, 255, 210);\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton#login_pb:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#login_pb:pressed{\n"
"	padding-left:5px;\n"
"	padding-top:5px;\n"
"	background-color:rgba(150, 123, 111, 255);\n"
"}\n"
"\n"
"QPushButton#regist_pb, #pushButton_3, #pushButton_4, #pushButton_5{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color:rgba(85, 98, 112, 255);\n"
"}\n"
"\n"
"QPushButton#regist_pb:hover, #pushButton_3:hover, #pushButton_4:hover, #pushButton_5:hover{\n"
"	color: rgba(131, 96, 53, 255);\n"
"}\n"
"\n"
"QPushButton#regist_pb:pressed, #pushButton_3:pressed, #pushButton_4:pressed, #pushButton_5:pressed{\n"
"	padding-left:5px;\n"
"	padding-top:5px;"
                        "\n"
"	color:rgba(91, 88, 53, 255);\n"
"}\n"
"\n"
""));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 280, 430));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/background.jpg);\n"
"border-top-left-radius: 50px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 280, 430));
        label_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 80);\n"
"border-top-left-radius: 50px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 30, 240, 430));
        label_3->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 255);\n"
"border-bottom-right-radius: 50px;\n"
"border: 2px solid gray;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 90, 100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Social Media Circled"));
        font.setPointSize(20);
        font.setBold(false);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:rgba(0, 0, 0, 200);"));
        name_le = new QLineEdit(widget);
        name_le->setObjectName(QString::fromUtf8("name_le"));
        name_le->setGeometry(QRect(275, 150, 231, 40));
        QFont font1;
        font1.setPointSize(10);
        name_le->setFont(font1);
        name_le->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46, 82, 101, 200);\n"
"color:rgba(0, 0, 0, 240);\n"
"padding-bottom:7px;"));
        pwd_le = new QLineEdit(widget);
        pwd_le->setObjectName(QString::fromUtf8("pwd_le"));
        pwd_le->setGeometry(QRect(274, 215, 231, 40));
        pwd_le->setFont(font1);
        pwd_le->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46, 82, 101, 200);\n"
"color:rgba(0, 0, 0, 240);\n"
"padding-bottom:7px;"));
        pwd_le->setEchoMode(QLineEdit::Password);
        login_pb = new QPushButton(widget);
        login_pb->setObjectName(QString::fromUtf8("login_pb"));
        login_pb->setGeometry(QRect(290, 270, 190, 40));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        login_pb->setFont(font2);
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(318, 383, 141, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        regist_pb = new QPushButton(horizontalLayoutWidget);
        regist_pb->setObjectName(QString::fromUtf8("regist_pb"));
        regist_pb->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Social Media Circled"));
        font3.setPointSize(15);
        regist_pb->setFont(font3);

        horizontalLayout->addWidget(regist_pb);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(30, 30));
        pushButton_3->setFont(font3);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(30, 30));
        pushButton_4->setFont(font3);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(30, 30));
        pushButton_5->setFont(font3);

        horizontalLayout->addWidget(pushButton_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 80, 230, 130));
        label_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 75);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 120, 180, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font4.setPointSize(22);
        font4.setBold(false);
        label_7->setFont(font4);
        label_7->setStyleSheet(QString::fromUtf8("color:rgba(255, 255, 255, 200);"));
        cancel_pb = new QPushButton(widget);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setGeometry(QRect(290, 320, 190, 40));
        cancel_pb->setFont(font2);
        close_pb = new QPushButton(widget);
        close_pb->setObjectName(QString::fromUtf8("close_pb"));
        close_pb->setGeometry(QRect(480, 30, 30, 29));
        close_pb->setMaximumSize(QSize(30, 30));
        close_pb->setFont(font3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_pb->setIcon(icon);

        retranslateUi(TcpClient);
        QObject::connect(close_pb, SIGNAL(clicked()), TcpClient, SLOT(close()));

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("TcpClient", "\347\231\273\345\275\225", nullptr));
        name_le->setPlaceholderText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215", nullptr));
        pwd_le->setPlaceholderText(QCoreApplication::translate("TcpClient", "\345\257\206\347\240\201", nullptr));
        login_pb->setText(QCoreApplication::translate("TcpClient", "\347\231\273\345\275\225", nullptr));
        regist_pb->setText(QCoreApplication::translate("TcpClient", "\347\202\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TcpClient", "\345\207\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TcpClient", "\346\263\250", nullptr));
        pushButton_5->setText(QCoreApplication::translate("TcpClient", "\346\265\213", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("TcpClient", "Cove", nullptr));
        cancel_pb->setText(QCoreApplication::translate("TcpClient", "\351\207\215\347\275\256", nullptr));
        close_pb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
