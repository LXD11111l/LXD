#ifndef LABELFACTORY_H
#define LABELFACTORY_H

#include <QtCore/qglobal.h>
#include <QPoint>
#include "rolelable.h"
#include <QWidget>

typedef struct Monster{
    int at = 0;
    int df = 0;
    int hp = 0;
    int mo = 0;
    QString name = "野怪";
}MON;

class LabelFactory
{
public:
    LabelFactory();
    RoleLable* creatLabel(QWidget* parent, int id, QPoint p);
    MON monsterdata[60] = {};
    QPoint rect[256] = {QPoint(0,0)};
    QString  source[256] = {""};
private:

};

#endif // LABELFACTORY_H
