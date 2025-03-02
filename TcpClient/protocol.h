#ifndef PROTOCOL_H
#define PROTOCOL_H

#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <QString>
#include <QDateTime>

typedef unsigned int uint;

#define REGIST_OK "regist_ok"
#define REGIST_FAILED "regist failed : name existed"

#define LOGIN_OK "login_ok"
#define LOGIN_FAILED "login failed : name error or pwd error or relogin"

#define SEARCH_USR_NO "no such people"
#define SEARCH_USR_ONLINE "online"
#define SEARCH_USR_OFFLINE "offline"

#define UNKNOW_ERROR "unkonw error"
#define EXIST_FRIEND "friend exist"
#define ADD_FRIEND_OFFLINE "usr offline"
#define ADD_FRIEND_NO_EXIST "usr not exist"

#define ADD_FRIEND_AGREE_SUCCEED "add friend succeed"
#define ADD_FRIEND_AGREE_FAILED "agree but add friend failed"
#define ADD_FRIEND_REFUSE "refuse"

#define DELETE_FRIEND_OK "delete friend ok"

#define CUR_DIR_NOT_EXIST "cur dir not exist"
#define FILE_NAME_EXIST "file name exist"
#define CREATE_DIR_OK "create dir ok"
#define CREATE_DIR_ERROR "create dir error"

#define DEL_DIR_OK "delete dir ok"
#define DEL_DIR_TYPE_ERROR "delete dir fail: it is a file"
#define DEL_DIR_SYSTEM_ERROR "delete dir fail: can not delete"

#define RENAME_FILE_OK "rename file ok"
#define RENAME_FILE_FIAL "rename file fail"

#define ENTER_DIR_FAIL "enter dir fail：is reguler file"
#define ENTER_DIR_OK "enter dir ok"

#define UPLOAD_FILE_OK "upload file ok"
#define UPLOAD_FILE_FAIL "upload file fail"

#define DEL_FILE_OK "delete file ok"
#define DEL_FILE_TYPE_ERROR "delete file fail: it is a dir"
#define DEL_FILE_SYSTEM_ERROR "delete file fail: can not delete"
enum ENUM_MSG_TYPE
{
    ENUM_MSG_TYPE_MIN=0,
    ENUM_MSG_TYPE_REGIST_REQUEST,  //注册请求
    ENUM_MSG_TYPE_REGIST_RESPOND,  //注册回复
    ENUM_MSG_TYPE_LOGIN_REQUEST,  //登录请求
    ENUM_MSG_TYPE_LOGIN_RESPOND,  //登录回复
    ENUM_MSG_TYPE_ALL_ONLINE_REQUEST,//在线用户请求
    ENUM_MSG_TYPE_ALL_ONLINE_RESPOND,//在线用户回复
    ENUM_MSG_TYPE_SEARCH_USR_REQUEST,//搜索用户请求
    ENUM_MSG_TYPE_SEARCH_USR_RESPOND,//搜索用户回复
    ENUM_MSG_TYPE_ADD_FRIEND_REQUEST,//加好友请求
    ENUM_MSG_TYPE_ADD_FRIEND_RESPOND,//加好友回复
    ENUM_MSG_TYPE_ADD_FRIEND_AGREE,  //同意添加好友
    ENUM_MSG_TYPE_ADD_FRIEND_REFUSE,  //拒绝添加好友
    ENUM_MSG_TYPE_ADD_FRIEND_AGREE_RESPOND, //同意添加好友回复
    ENUM_MSG_TYPE_ADD_FRIEND_REFUSE_RESPOND, //拒绝添加好友的回复
    ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST,//刷新好友请求
    ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND,//刷新好友回复
    ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST,//删除好友请求
    ENUM_MSG_TYPE_DELETE_FRIEND_RESPOND,//删除好友回复
    ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST,//私聊请求
    ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND,//私聊回复

    ENUM_MSG_TYPE_GROUP_CHAT_REQUEST,//群聊请求
    ENUM_MSG_TYPE_GROUP_CHAT_RESPOND,//群聊回复

    ENUM_MSG_TYPE_CREATE_DIR_REQUEST,//创建文件夹请求
    ENUM_MSG_TYPE_CREATE_DIR_RESPOND,//创建文件夹回复

    ENUM_MSG_TYPE_FLUSH_DIR_REQUEST,//刷新文件夹请求
    ENUM_MSG_TYPE_FLUSH_DIR_RESPOND,//刷新文件夹回复

    ENUM_MSG_TYPE_DEL_DIR_REQUEST,//删除文件夹请求
    ENUM_MSG_TYPE_DEL_DIR_RESPOND,//删除文件夹回复

    ENUM_MSG_TYPE_RENAME_DIR_REQUEST,//重命名文件夹请求
    ENUM_MSG_TYPE_RENAME_DIR_RESPOND,//重命名文件夹回复

    ENUM_MSG_TYPE_ENTER_DIR_REQUEST,//进入文件夹请求
    ENUM_MSG_TYPE_ENTER_DIR_RESPOND,//进入文件夹回复

    ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST,//上传文件请求
    ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND,//上传文件回复

    ENUM_MSG_TYPE_DEL_FILE_REQUEST,//删除文件请求
    ENUM_MSG_TYPE_DEL_FILE_RESPOND,//删除文件回复

    ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST,//下载文件请求
    ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND,//下载文件回复

    ENUM_MSG_TYPE_SHARE_FILE_REQUEST,//共享文件请求
    ENUM_MSG_TYPE_SHARE_FILE_RESPOND,//共享文件回复
    ENUM_MSG_TYPE_SHARE_FILE_NOTE,//共享文件通知
    ENUM_MSG_TYPE_SHARE_FILE_NOTE_REQUEST,//共享文件通知请求
    ENUM_MSG_TYPE_SHARE_FILE_NOTE_RESPOND,//共享文件通知回复

    // ENUM_MSG_TYPE_REQUEST,
    // ENUM_MSG_TYPE_RESPOND,
    ENUM_MSG_TYPE_MAX=0x00ffffff
};

struct PDU
{
    uint uiPDULen;  //总的协议数据单元大小
    uint uiMsgType; //消息类型
    char caData[64];
    uint uiMsgLen;  //实际消息长度
    int caMsg[];    //实际消息
};

struct FileInfoStruct {
    char caFileName[128]; //文件名称  // 文件名
    long long fileSize;   // 文件大小（字节）
   char lastModified[64]; // 文件最后修改时间
    int fileType;            // 文件类型
};

PDU *mkPDU(uint uiMsgLen);
#endif // PROTOCOL_H
