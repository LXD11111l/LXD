#include "braver.h"
#include <QDebug>
#include <QApplication>
#include <unistd.h>
#include "labelmanager.h"
#include "packetwidget.h"

Braver::Braver(RoleLable base)
    :RoleLable(base),timer(new QTimer(this)),time(new QTimer(this))
{
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    QWidget* w = static_cast<QWidget*>(this->parent());
    int _size = w->size().height();
    this->setFixedSize(_size/COL, _size/ROW);
    this->setStyleSheet("border:0px;");
    setPicture(QPoint(0,0));
    QObject::connect(timer, &QTimer::timeout, this, &Braver::roleWalk);
    timer->setInterval(17);
    this->labelMove();
    time = new QTimer(this);
    QObject::connect(time, &QTimer::timeout, this, &Braver::keyhandle);
    time->start(15);
}

Braver::~Braver()
{
    instance = nullptr;
}

Braver* Braver:: instance = nullptr;

bool Braver::pointJudge()
{
    QMap<int, unsigned char*>* mainMap = MainMapWidget::getMapdata();
    unsigned char* data = mainMap->value(MainMapWidget::Floor);
    int val = data[point.x() + point.y()*13];
    LabelManager labelmanager;
    labelmanager.Manager(data, point.x() + point.y()*13);
    if( val > 0 && val <= 12) {return false;}
    if( val >= 13 && val <= 40){ return true;}
    if( val >= 41 && val <= 100){ return false;}
    if( val >= 101 && val <= 200){ return false;}
    if( val >= 254 && val <= 255){ return true;}

    else return true;
}

void Braver::setPoint(QPoint sp)
{
    x[0] = sp.x(); y[0] = sp.y();
    x[4] = point.x(); y[4] = point.y();
    x[2] = (x[4]+x[0])/2; y[2] = (y[4]+y[0])/2;
    x[1] = (x[0]+x[2])/2; y[1] = (y[2]+y[0])/2;
    x[3] = (x[2]+x[4])/2; y[3] = (y[2]+y[4])/2;
}

void Braver::roleWalk()
{

    static int i = 1;
    QWidget* w = static_cast<QWidget*>(this->parent());
    int a = static_cast<int>(x[i]* w->width()/COL);
    int b = static_cast<int>(y[i]* w->width()/ROW);
    if(QPoint(static_cast<int>(x[0]), static_cast<int>(y[0])) !=
            QPoint(static_cast<int>(x[4]), static_cast<int>(y[4]))){
    QPoint rect = this->getRect();
    if(rect.x() == 96) rect.setX(0);
    else rect.setX( rect.x() +32);
    setPicture(rect);
    }
    this->move(a, b);
    this->show();
    QApplication::processEvents();//处理事件;防止假死
    if(i == 4) {i = 1; timer->stop();}
    else i++;

}

void Braver::keyhandle()
{
    if(timer->isActive()) return;
    QPoint sp = point;
    switch(key){
    case Qt::Key_Up :
        point.ry()--;
        setPicture(QPoint(0,96));
        break;
    case Qt::Key_Down :
        point.ry()++;
        setPicture(QPoint(0,0));
        break;
    case Qt::Key_Left :
        point.rx()--;
        setPicture(QPoint(0,32));
        break;
    case Qt::Key_Right :
        point.rx()++;
        setPicture(QPoint(0,64));
        break;
    default:
        return;
    }
    if(!pointJudge()){point = sp;}
    setPoint(sp);
    timer->start();
}

