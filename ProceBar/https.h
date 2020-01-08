#ifndef HTTPS_H
#define HTTPS_H

#include <QtCore/qglobal.h>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>  //加载网络请求头文件
#include <QtNetwork/QNetworkRequest>  //加载发送请求头文件
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QDebug>
#include <QEventLoop>
#include <QSsl>
#include <QThread>
#include <QApplication>
#include <QObject>

class Https:public QObject
{
    Q_OBJECT
public:
    Https(QObject* parent = nullptr);
    virtual ~Https();
    inline void init();
    QByteArray getHttps(QString url);
private:
    QNetworkAccessManager *manage;
    QNetworkRequest* request;
    QNetworkReply* reply;
    QByteArray buffer;
    volatile bool isfinished;
protected:

private slots:
    void httpFinished();
    void httpReadyRead();
};

#endif // HTTPS_H
