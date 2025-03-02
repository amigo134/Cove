/********************************************************************************
** Form generated from reading UI file 'online.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_H
#define UI_ONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Online
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QListWidget *online_lw;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addFriend_pb;

    void setupUi(QWidget *Online)
    {
        if (Online->objectName().isEmpty())
            Online->setObjectName(QString::fromUtf8("Online"));
        Online->resize(366, 585);
        horizontalLayout = new QHBoxLayout(Online);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(Online);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(237, 237, 237);\n"
"}\n"
"QFrame{\n"
"border-top-left-radius:0px;\n"
"border-top-right-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"}"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_8);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(frame_8);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,0%);\n"
"\n"
"}\n"
"QScrollBar::handle:vertical{\n"
"    width:0px;\n"
"    background:rgba(125,125,125,20%);\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::handle:vertical:hover{\n"
"    width:0px;\n"
"    background:rgba(125,125,125,70%);\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::add-line:vertical{\n"
"    height:0px;width:0px;\n"
"\n"
"}\n"
"QScrollBar::sub-line:vertical{\n"
"    height:0px;width:0px;\n"
"\n"
"}\n"
"QScrollBar::add-line:vertical:hover{\n"
"    height:0px;width:0px;\n"
"\n"
"}\n"
"QScrollBar::sub-line:vertical:hover{\n"
"    height:0px;width:0px;\n"
"\n"
"}\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical\n"
"{\n"
"    background:rgba(0,0,0,0%);\n"
"    border-radius:4px;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 342, 561));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        online_lw = new QListWidget(scrollAreaWidgetContents);
        online_lw->setObjectName(QString::fromUtf8("online_lw"));
        online_lw->setMinimumSize(QSize(0, 180));
        online_lw->setMaximumSize(QSize(16777215, 180));
        QFont font;
        online_lw->setFont(font);
        online_lw->setStyleSheet(QString::fromUtf8("QListView {\n"
"\n"
"}\n"
"QListView::item{\n"
"background-color: transparent;\n"
"padding:8px;\n"
"}\n"
"QListView::item:hover {\n"
"	background-color: rgba(216, 216, 216, 70);\n"
"\n"
"}\n"
"QListView::item:selected {\n"
"	/*background-color: transparent;*/\n"
"\n"
"	background-color: rgba(216, 216, 216, 150);\n"
"	color: red;\n"
"}\n"
""));
        online_lw->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        online_lw->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        online_lw->setIconSize(QSize(16, 16));

        verticalLayout_3->addWidget(online_lw);

        frame_11 = new QFrame(scrollAreaWidgetContents);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_11);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        addFriend_pb = new QPushButton(frame_11);
        addFriend_pb->setObjectName(QString::fromUtf8("addFriend_pb"));
        addFriend_pb->setMinimumSize(QSize(0, 24));
        addFriend_pb->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgba(255, 58, 34, 195);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border:1px solid rgba(255, 58, 34, 195);\n"
"	border-radius:4px;\n"
"padding:3px;\n"
"padding-left:5px;\n"
"padding-right:5px;\n"
"}"));

        verticalLayout_4->addWidget(addFriend_pb);


        verticalLayout_3->addWidget(frame_11);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        verticalLayout_2->setStretch(0, 10);

        horizontalLayout_4->addWidget(frame_8);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout->addWidget(frame_3);

        verticalLayout->setStretch(0, 10);

        horizontalLayout_2->addWidget(frame);


        horizontalLayout->addWidget(widget);


        retranslateUi(Online);

        QMetaObject::connectSlotsByName(Online);
    } // setupUi

    void retranslateUi(QWidget *Online)
    {
        Online->setWindowTitle(QCoreApplication::translate("Online", "Form", nullptr));
        addFriend_pb->setText(QCoreApplication::translate("Online", "\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Online: public Ui_Online {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_H
