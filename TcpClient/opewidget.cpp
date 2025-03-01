#include "opewidget.h"
#include "ui_opewidget.h"
#include "friend.h"
#include "book.h"
#include "tcpclient.h"
OpeWidget::OpeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OpeWidget)
{
    ui->setupUi(this);
    ui->pushButton->setText(TcpClient::getInstance().strLoginName());
    // 清空 QStackedWidget
    while (ui->stackedWidget->count() > 0) {
        QWidget *widget = ui->stackedWidget->widget(0);
        ui->stackedWidget->removeWidget(widget);
        // 若需要手动释放内存（通常 Qt 会自动管理）
        delete widget;
    }
    m_pFriend = new Friend;
    m_pBook=new Book;
    ui->stackedWidget->addWidget(m_pFriend);
    ui->stackedWidget->addWidget(m_pBook);
    ui->stackedWidget->setCurrentWidget(m_pFriend);
    connect(ui->m_pListW,SIGNAL(currentRowChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
}

OpeWidget &OpeWidget::getInstance()
{
    static OpeWidget instance;
    instance.setWindowFlags(instance.windowFlags() | Qt::FramelessWindowHint);
    instance.setAttribute(Qt::WA_TranslucentBackground);
    return instance;
}

OpeWidget::~OpeWidget()
{
    delete ui;
}

void OpeWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标按下时的位置
        m_dragStartPosition = event->globalPos() - frameGeometry().topLeft();
        m_isDragging = true;
        event->accept();
    }
}

void OpeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging && (event->buttons() & Qt::LeftButton)) {
        // 计算窗口需要移动的距离
        move(event->globalPos() - m_dragStartPosition);
        event->accept();
    }
}

void OpeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
        event->accept();
    }
}

Friend *OpeWidget::pFriend() const
{
    return m_pFriend;
}

void OpeWidget::on_pushButton_6_clicked()
{
    if (isMaximized()) {
        // 如果窗口当前是最大化状态，将其还原
        showNormal();

    } else {
        // 如果窗口当前是正常状态，将其最大化
        showMaximized();

    }
}

Book *OpeWidget::pBook() const
{
    return m_pBook;
}

