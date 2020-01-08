#include "mainmapwidget.h"
#include <QDebug>
#include "packetwidget.h"
#include "floorleap.h"
#include "braver.h"

MainMapWidget::MainMapWidget(QWidget *parent)
    : QLabel(parent)
{
    QPixmap pixmap = QPixmap::fromImage(QImage(":/picture/Mota.png").copy(96,32,32,32));
    QPalette pal;
    pal.setBrush(QPalette::Background, pixmap.scaled(WID/COL, HEI/ROW));
    this->setPalette(pal);
    this->setAutoFillBackground(true);
    this->setFixedSize(WID, HEI);
    //this->setStyleSheet("background-image: url(:/picture/floor.png);");
    //this->setPixmap(pixmap.scaled());
    factory = new LabelFactory();
    Mapdata = new QMap<int, unsigned char*>();
    labeldata = new QMap<int, RoleLable*>();
    timer = new QTimer(this);
    timer->start(160);
    QObject::connect(timer, &QTimer::timeout, this, &MainMapWidget::animate);
}

MainMapWidget::~MainMapWidget()
{
    for (int i = 0; i < Mapdata->size(); ++i) {
        delete [] Mapdata->value(i);
    }
    delete factory;
    deleteLabeldata();
    delete Mapdata;
    delete labeldata;
    delete frame;
    instance = nullptr;
}

QMap<int, unsigned char*>* MainMapWidget::Mapdata = nullptr;

QMap<int, RoleLable*>* MainMapWidget::labeldata = nullptr;

int MainMapWidget::Floor = 0;

MainMapWidget* MainMapWidget::instance = nullptr;

void MainMapWidget::initFloor()
{
    unsigned char F0[169] = {
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,101,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,6,
        6  ,0  ,0  ,0  ,0  ,0  ,255,0  ,0  ,0  ,0  ,0  ,6,
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6
    };
    unsigned char F1[169] = {
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6,
        6  ,255,42 ,41 ,41 ,0  ,6  ,25 ,50 ,1  ,0  ,29 ,6,
        6  ,6  ,6  ,6  ,6  ,0  ,6  ,49 ,0  ,6  ,13 ,26 ,6,
        6  ,29 ,0  ,49 ,1  ,0  ,6  ,0  ,0  ,6  ,6  ,1  ,6,
        6  ,13 ,0  ,0  ,6  ,0  ,6  ,57 ,45 ,6  ,0  ,45 ,6,
        6  ,6  ,1  ,6  ,6  ,0  ,6  ,1  ,6  ,6  ,25 ,13 ,6,
        6  ,13 ,0  ,29 ,6  ,0  ,0  ,45 ,101,6  ,6  ,6  ,6,
        6  ,0  ,49 ,0  ,6  ,0  ,41 ,0  ,42 ,1  ,0  ,57 ,6,
        6  ,6  ,1  ,6  ,6  ,0  ,0  ,26 ,6  ,6  ,2  ,6  ,6,
        6  ,0  ,50 ,0  ,6  ,6  ,1  ,6  ,6  ,41 ,45 ,41 ,6,
        6  ,13 ,25 ,13 ,6  ,14 ,0  ,15 ,6  ,13 ,30 ,13 ,6,
        6  ,29 ,19 ,30 ,6  ,13 ,254,13 ,6  ,25 ,30 ,26 ,6,
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6
    };
    unsigned char F2[169] = {
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6,
        6  ,254,0  ,45 ,41 ,0  ,0  ,0  ,6  ,0  ,0  ,29 ,6,
        6  ,6  ,6  ,6  ,6  ,0  ,0  ,42 ,1  ,57 ,13 ,26 ,6,
        6  ,29 ,0  ,50 ,1  ,0  ,60  ,0  ,6  ,0  ,0  ,0  ,6,
        6  ,13 ,0  ,0  ,6  ,0  ,45 ,0  ,6  ,6  ,6  ,1  ,6,
        6  ,6  ,1  ,6  ,6  ,6  ,1  ,6  ,6  ,0  ,25 ,49 ,6,
        6  ,13 ,0  ,29 ,1  ,0  ,0  ,0  ,1  ,45 ,0  ,0  ,6,
        6  ,0  ,49 ,0  ,6  ,0  ,255,0  ,6  ,0  ,0  ,57 ,6,
        6  ,6  ,2  ,6  ,6  ,13 ,0  ,50 ,6  ,6  ,1  ,6  ,6,
        6  ,0  ,0  ,0  ,6  ,6  ,6  ,6  ,6  ,0  ,57 ,0  ,6,
        6  ,49 ,50 ,49 ,6  ,13 ,57 ,0  ,6  ,13 ,0  ,13 ,6,
        6  ,25 ,30 ,26 ,6  ,14 ,57 ,0  ,1  ,29 ,26 ,29 ,6,
        6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6  ,6
    };
    unsigned char* f0 = new unsigned char[169];
    unsigned char* f1 = new unsigned char[169];
    unsigned char* f2 = new unsigned char[169];

    memcpy(f0,F0,169);
    memcpy(f1,F1,169);
    memcpy(f2,F2,169);

    Mapdata->insert(0, f0);
    Mapdata->insert(1, f1);
    Mapdata->insert(2, f2);

}

void MainMapWidget::loadMap(int floor)
{
    if(floor > Mapdata->size() - 1 || floor < 0) return;
    int currentfloor = PacketWidget::getInstance()->getCurrentFloor();
    Braver* braver = Braver::getBraver();
    deleteLabeldata();
    PacketWidget::getInstance()->setFloor(floor);
    unsigned char* fn = Mapdata->value(floor);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            unsigned char val = fn[13*i + j];
            RoleLable* label = nullptr;
            if(val != 0) {
                label = factory->creatLabel(this, val, QPoint(j,i));
                label ->show();
            }
            if(currentfloor < floor && val == 254){//上楼
                    braver->point = QPoint(j, i);
                    braver->labelMove();
            }else if(currentfloor > floor && val == 255){//下楼
                    braver->point = QPoint(j, i);
                    braver->labelMove();
            }
            labeldata->insert(13*i + j, label);
        }
    }
    initFrame();
    FloorLeap::setHf(floor);
    if(braver != nullptr) braver->raise();
    Floor = floor;
}

void MainMapWidget::deleteLabeldata()
{
    for (int i = 0; i < labeldata->size(); ++i) {
        if(labeldata->value(i) != nullptr)
            delete labeldata->value(i);
    }
    labeldata->clear();
}

void MainMapWidget::initFrame()
{
    if(frame != nullptr) delete frame;
    frame = new QLabel(this);
    frame->setStyleSheet("background:transparent;color:rgb(255, 255, 255);");
    frame->setFixedSize(this->size());
    //frame->setFrameStyle(QFrame::Box);
    frame->setFrameShape(QFrame::Box);
    frame->setLineWidth(5);
    //frame->setStyleSheet("border:4px solid white;background:transparent;");
    frame->show();
}

void MainMapWidget::animate()
{
    for (int i = 0; i < labeldata->size(); ++i) {
        if(labeldata->value(i) != nullptr){
            int type = labeldata->value(i)->getType();
            if(type > 40 && type <= 200){
                QPoint rect = labeldata->value(i)->getRect();
                if(rect.x() == 96) rect.setX(0);
                else{rect.setX( rect.x() +32);}
                labeldata->value(i)->setPicture(rect);
            }
        }
    }
}


