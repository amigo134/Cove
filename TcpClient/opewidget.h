#ifndef OPEWIDGET_H
#define OPEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
class Book;
class Friend;

namespace Ui {
class OpeWidget;
}

class OpeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OpeWidget(QWidget *parent = nullptr);
    static OpeWidget &getInstance();
    ~OpeWidget();

    Friend *pFriend() const;

    Book *pBook() const;

protected:
    // 鼠标按下事件处理函数
    void mousePressEvent(QMouseEvent *event) override;

    // 鼠标移动事件处理函数
    void mouseMoveEvent(QMouseEvent *event) override;

    // 鼠标释放事件处理函数
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_6_clicked();

private:
    Ui::OpeWidget *ui;
    Friend *m_pFriend;
    Book *m_pBook;
    QPoint m_dragStartPosition;
    bool m_isDragging;
};

#endif // OPEWIDGET_H
