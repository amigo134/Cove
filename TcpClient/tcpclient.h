#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QMouseEvent>
#include <QTcpSocket>
#include <QPainter>
#include "protocol.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class TcpClient;
}
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();
    static TcpClient &getInstance();


    QTcpSocket &tcpSocket();

    QString strLoginName() const;

    QString strCurPath() const;

    void setStrCurPath(const QString &newStrCurPath);

public slots:
    void showConnect();
    void recvMsg();
private slots:

    //void on_send_pb_clicked();

    void on_login_pb_clicked();

    void on_cancel_pb_clicked();

    void on_regist_pb_clicked();
protected:
    // 鼠标按下事件处理函数
    void mousePressEvent(QMouseEvent *event) override;

    // 鼠标移动事件处理函数
    void mouseMoveEvent(QMouseEvent *event) override;

    // 鼠标释放事件处理函数
    void mouseReleaseEvent(QMouseEvent *event) override;


private:
    Ui::TcpClient *ui;
    QString m_strIP;
    quint16 m_usPort;

    QTcpSocket m_tcpSocket;
    QString m_strLoginName;

    QString m_strCurPath;


    QPoint m_dragStartPosition;
    bool m_isDragging;
    bool i=false;
};
#endif // TCPCLIENT_H
