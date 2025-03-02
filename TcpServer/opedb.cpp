#include "opedb.h"
#include <QVariant>
#include <QDebug>
#include <QMessageBox>

OpeDB::OpeDB(QObject *parent)
    : QObject{parent}
{

}

OpeDB::~OpeDB()
{
    // 关闭所有线程中的数据库连接
    QMutexLocker locker(&mutex);
    QHash<Qt::HANDLE, QSqlDatabase>::iterator it;
    for (it = connections.begin(); it != connections.end(); ++it) {
        QSqlDatabase db = it.value();
        if (db.isOpen()) {
            db.close();
        }
        QString connectionName = db.connectionName();
        QSqlDatabase::removeDatabase(connectionName);
    }
    connections.clear();
    m_db.close();
}

OpeDB &OpeDB::getInstance()
{
    static OpeDB instance;
    return instance;
}

void OpeDB::init()
{

}

bool OpeDB::handleRegist(const char *name, const char *pwd)
{
    if(NULL == name || NULL == pwd)
    {
        return false;
    }
    QString data = QString("insert into usrInfo(name,pwd) values(\'%1\',\'%2\')").arg(name).arg(pwd);
    qDebug() <<data;
    QSqlQuery query;
    return query.exec(data);



    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {

    }
    return false;
}

bool OpeDB::handleLogin(const char *name, const char *pwd)
{

    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {
        QSqlQuery query(db);
        if(NULL == name || NULL == pwd)
        {
            return false;
        }
        QString data = QString("select * from usrInfo where name=\'%1\' and pwd=\'%2\' and online=0").arg(name).arg(pwd);
        qDebug() <<data;
       // QSqlQuery query;
        query.exec(data);
        if(query.next())
        {
            QString data = QString("update usrInfo set online=1 where name=\'%1\' and pwd=\'%2\'").arg(name).arg(pwd);
            qDebug() <<data;
            QSqlQuery query(db);
            query.exec(data);
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void OpeDB::handleOffline(const char *name)
{

    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {
        if(NULL == name)
        {
            return;
        }
        QString data = QString("update usrInfo set online=0 where name=\'%1\'").arg(name);
        qDebug() <<data;
        QSqlQuery query(db);
        query.exec(data);
    }
    return ;
}

QStringList OpeDB::handleALLOnline()
{




    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {
        QString data = QString("select name from usrInfo where online=1");
        qDebug() <<data;
        QSqlQuery query(db);
        query.exec(data);
        QStringList result;
        result.clear();
        while(query.next())
        {
            result.append(query.value(0).toString());
        }
        return result;
    }
    return QStringList();



}

int OpeDB::handleSearchUsr(const char *name)
{

    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {

        if(NULL==name)
        {
            return -1;
        }
        QString data = QString("select online from usrInfo where name=\'%1\'").arg(name);
        qDebug() <<data;
        QSqlQuery query(db);
        query.exec(data);
        if(query.next())
        {
            int ret=query.value(0).toInt();
            return ret;
        }
        else
        {
            return -1;
        }

    }
    return false;
}

int OpeDB::handleAddFriend(const char *pername, const char *name)
{

    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {

        if(NULL == pername || NULL == name)
        {
            return -1;
        }
        QString data = QString("select * from friend where (id=(select id from usrInfo where name=\'%1\') and friendid=(select id from usrInfo where name=\'%2\' ))"
                               "or(id=(select id from usrInfo where name=\'%2\') and friendid=(select id from usrInfo where name=\'%1\' ))").arg(pername).arg(name);
        qDebug() <<data;
        QSqlQuery query(db);
        query.exec(data);
        if(query.next())
        {
            qDebug() << query.value(0) <<query.value(1);
            return 0; //双方已经是好友
        }
        else
        {
            QString data = QString("select online from usrInfo where name=\'%1\'").arg(pername);
            qDebug() <<data;
            QSqlQuery query(db);
            query.exec(data);
            if(query.next())
            {
                int ret=query.value(0).toInt();
                if(1 == ret)
                {
                    return 1;  //不是好友，在线
                }
                else if(0 == ret)
                {
                    return 2; //不在线
                }
            }
            else
            {
                return 3; //不存在
            }
        }

    }
    return -1;
}

bool OpeDB::handleAgreeFriend(const char *pername, const char *name)
{


    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {
        if(NULL == pername || NULL == name)
        {
            return false;
        }
        QString data = QString("INSERT INTO friend (id, friendId) SELECT (SELECT id FROM usrInfo WHERE name = \'%1\'),(SELECT id FROM usrInfo WHERE name = \'%2\');").arg(name).arg(pername);
        qDebug() <<data;
        QSqlQuery query(db);
        return query.exec(data);
    }
    return false;
}


QStringList OpeDB::handleFlushFriend(const char *name)
{


    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {




        QStringList strNameList;
        strNameList.clear();

        if(NULL == name)
        {
            return strNameList;
        }

        QString strSql = QString("select id from usrInfo where name = \'%1\'").arg(name);
        QSqlQuery query(db);
        query.exec(strSql);
        query.next();
        int loginId = query.value(0).toInt();
        strSql = QString("select friendId from friend where id = %1").arg(loginId);
        query.exec(strSql);
        while(query.next())
        {
            int friendId = query.value(0).toInt();
            strSql = QString("select name from usrInfo where id = %1 and online = 1").arg(friendId);
            QSqlQuery nameQuery(db);
            nameQuery.exec(strSql);
            if(nameQuery.next())
            {
                strNameList.append(nameQuery.value(0).toString());
            }
        }
        strSql = QString("select id from friend where friendId = %1").arg(loginId);
        query.exec(strSql);
        while(query.next())
        {
            int friendId = query.value(0).toInt();
            strSql = QString("select name from usrInfo where id = %1 and online = 1").arg(friendId);
            QSqlQuery nameQuery(db);
            nameQuery.exec(strSql);
            if(nameQuery.next())
            {
                strNameList.append(nameQuery.value(0).toString());
            }
        }

        return strNameList;
    }
    return QStringList(0);
}

bool OpeDB::handleDelFriend(const char *pername, const char *name)
{


    QSqlDatabase db = getDatabase();
    if (db.isOpen()) {
        if(NULL == pername || NULL == name)
        {
            return false;
        }
        QString strSql = QString("select id from usrInfo where name = '%1'").arg(pername);
        QSqlQuery query(db);
        query.exec(strSql);
        query.next();
        int friendId = query.value(0).toInt();
        strSql = QString("select id from usrInfo where name = '%1'").arg(name);
        query.exec(strSql);
        query.next();
        int userId = query.value(0).toInt();
        strSql = QString("delete from friend where (id = '%1' and friendId = '%2') or (id = '%2' and friendId = '%1')").arg(userId).arg(friendId);
        return query.exec(strSql);
    }
    return false;

}

