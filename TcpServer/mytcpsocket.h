#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QFile>
#include <QTcpSocket>
#include <QTimer>
#include "protocol.h"
#include "opedb.h"
class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = nullptr);

    QString strName() const;

    void copyDir(QString sourceDir, QString targetDir);
signals:
    void offline(MyTcpSocket *mysocket);

public slots:
    void recvMsg();
    void clientOffline();
    void sendFileDataToClient();

private:
    QString m_strName;
    QFile m_file;//上传的文件
    qint64 m_iTotal;//文件总大小
    qint64 m_iRecved;//已接受到的数据大小
    bool m_bUpload; //正在上传文件的状态
    qint64 m_iCount;//计数
    QTimer *m_pTimer;
};

#endif // MYTCPSOCKET_H
