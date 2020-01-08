#include "packetwidget.h"
#include "ui_packetwidget.h"
#include "floorleap.h"
#include "monstermanual.h"
#include "settingform.h"
#include <QDebug>
#include "fileform.h"
#include "dialogwidget.h"
#include "store.h"

PacketWidget::PacketWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PacketWidget)
{
    ui->setupUi(this);
    addIco(":/picture/Icons/Item01-05_1_1.png", false, 1);
    addIco(":/picture/Icons/Item01-05_1_3.png", false, 2);
    addIco(":/picture/tools.png", true, 3);
    addIco(":/picture/save.png", true, 4);
    addIco(":/picture/read.png", true, 5);
    addIco(":/picture/set.png", true, 6);
    instance = this;
}

PacketWidget* PacketWidget:: instance = nullptr;

PacketWidget::~PacketWidget()
{
    instance = nullptr;
    delete ui;
}

int PacketWidget::getCurrentFloor()const
{
    return ui->floorlab->text().toInt();
}

void PacketWidget::setFloor(int fn)
{
    this->ui->floorlab->setNum(fn);
}

int PacketWidget::getHp() const
{
    return  ui->energylabel->text().toInt();
}

void PacketWidget::addHp(int hp)
{
    int num = getHp();
    ui->energylabel->setNum(num + hp);
}

int PacketWidget::getAt() const
{
    return ui->atklabel->text().toInt();
}

void PacketWidget::addAt(int at)
{
    int num = getAt();
    ui->atklabel->setNum(num + at);
}

int PacketWidget::getDf() const
{
    return ui->deflabel->text().toInt();
}

void PacketWidget::addDf(int df)
{
    int num = getDf();
    ui->deflabel->setNum(num + df);
}

int PacketWidget::getMoney() const
{
    return ui->moneylabel->text().toInt();
}

void PacketWidget::addMoney(int mo)
{
    int num = getMoney();
    if(num + mo < 0) return;
    ui->moneylabel->setNum(num + mo);
}

int PacketWidget::getYellowKey() const
{
    return ui->yellowKeylabel->text().toInt();
}

void PacketWidget::addYellowKey(int yk)
{
    int num = getYellowKey();
    if(num + yk < 0) return;
    ui->yellowKeylabel->setNum(num + yk);
}

int PacketWidget::getBlueKey() const
{
    return ui->blueKeylabel->text().toInt();
}

void PacketWidget::addBlueKey(int bk)
{
    int num = getBlueKey();
    if(num + bk < 0) return;
    ui->blueKeylabel->setNum(num + bk);
}

int PacketWidget::getRedKey() const
{
    return ui->redKeylabel->text().toInt();
}

void PacketWidget::addRedKey(int rk)
{
    int num = getRedKey();
    if(num + rk < 0) return;
    ui->redKeylabel->setNum(num + rk);
}

void PacketWidget::addIco(QString ico, bool isactive, int i)
{
    QImage image = QImage(ico);
    if(isactive == false) image = toMonochrome(image);
    QPixmap pixmap = QPixmap::fromImage(image).scaled(40,40);
    QLabel* lab;
    if(i == 1)lab = ui->manualLab;
    else if(i == 2)lab = ui->floorLab;
    else if(i == 3)lab = ui->toolLab;
    else if(i == 4)lab = ui->saveLab;
    else if(i == 5)lab = ui->readLab;
    else if(i == 6)lab = ui->setLab;
    else return;
    lab->setPixmap(pixmap);
}

QImage PacketWidget::toMonochrome(QImage image)
{
    int x = image.size().width();
    int y = image.size().height();
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            QColor col = image.pixelColor(j, i);
            int r = col.red();
            int g = col.green();
            int b = col.blue();
            int a = col.alpha();
            int ave = static_cast<int>((r + g + b)/3);
            image.setPixelColor(j,i,QColor(ave,ave,ave,a));
        }
    }
    return image;
}

void PacketWidget::initFloorLeap()
{
    if(FileForm::getFileForm() != nullptr) return;
    if(MonsterManual::getMonsterManual() != nullptr) return;
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(SettingForm::getSettingForm() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    qDebug()<< "2222";
    FloorLeap* floorleap = FloorLeap::getFloorLeap();
    if(floorleap == nullptr){
        qDebug()<< "3333";
        FloorLeap::getInstance(MainMapWidget::getInstance());
    }else{
        delete floorleap;
    }
}

void PacketWidget::initManual()
{
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(SettingForm::getSettingForm() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;
    if(FileForm::getFileForm() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    if(MonsterManual::getMonsterManual() == nullptr)
        MonsterManual::getInstance(MainMapWidget::getInstance());
    else{
        delete MonsterManual::getMonsterManual();
    }
}

void PacketWidget::initSetting()
{
    if(FileForm::getFileForm() != nullptr) return;
    if(MonsterManual::getMonsterManual() != nullptr) return;
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    if(SettingForm::getSettingForm() == nullptr)
        SettingForm::getInstance(MainMapWidget::getInstance());
    else{
        delete SettingForm::getSettingForm();
    }
}

void PacketWidget::initSave()
{
    if(MonsterManual::getMonsterManual() != nullptr) return;
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(SettingForm::getSettingForm() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    if(FileForm::getFileForm() == nullptr){
        FileForm::getInstance(MainMapWidget::getInstance(),true);
    }else{
        delete FileForm::getFileForm();
    }
}

void PacketWidget::initRead()
{
    if(MonsterManual::getMonsterManual() != nullptr) return;
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(SettingForm::getSettingForm() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    if(FileForm::getFileForm() == nullptr){
        FileForm::getInstance(MainMapWidget::getInstance(),false);
    }else{
        delete FileForm::getFileForm();
    }
}

void PacketWidget::initStore()
{
    if(MonsterManual::getMonsterManual() != nullptr) return;
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(SettingForm::getSettingForm() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;
    if(FileForm::getFileForm() != nullptr) return;
    if(Store::getStore() == nullptr){
        Store::getInstance(MainMapWidget::getInstance());
    }else{
        delete Store::getStore();
    }
}

void PacketWidget::changeEvent(QEvent *e)
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

void PacketWidget::on_floorLab_clicked()
{
    initFloorLeap();
}

void PacketWidget::on_manualLab_clicked()
{
    initManual();
}

void PacketWidget::on_setLab_clicked()
{
    initSetting();
}

void PacketWidget::on_saveLab_clicked()
{
    initSave();
}

void PacketWidget::on_readLab_clicked()
{
    initRead();
}
