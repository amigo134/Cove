#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
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
signals:

private:
    QSqlDatabase m_db;//用于连接数据库
};

#endif // OPEDB_H
