#ifndef PACKETWIDGET_H
#define PACKETWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include "mainmapwidget.h"

namespace Ui {
class PacketWidget;
}

class PacketWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::PacketWidget *ui;
    explicit PacketWidget(QWidget *parent = nullptr);
    static PacketWidget* instance;
    //bool isActive[8] = {0,0,0,1,1,1,0,0};
public:
    static PacketWidget* getInstance(QWidget *parent = nullptr){
        if(instance == nullptr) instance = new PacketWidget(parent);
        return instance;
    }
    ~PacketWidget();

    int  getCurrentFloor()const;
    void setFloor(int fn);
    int  getHp()const;
    void addHp(int hp);
    int  getAt()const;
    void addAt(int at);
    int  getDf()const;
    void addDf(int df);
    int  getMoney()const;
    void addMoney(int mo);
    int  getYellowKey()const;
    void addYellowKey(int yk);
    int  getBlueKey()const;
    void addBlueKey(int bk);
    int  getRedKey()const;
    void addRedKey(int rk);
    void addIco(QString ico, bool isactive, int i);
    QImage toMonochrome(QImage image);
    static void initFloorLeap();
    static void initManual();
    static void initSetting();
    static void initSave();
    static void initRead();
    static void initStore();

protected:
    void changeEvent(QEvent *e);


private slots:
    void on_floorLab_clicked();
    void on_manualLab_clicked();
    void on_setLab_clicked();
    void on_saveLab_clicked();
    void on_readLab_clicked();
};

#endif // PACKETWIDGET_H
