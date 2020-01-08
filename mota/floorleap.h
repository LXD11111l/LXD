#ifndef FLOORLEAP_H
#define FLOORLEAP_H

#include <QWidget>
#include "packetwidget.h"
#include "mainmapwidget.h"
#include <QDebug>

namespace Ui {
class FloorLeap;
}

class FloorLeap : public QWidget
{
    Q_OBJECT
private:
    Ui::FloorLeap *ui;
    explicit FloorLeap(QWidget *parent = nullptr);
    static FloorLeap* floorleap;

public:
    static bool isActive;
    static FloorLeap* getInstance(QWidget *parent = nullptr){
        if(floorleap == nullptr && isActive) {floorleap = new FloorLeap(parent);qDebug()<< floorleap;}
        return floorleap;
    }
    static FloorLeap* getFloorLeap(){return floorleap;}
    ~FloorLeap();
    static int hf;
    void showFloorLeap();
    int getCurrentfloor();
    static void setHf(int fn){ if(fn > hf) hf = fn;}
    static int getHf(){ return hf;}
    static void setActive(bool isactive);
    void keyPressHandle(int key);
protected:
    void changeEvent(QEvent *e);

private slots:
    void on_upbtn_clicked();

    void on_downbtn_clicked();

};

#endif // FLOORLEAP_H
