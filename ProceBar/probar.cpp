#include "probar.h"
#include "ui_probar.h"
#include <QResizeEvent>
#include <QDebug>
#include "tlabel.h"

Probar::Probar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Probar)
{
    ui->setupUi(this);
    ui->label->setFixedSize(0,0);
    //ui->label->setAlignment(Qt::AlignCenter);
    //ui->label->setAttribute(Qt::WA_TranslucentBackground);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Probar::barReset);
    timer->setInterval(5);
    //setColor("rgb(80,180,50)");
    setFont(QFont("微软雅黑",10,QFont::Normal,false));
    ui->ratelab->setborderCol(QColor(240,0,0));
    ui->rate->setborderCol(QColor(240,0,0));
}

Probar::~Probar()
{
    delete ui;
}

bool Probar::setCurrentSize(int size)
{
    if(1 > MaxSize) {
        ui->rate->setText("");
        ui->ratelab->setText("0000/0000");
        return false;
    }
    else if(size > MaxSize || size < 0) return false;
    else{
        cSize = size;
        setRate();
        timer->start();
        return true;
    }
}

void Probar::setColor(QString rgb)
{
    this->rgb = rgb;
    int height = this->size().height();
    int width = this->size().width();
    int ra = ((width>height) ? height:width)/2;
    ui->label->setStyleSheet("border:0px;border-radius:" + QString::number(ra) +"px;" + "background-color: " + rgb);
}

void Probar::setFont(QFont font)
{
    ui->ratelab->setFont(font);
    ui->rate->setFont(font);
    ui->rate->move(0,0);
    ui->rate->setFixedSize(40,ui->frame->size().height());
}

void Probar::setTextColor(QColor innercol, QColor bordercol)
{
    ui->ratelab->setinnerCol(innercol);
    ui->ratelab->setborderCol(bordercol);
    ui->rate->setinnerCol(innercol);
    ui->rate->setborderCol(bordercol);
}

void Probar::setRate()
{
    int rate = cSize*100/MaxSize;
    ui->rate->setText(QString::number(rate) + "%");
    ui->ratelab->setText(QString::number(cSize) + "/" + QString::number(MaxSize));
}

void Probar::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Probar::resizeEvent(QResizeEvent *event)
{
    //int width = event->size().width();
    int height = event->size().height();
    ui->label->setFixedHeight(height);
    ui->ratelab->setFixedSize(event->size());
    //int ra = ((width>height) ? height:width)/2;
    //ui->label->setStyleSheet("border:0px;border-radius:" + QString::number(ra) +"px;" + "background-color: " + rgb);
    ui->frame->setStyleSheet("border-radius:" + QString::number(height/2) +"px;" + "background-color: " + backrgb);
    ui->rate->setStyleSheet("border:0px;background-color: " + backrgb);
    ui->ratelab->setStyleSheet("border:0px;background-color: " + backrgb);
    setCurrentSize(cSize);
}

void Probar::barReset()
{
    if(1 > MaxSize) return;
    int wid = ui->label->size().width();
    int size = ui->frame->size().width();
    int bit = size/50;
    int hei = ui->label->size().height();
    if(wid <= size*cSize/MaxSize + bit && wid >= size*cSize/MaxSize - bit){
        wid = size*cSize/MaxSize;
        timer->stop();
    }else if(wid > size*cSize/MaxSize + bit){
        wid -= bit;
    }else if(wid < size*cSize/MaxSize - bit){
        wid += bit;
    }
    if(wid < ui->frame->size().height()) hei = wid;
    else hei = ui->frame->size().height();
    ui->label->setFixedSize(wid, hei);
    ui->label->move(0,(ui->frame->size().height()-hei)/2);
    int ra = hei/2;
    ui->label->setStyleSheet("border:0px;border-radius:" + QString::number(ra) +"px;" + "background-color: " + rgb);
    ui->ratelab->update();
}
