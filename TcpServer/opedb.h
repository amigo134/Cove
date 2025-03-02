#ifndef OPEDB_H
#define OPEDB_H

#include <QMutex>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QThread>
#include <QString>
#include <QDebug>
class OpeDB : public QObject
{
    Q_OBJECT
public:
    explicit OpeDB(QObject *parent = nullptr);
    ~OpeDB();
    static OpeDB& getInstance();
    void init();
    bool handleRegist(const char *name,const char *pwd);
    bool handleLogin(const char *name,const char *pwd);
    void handleOffline(const char *name);
    QStringList handleALLOnline();
    int handleSearchUsr(const char *name);
    int handleAddFriend(const char *pername,const char *name);
    bool handleAgreeFriend(const char *pername,const char *name);
    // 刷新好友列表
    QStringList handleFlushFriend(const char *name);
    bool handleDelFriend(const char *pername,const char *name);
    QSqlDatabase getDatabase() {
        QMutexLocker locker(&mutex);
        Qt::HANDLE currentThreadId = QThread::currentThreadId();
         QString handleStr1 = QString::number(reinterpret_cast<quintptr>(currentThreadId), 16);
        if (!connections.contains(currentThreadId)) {
            QString connectionName = QString("DBConnection_%1").arg(handleStr1);
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("C:\\Users\\COZY\\Documents\\TcpServer\\cloud.db");
            if (db.open()) {
                qDebug() << "Database opened successfully in thread:" << currentThreadId;
            } else {
                qDebug() << "Failed to open database in thread:" << currentThreadId;
            }
            connections.insert(currentThreadId, db);
        }
        return connections[currentThreadId];
    }
signals:

private:
    QSqlDatabase m_db;//用于连接数据库
    QHash<Qt::HANDLE, QSqlDatabase> connections;
    QMutex mutex;
};

#endif // OPEDB_H
