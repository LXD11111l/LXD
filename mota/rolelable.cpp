#include "rolelable.h"
#include "mainmapwidget.h"
#include <QPainter>
#include <QDebug>
#include <unistd.h>
#include <QApplication>

RoleLable::RoleLable(QWidget* parent, QString pic, QPoint p)
    :QLabel (parent), point(p), Picture(pic)
{
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    int _size = parent->size().height();
    this->setFixedSize(_size/COL, _size/ROW);
    this->setStyleSheet("border:0px solid red;");
    setPicture(QPoint(0,0));
    this->time = new QTimer(this);
    QObject::connect(time, &QTimer::timeout, this, &RoleLable::openDoor);
    this->labelMove();
}

RoleLable::RoleLable(const RoleLable &rolelable)
    :QLabel(static_cast<QWidget*>(rolelable.parent())), point(rolelable.point), Picture(rolelable.Picture)
{

}

void RoleLable::labelMove()
{
    QWidget* w = static_cast<QWidget*>(this->parent());
    this->move(point.x()* w->width()/COL, point.y()* w->height()/ROW);
}

void RoleLable::setPicture(QPoint p)
{
    this->rect = p;
    QPixmap pixmap = QPixmap::fromImage(QImage(Picture).copy(p.x(),p.y(),32,32));
    this->setPixmap(pixmap.scaled(this->width(),this->height()));
}

void RoleLable::openDoor()
{
    if(type > 0 && type < 13){
        QPoint p = rect;
        if(p.y() == 96){
            time->stop();
            deleteLater();
        }
        else{
            p.setY(p.y() + 32);
            setPicture(p);
        }
    }
    if(type == 220){
        QPoint p = rect;
        if(p.x() == 128){
            time->stop();
            deleteLater();
        }
        else{
            p.setX(p.x() + 32);
            setPicture(p);
        }
    }
}


