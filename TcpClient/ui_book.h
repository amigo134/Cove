/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Book
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_20;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *m_returnPB;
    QPushButton *m_pUploadPB;
    QPushButton *m_pCreateDirPB;
    QPushButton *m_pRenamePB;
    QPushButton *m_pDelDirPB;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *lineEdit;
    QPushButton *pushButton_14;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QLabel *label_5;
    QToolButton *m_pDownloadFilePB;
    QToolButton *m_pFlushFilePB;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Book)
    {
        if (Book->objectName().isEmpty())
            Book->setObjectName(QString::fromUtf8("Book"));
        Book->resize(910, 556);
        verticalLayout_2 = new QVBoxLayout(Book);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(Book);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(251, 251, 251);\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;\n"
"border-bottom-right-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setSpacing(12);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_20 = new QFrame(frame);
        frame_20->setObjectName(QString::fromUtf8("frame_20"));
        frame_20->setStyleSheet(QString::fromUtf8("QFrame#Frame_20{\n"
"	background-color: rgb(246, 246, 246);\n"
"border-top-left-radius:0px;\n"
"border-top-right-radius:0px;\n"
"border-bottom-right-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"}"));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        horizontalLayout_21 = new QHBoxLayout(frame_20);
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_4 = new QFrame(frame_20);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_4);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_6);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(frame_6);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_7);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(12, 4, 12, 4);
        m_returnPB = new QPushButton(frame_7);
        m_returnPB->setObjectName(QString::fromUtf8("m_returnPB"));
        m_returnPB->setMinimumSize(QSize(0, 36));
        m_returnPB->setMaximumSize(QSize(16777215, 36));
        m_returnPB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:4px;\n"
"padding-left:12px;padding-right:12px;\n"
"	color: rgb(31, 171, 255);\n"
"	background-color: rgb(240, 250, 255);\n"
"	border:1px outset rgb(255, 255, 255);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
""));

        horizontalLayout_16->addWidget(m_returnPB);

        m_pUploadPB = new QPushButton(frame_7);
        m_pUploadPB->setObjectName(QString::fromUtf8("m_pUploadPB"));
        m_pUploadPB->setMinimumSize(QSize(0, 36));
        m_pUploadPB->setMaximumSize(QSize(16777215, 36));
        m_pUploadPB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:4px;\n"
"padding-left:12px;padding-right:12px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 167, 255);\n"
"	border:1px outset rgb(255, 255, 255);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(7, 167, 255);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(7, 167, 255);\n"
"\n"
"}\n"
""));

        horizontalLayout_16->addWidget(m_pUploadPB);

        m_pCreateDirPB = new QPushButton(frame_7);
        m_pCreateDirPB->setObjectName(QString::fromUtf8("m_pCreateDirPB"));
        m_pCreateDirPB->setMinimumSize(QSize(0, 36));
        m_pCreateDirPB->setMaximumSize(QSize(16777215, 36));
        m_pCreateDirPB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:4px;\n"
"padding-left:12px;padding-right:12px;\n"
"	color: rgb(31, 171, 255);\n"
"	background-color: rgb(240, 250, 255);\n"
"	border:1px outset rgb(255, 255, 255);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
""));

        horizontalLayout_16->addWidget(m_pCreateDirPB);

        m_pRenamePB = new QPushButton(frame_7);
        m_pRenamePB->setObjectName(QString::fromUtf8("m_pRenamePB"));
        m_pRenamePB->setMinimumSize(QSize(0, 36));
        m_pRenamePB->setMaximumSize(QSize(16777215, 36));
        m_pRenamePB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:4px;\n"
"padding-left:12px;padding-right:12px;\n"
"	color: rgb(31, 171, 255);\n"
"	background-color: rgb(240, 250, 255);\n"
"	border:1px outset rgb(255, 255, 255);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
""));

        horizontalLayout_16->addWidget(m_pRenamePB);

        m_pDelDirPB = new QPushButton(frame_7);
        m_pDelDirPB->setObjectName(QString::fromUtf8("m_pDelDirPB"));
        m_pDelDirPB->setMinimumSize(QSize(0, 36));
        m_pDelDirPB->setMaximumSize(QSize(16777215, 36));
        m_pDelDirPB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:4px;\n"
