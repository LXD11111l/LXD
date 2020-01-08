#ifndef ROLELABLE_H
#define ROLELABLE_H

#include <QtCore/qglobal.h>
#include <QLabel>
#include <QPaintEvent>
#include <QTimer>
#include <QPoint>
#include <QString>


class RoleLable: public QLabel
{
public:
    QPoint point;//(0~12, 0~12);

    RoleLable(QWidget* parent = nullptr, QString pic = nullptr, QPoint p = QPoint(6, 11));
    RoleLable(const RoleLable& rolelable);
    inline void setPoint(QPoint p){ point = p;}
    inline QPoint getPoint()const{ return this->point;}
    void labelMove();
    inline void setPicSource(QString pic){ Picture = pic;}
    inline QString getPicSource()const {return this->Picture;}
    void setPicture(QPoint p);
    inline void setType(int id){type = id;}
    inline int getType()const{return this->type;}
    inline QPoint getRect()const {return this->rect;}
    void timeStart(int t = 60){time->start(t);}
private:
    QString Picture;
    int type;
    QPoint rect;
    QTimer* time;
    QTimer* _time;
public slots:
    void openDoor();
    void battle();
protected:

};

#endif // ROLELABLE_H
