#include "labelmanager.h"
#include "mainmapwidget.h"
#include "packetwidget.h"
#include <QDebug>
#include "braver.h"
#include "floorleap.h"
#include "monstermanual.h"
#include "dialogwidget.h"

LabelManager::LabelManager()
{

}

void LabelManager::Manager(unsigned char* data, int i)
{
    PacketWidget* pwidget = PacketWidget::getInstance();
    MainMapWidget* mainmap = MainMapWidget::getInstance();
    QMap<int, RoleLable*>* labeldata = MainMapWidget::getLabeldata();
    RoleLable* label = labeldata->value(i);
    int currentfloor = pwidget->getCurrentFloor();
    if(data[i] >= 13 && data[i] <= 40){
        if(data[i] == 13) pwidget->addYellowKey(1);
        if(data[i] == 14) pwidget->addBlueKey(1);
        if(data[i] == 15) pwidget->addRedKey(1);
        if(data[i] == 17) MonsterManual::setActive(true);
        if(data[i] == 19) FloorLeap::setActive(true);
        if(data[i] == 20) pwidget->addMoney(100);
        if(data[i] == 25) pwidget->addAt(1);
        if(data[i] == 26) pwidget->addDf(1);
        if(data[i] == 28) {pwidget->addAt(1); pwidget->addDf(1);}
        if(data[i] == 29) pwidget->addHp(100);
        if(data[i] == 30) pwidget->addHp(200);
        if(data[i] == 31) pwidget->addHp(400);
        if(data[i] == 32) pwidget->addHp(800);
        if(data[i] == 37) pwidget->addAt(10);
        if(data[i] == 38) pwidget->addAt(30);
        if(data[i] == 39) pwidget->addDf(10);
        if(data[i] == 40) pwidget->addDf(30);
        delete label;
        data[i] = 0;
        labeldata->insert(i, nullptr);
    }
    if(data[i] == 1 && pwidget->getYellowKey()>0){
        pwidget->addYellowKey(-1);
        label->timeStart();
        data[i] = 0;
        labeldata->insert(i, nullptr);
    }
    if(data[i] == 2 && pwidget->getBlueKey()>0){
        pwidget->addBlueKey(-1);
        label->timeStart();
        data[i] = 0;
        labeldata->insert(i, nullptr);
    }
    if(data[i] == 3 && pwidget->getRedKey()>0){
        pwidget->addRedKey(-1);
        label->timeStart();
        data[i] = 0;
        labeldata->insert(i, nullptr);
    }
    if(data[i] == 101){
        if(pwidget->getCurrentFloor() == 1){
            DialogWidget* dialogWidget = DialogWidget::getInstance(mainmap);
            dialogWidget->setText(":/picture/Battlers/NPC01-06_1_1.png",
                                  "老人：","我这里有一本怪物手册，希望对你有帮助！");
            MonsterManual::setActive(true);
            Braver::getBraver()->setKey(0);
        }
        //delete label;
        //data[i] = 0;
        //labeldata->insert(i, nullptr);
    }
    if(data[i] == 254){
        mainmap->loadMap(currentfloor - 1);
    }
    if(data[i] == 255){
        mainmap->loadMap(currentfloor + 1);
    }
    if(data[i] >40 && data[i]<101){
        label->setPicSource(":/picture/Sword466RPG.png");
        label->setType(220);
        label->setPicture(QPoint(0,32));
        label->timeStart(25);
        data[i] = 0;
        labeldata->insert(i, nullptr);
    }
}
