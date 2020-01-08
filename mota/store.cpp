#include "store.h"
#include "ui_store.h"
#include <QDebug>
#include "packetwidget.h"

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    Storeshow();
}

Store *Store::getInstance(QWidget *parent)
{
    if(instance == nullptr) instance = new Store(parent);
    return instance;
}

Store* Store:: instance = nullptr;

int Store::price = 25;

int Store::hp = 500;

int Store::at = 2;

int Store::df = 2;

Store::~Store()
{
    instance = nullptr;
    delete ui;
}

void Store::Storeshow()
{
    int x = static_cast<QWidget*>(this->parent())->width()/2 - this->size().width()/2;
    int y = static_cast<QWidget*>(this->parent())->height()/2 - this->size().height()/2;
    this->move(x, y);
    this->show();
}

void Store::selected()
{
    if(index == 1){
        ui->addHP->setFrameStyle(QFrame::Box);
        ui->addAT->setFrameStyle(QFrame::NoFrame);
        ui->addDF->setFrameStyle(QFrame::NoFrame);
        ui->Return->setFrameStyle(QFrame::NoFrame);
    }
    if(index == 2){
        ui->addHP->setFrameStyle(QFrame::NoFrame);
        ui->addAT->setFrameStyle(QFrame::Box);
        ui->addDF->setFrameStyle(QFrame::NoFrame);
        ui->Return->setFrameStyle(QFrame::NoFrame);
    }
    if(index == 3){
        ui->addHP->setFrameStyle(QFrame::NoFrame);
        ui->addAT->setFrameStyle(QFrame::NoFrame);
        ui->addDF->setFrameStyle(QFrame::Box);
        ui->Return->setFrameStyle(QFrame::NoFrame);
    }
    if(index == 4){
        ui->addHP->setFrameStyle(QFrame::NoFrame);
        ui->addAT->setFrameStyle(QFrame::NoFrame);
        ui->addDF->setFrameStyle(QFrame::NoFrame);
        ui->Return->setFrameStyle(QFrame::Box);
    }
}

void Store::changeEvent(QEvent *e)
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

void Store::keyPresshandle(int key)
{
    if(key == Qt::Key_Up){
        if(index == 1) index = 4;
        else index--;
    }
    else if(key == Qt::Key_Down){
        if(index == 4) index = 1;
        else index++;
    }
    else if(key == Qt::Key_Return){
        Comfirm();
    }
    selected();

}

void Store::Comfirm()
{
    PacketWidget* pWidget = PacketWidget::getInstance();
    if(index == 1){
        pWidget->addHp(hp);
        pWidget->addMoney(-price);
    }
    else if(index == 2){
        pWidget->addAt(at);
        pWidget->addMoney(-price);

    }
    else if(index == 3){
        pWidget->addDf(df);
        pWidget->addMoney(-price);
    }
    else if(index == 4){
        this->deleteLater();
    }
}