"padding-left:12px;padding-right:12px;\n"
"	color: rgba(255, 58, 34, 195);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	\n"
"border:1px solid rgba(255, 58, 34, 195);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(240, 250, 255);\n"
"\n"
"}\n"
""));

        horizontalLayout_16->addWidget(m_pDelDirPB);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_5);

        frame_16 = new QFrame(frame_7);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMinimumSize(QSize(0, 32));
        frame_16->setMaximumSize(QSize(16777, 32));
        frame_16->setStyleSheet(QString::fromUtf8("QFrame{\n"
"padding-left:6px;\n"
"padding-right:12px;\n"
"	background-color: rgba(0, 0, 0, 10);\n"
"border-radius:12px;\n"
"}"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_16);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(frame_16);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgba(0, 0, 0, 60);\n"
"padding-left:6px"));

        horizontalLayout_15->addWidget(lineEdit);

        pushButton_14 = new QPushButton(frame_16);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMaximumSize(QSize(16777215, 32));
        pushButton_14->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgba(0, 0, 0, 158);"));

        horizontalLayout_15->addWidget(pushButton_14);


        horizontalLayout_16->addWidget(frame_16);


        verticalLayout_6->addWidget(frame_7);

        frame_8 = new QFrame(frame_6);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setMinimumSize(QSize(0, 0));
        frame_8->setMaximumSize(QSize(16777215, 32));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_8);
        horizontalLayout_17->setSpacing(8);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(12, 0, 12, 0);
        label_7 = new QLabel(frame_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 143);"));

        horizontalLayout_17->addWidget(label_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        label_6 = new QLabel(frame_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 143);"));

        horizontalLayout_17->addWidget(label_6);

        label_5 = new QLabel(frame_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 143);"));

        horizontalLayout_17->addWidget(label_5);

        m_pDownloadFilePB = new QToolButton(frame_8);
        m_pDownloadFilePB->setObjectName(QString::fromUtf8("m_pDownloadFilePB"));
        m_pDownloadFilePB->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"border:1px solid rgb(197, 197, 197);\n"
"	border-radius:6px;\n"
"padding:2px;\n"
"padding-left:6px;padding-right:6px;\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"background-color: rgba(0, 0, 0, 15);\n"
"\n"
"}\n"
"QToolButton:pressed {\n"
"background-color: rgba(0, 0, 0, 20);\n"
"\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pDownloadFilePB->setIcon(icon);
        m_pDownloadFilePB->setIconSize(QSize(18, 18));

        horizontalLayout_17->addWidget(m_pDownloadFilePB);

        m_pFlushFilePB = new QToolButton(frame_8);
        m_pFlushFilePB->setObjectName(QString::fromUtf8("m_pFlushFilePB"));
        m_pFlushFilePB->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"border:1px solid rgb(197, 197, 197);\n"
"	border-radius:6px;\n"
"padding:2px;\n"
"padding-left:6px;padding-right:6px;\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"background-color: rgba(0, 0, 0, 15);\n"
"\n"
"}\n"
"QToolButton:pressed {\n"
"background-color: rgba(0, 0, 0, 20);\n"
"\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pFlushFilePB->setIcon(icon1);
        m_pFlushFilePB->setIconSize(QSize(18, 18));

        horizontalLayout_17->addWidget(m_pFlushFilePB);


        verticalLayout_6->addWidget(frame_8);

        scrollArea = new QScrollArea(frame_6);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("#scrollAreaWidgetContents{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 896, 466));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 0, __qtablewidgetitem16);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/map/map/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setIcon(icon2);
        tableWidget->setItem(1, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setIcon(icon2);
        tableWidget->setItem(2, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setIcon(icon2);
        tableWidget->setItem(3, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setIcon(icon2);
        tableWidget->setItem(4, 1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(4, 4, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setIcon(icon2);
        tableWidget->setItem(5, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(5, 4, __qtablewidgetitem40);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	color: rgba(16, 16, 16,200);\n"
"outline:0px;\n"
"border-radius:0px;\n"
"selection-background-color:  rgb(235, 235, 235);\n"
"}\n"
"QTableWidget:item{\n"
"	color: rgba(16, 16, 16,200);\n"
"	border-bottom:0px solid rgba(50, 50, 50,30);\n"
"}\n"
"QHeaderView::section{\n"
"border-radius:0px;\n"
"	color: rgba(16, 16, 16,200);\n"
"}\n"
"QTableWidget:item::hover {\n"
"	color: rgba(16, 16, 16,200);\n"
"}\n"
"QTableWidget:item::focus{\n"
"	color: rgba(16, 16, 16,200);\n"
"	outline: none; \n"
"	\n"
"}\n"
"QTableWidget::item:selected {\n"
"    color: rgb(31, 171, 255); /* \351\200\211\344\270\255\347\212\266\346\200\201\344\270\213\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}"));
        tableWidget->setLineWidth(1);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(150);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);

        horizontalLayout_2->addWidget(tableWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 9);

        horizontalLayout_10->addWidget(frame_6);

        horizontalLayout_10->setStretch(0, 1);

        horizontalLayout_3->addWidget(frame_4);

        horizontalLayout_3->setStretch(0, 9);

        horizontalLayout_21->addLayout(horizontalLayout_3);


        verticalLayout_7->addWidget(frame_20);


        verticalLayout_2->addWidget(frame);


        retranslateUi(Book);

        QMetaObject::connectSlotsByName(Book);
    } // setupUi

    void retranslateUi(QWidget *Book)
    {
        Book->setWindowTitle(QCoreApplication::translate("Book", "Form", nullptr));
        m_returnPB->setText(QCoreApplication::translate("Book", "<<", nullptr));
        m_pUploadPB->setText(QCoreApplication::translate("Book", "\344\270\212\344\274\240", nullptr));
        m_pCreateDirPB->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        m_pRenamePB->setText(QCoreApplication::translate("Book", "\351\207\215\345\221\275\345\220\215", nullptr));
        m_pDelDirPB->setText(QCoreApplication::translate("Book", "\345\210\240\351\231\244", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Book", "\346\220\234\347\264\242\345\205\250\351\203\250\346\226\207\344\273\266", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Book", "\346\220\234\347\264\242", nullptr));
        label_7->setText(QCoreApplication::translate("Book", "\346\210\221\347\232\204\346\226\207\344\273\266", nullptr));
        label_6->setText(QCoreApplication::translate("Book", "\345\267\262\345\205\250\351\203\250\345\212\240\350\275\275\357\274\214", nullptr));
        label_5->setText(QCoreApplication::translate("Book", "\345\205\26116\344\270\252", nullptr));
        m_pDownloadFilePB->setText(QString());
        m_pFlushFilePB->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Book", "kuang", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Book", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Book", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Book", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Book", "\346\226\260\345\273\272\350\241\214", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Book", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Book", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Book", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Book", "maya", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Book", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\244\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Book", "2012.07.17 15:58", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Book", "\346\210\221\347\232\204\350\265\204\346\272\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Book", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\244\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 4);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Book", "2022.09.13 15:58", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(3, 1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Book", "\346\210\221\347\232\204\347\205\247\347\211\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 2);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Book", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 3);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\244\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 4);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Book", "2022.07.15 15:58", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(4, 1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Book", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(4, 2);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Book", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(4, 3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\244\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(4, 4);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("Book", "2012.08.17 15:58", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(5, 1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("Book", "\346\210\221\347\232\204\351\241\271\347\233\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(5, 2);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("Book", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(5, 3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("Book", "\346\226\207\344\273\266\345\244\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(5, 4);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("Book", "2012.07.17 12:58", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Book: public Ui_Book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H
