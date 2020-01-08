#include "https.h"

Https::Https(QObject* parent)
    :QObject(parent)
{
    init();
}

Https::~Https()
{
    delete manage;
    delete  request;
}

void Https::init()
{
    manage = new QNetworkAccessManager(this);
    request = new QNetworkRequest;
    request->setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    QSslConfiguration conf = request->sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    conf.setProtocol(QSsl::TlsV1SslV3);
    request->setSslConfiguration(conf);
    request->setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request->setHeader(QNetworkRequest::ContentLengthHeader, buffer.length());
}

QByteArray Https::getHttps(QString url)
{
    buffer = nullptr;
    isfinished = false;
    request->setUrl(QUrl(url));
    reply = manage->get(*request);    //请求实现
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    volatile int i = 0;
    while(!isfinished){
        QApplication::processEvents();
        QThread::usleep(1);
        ++i;
        QApplication::processEvents();
        qDebug()<<i;
        if(i >= 500) break;
    }
    return buffer;
}

void Https::httpFinished()
{
    isfinished = true;
}

void Https::httpReadyRead()
{
    static int i = 0;
    i++;
    qDebug()<< i;
    QByteArray buf;
    buf = reply->readAll();
    buffer.insert(buffer.size(),buf);
}
