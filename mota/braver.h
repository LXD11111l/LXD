#ifndef BRAVER_H
#define BRAVER_H

#include <QtCore/qglobal.h>
#include "rolelable.h"
#include "mainmapwidget.h"

class Braver : public RoleLable
{
public:

private:
    QTimer* timer;
    QTimer* time;
    Braver(RoleLable base);
    static Braver* instance;
    double x[5];
    double y[5];
    int key = 0;
    int path = 0;
public:
    static Braver* getInstance(RoleLable base){
        if (instance == nullptr) instance = new Braver(base);
        return instance;
    }
    static Braver* getBraver(){ return instance;}
    ~Braver();
    bool pointJudge();
    void setPoint(QPoint sp);
    inline void setKey(int k){ key = k;}

public slots:
    void roleWalk();
    void keyhandle();
};

#endif // BRAVER_H
