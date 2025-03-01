/********************************************************************************
** Form generated from reading UI file 'opewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPEWIDGET_H
#define UI_OPEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_29;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_3;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QListWidget *m_pListW;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_23;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_22;
    QWidget *page_2;
    QFrame *frame_27;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_14;
    QFrame *frame_15;
    QHBoxLayout *horizontalLayout_16;

    void setupUi(QWidget *OpeWidget)
    {
        if (OpeWidget->objectName().isEmpty())
            OpeWidget->setObjectName(QString::fromUtf8("OpeWidget"));
        OpeWidget->resize(1125, 929);
        horizontalLayout = new QHBoxLayout(OpeWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(OpeWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_29 = new QHBoxLayout(widget);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
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
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777, 50));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"	color:rgba(255, 255, 255, 210);\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMaximumSize(QSize(16777, 16777213));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setSpacing(18);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(18, 12, 3, 18);
        pushButton_5 = new QPushButton(frame_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(12, 12));
        pushButton_5->setMaximumSize(QSize(12, 12));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	background-color: rgb(240, 108, 96);\n"
"border:1px solid rgba(113, 17, 15,50);\n"
"border-radius:6px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color:rgb(139, 29, 31)\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(232, 59, 35);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(frame_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(12, 12));
        pushButton_6->setMaximumSize(QSize(12, 12));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	background-color: rgb(231, 193, 75);\n"
"border:1px solid rgb(166, 151, 66);\n"
"border-radius:6px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(124, 111, 38);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"	\n"
"	background-color: rgb(231, 193, 75);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(frame_5);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(12, 12));
        pushButton_7->setMaximumSize(QSize(12, 12));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(35, 158, 33);\n"
"border:1px solid rgb(25, 87, 16);\n"
"border-radius:6px;\n"
"}\n"
"QPushButton:hover {\n"
"	\n"
"	background-color: rgb(15, 118, 13);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(35, 158, 33);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addWidget(frame_5);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addWidget(frame_2);

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
        frame_10 = new QFrame(frame_8);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_10);
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(8, 2, 8, 2);
        widget_3 = new QWidget(frame_10);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(48, 48));
        widget_3->setMaximumSize(QSize(48, 48));
        widget_3->setCursor(QCursor(Qt::PointingHandCursor));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{image:url(:/images/images/1.jpg);\n"
"border-radius:24px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_7->addWidget(widget_3);

        pushButton = new QPushButton(frame_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border:none;\n"
"text-align:left;"));

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout_2->addWidget(frame_10);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1073, 723));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_pListW = new QListWidget(scrollAreaWidgetContents);
        new QListWidgetItem(m_pListW);
        new QListWidgetItem(m_pListW);
        m_pListW->setObjectName(QString::fromUtf8("m_pListW"));
        m_pListW->setMinimumSize(QSize(0, 180));
        m_pListW->setMaximumSize(QSize(16777215, 180));
        QFont font;
        m_pListW->setFont(font);
        m_pListW->setStyleSheet(QString::fromUtf8("QListView {\n"
"	border-radius: 20px;\n"
"outline:0px;\n"
"}\n"
"QListView::item{\n"
"background-color: transparent;\n"
"	padding: 8px;\n"
"padding-left: 18px;\n"
"padding-right: 18px;\n"
"margin-bottom:0px;\n"
"\n"
"}\n"
"QListView::item:hover {\n"
"background-color: rgba(216, 216, 216, 70);\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}\n"
"QListView::item:selected {\n"
"	/*background-color: transparent;*/\n"
"	border-radius: 8px;\n"
"background-color: rgba(216, 216, 216, 70);\n"
"	color: black;\n"
"\n"
"\n"
"}"));
        m_pListW->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_pListW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_pListW->setIconSize(QSize(16, 16));

        verticalLayout_3->addWidget(m_pListW);

        frame_11 = new QFrame(scrollAreaWidgetContents);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_11);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(frame_11);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);

        horizontalLayout_4->addWidget(frame_8);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_23 = new QHBoxLayout(frame_7);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        stackedWidget = new QStackedWidget(frame_7);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("${\n"
"\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical{\n"
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
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_22 = new QHBoxLayout(page);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_23->addWidget(stackedWidget);


        horizontalLayout_4->addWidget(frame_7);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout->addWidget(frame_3);

        frame_27 = new QFrame(frame);
        frame_27->setObjectName(QString::fromUtf8("frame_27"));
        frame_27->setFrameShape(QFrame::StyledPanel);
        frame_27->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_27);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frame_27);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 60));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"	color:rgba(255, 255, 255, 210);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame_4);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(12, 0, 12, 0);
        frame_15 = new QFrame(frame_4);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_15);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));

        horizontalLayout_14->addWidget(frame_15);

        horizontalLayout_14->setStretch(0, 2);

        verticalLayout->addWidget(frame_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        horizontalLayout_29->addWidget(frame);


        horizontalLayout->addWidget(widget);


        retranslateUi(OpeWidget);
        QObject::connect(pushButton_5, SIGNAL(clicked()), OpeWidget, SLOT(close()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), OpeWidget, SLOT(showMinimized()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OpeWidget);
    } // setupUi

    void retranslateUi(QWidget *OpeWidget)
    {
        OpeWidget->setWindowTitle(QCoreApplication::translate("OpeWidget", "Form", nullptr));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton->setText(QCoreApplication::translate("OpeWidget", "jack", nullptr));

        const bool __sortingEnabled = m_pListW->isSortingEnabled();
        m_pListW->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = m_pListW->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("OpeWidget", "\345\245\275\345\217\213", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = m_pListW->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("OpeWidget", "\347\275\221\347\233\230", nullptr));
        m_pListW->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class OpeWidget: public Ui_OpeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPEWIDGET_H
