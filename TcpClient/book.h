#ifndef BOOK_H
#define BOOK_H

#include "protocol.h"

#include <QFile>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QTimer>
#include <QWidget>

namespace Ui {
class Book;
}

class Book : public QWidget
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();
    void onItemChanged(QTableWidgetItem *item);
    void updateFileList(const PDU *pdu);
    QString convertFileSize(qint64 bytes);
    QString getFileInfo(int fileType, const QString& fileName);
    void updateLocalDownloadFileName();//更新本地下载文件的文件名称
    QString enterPath() const;

    bool pDownload();
    void setPDownload(bool newPDownload);
    qint64 m_iTotal;//下载文件的总字节大小
    qint64 m_iRevice;//下载文件目前接受到文件的大小
    QFile m_pFile;//用于本地下载文件使用

public slots:
    void uploadFileData();
private slots:

    void on_m_pCreateDirPB_clicked();

    void on_m_pFlushFilePB_clicked();

    void on_m_pDelDirPB_clicked();

    void on_m_pRenamePB_clicked();
    void rename(QTableWidgetItem *item);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_m_returnPB_clicked();

    void on_m_pUploadPB_clicked();

    void on_m_pDownloadFilePB_clicked();

    void onShareButtonClicked();

private:
    Ui::Book *ui;
    QPushButton *sharePB;
    QString oldName;
    QString m_enterPath;


    bool  m_pDownload;//是否处于文件下载状态

    QString m_strUploadFilePath;//上传文件的路径
    QTimer *m_pTimer;//定时器执行上传文件，【防止发送文件数据过快导致粘包】
    QString m_strSaveFilePath;//保存文件的路径

    QString m_shareFileName;
};

#endif // BOOK_H
