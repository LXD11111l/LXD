#include "floorleap.h"
#include "ui_floorleap.h"
#include <QDebug>

FloorLeap::FloorLeap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloorLeap)
{
    ui->setupUi(this);
    showFloorLeap();
}

FloorLeap* FloorLeap::floorleap = nullptr;

int FloorLeap::hf = 0;

bool FloorLeap::isActive = false;

FloorLeap::~FloorLeap()
{
    floorleap  = nullptr;
    qDebug()<< "delete";
    delete ui;
}

void FloorLeap::showFloorLeap()
{

    int x = static_cast<QWidget*>(this->parent())->width()/2 - this->size().width()/2;
    int y = static_cast<QWidget*>(this->parent())->height()/2 - this->size().height()/2;
    move(x, y);
    int currentfloor = PacketWidget::getInstance()->getCurrentFloor();
    ui->label->setText("第"+ QString::number(currentfloor) +"层");
    show();
    qDebug()<< "show";
}

int FloorLeap::getCurrentfloor()
{
    return ui->label->text().chopped(1).remove(0,1).toInt();
}

void FloorLeap::setActive(bool isactive)
{
    PacketWidget::getInstance()->addIco(":/picture/Icons/Item01-05_1_3.png", isactive, 2);
    isActive = isactive;
}

void FloorLeap::keyPressHandle(int key)
{
    if(key == Qt::Key_Return || key == Qt::Key_Enter){
        MainMapWidget::getInstance()->loadMap(getCurrentfloor());
        deleteLater();
    }

}

void FloorLeap::changeEvent(QEvent *e)
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

void FloorLeap::on_upbtn_clicked()
{
    int fn = getCurrentfloor();
    if(fn == hf)return;
    ui->label->setText("第"+ QString::number(++fn) +"层");
}

void FloorLeap::on_downbtn_clicked()
{
    int fn = getCurrentfloor();
    if(fn == 0)return;
    ui->label->setText("第"+ QString::number(--fn) +"层");
}
