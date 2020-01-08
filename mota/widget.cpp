#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QImage>
#include <QHBoxLayout>
#include "monstermanual.h"
#include "fileform.h"
#include "settingform.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initPacketWidget();//初始化属性面板
    initMap();//初始化主地图
    initMainRole( ":/picture/Characters/002-Braver01.png", QPoint(6,1));//初始化主角
    //initDialogWidget(":/picture/Battlers/NPC01-06_1_1.png","魔塔：","欢迎来到魔塔！");
    this->setWindowFlag(Qt::WindowStaysOnTopHint);//窗口置顶
    Layout();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initMap()
{
    mainMap = MainMapWidget::getInstance();
    mainMap->initFloor();
    mainMap->loadMap(0);
}

void Widget::initMainRole(QString picsource, QPoint p)
{
    Braver:: getInstance(RoleLable(mainMap, picsource, p));
}

void Widget::initStore()
{
    Store* store = Store::getInstance(mainMap);
    store->setStyleSheet("background-color: rgb(102, 102, 102);");
}

void Widget::initPacketWidget()
{
    pWidget = PacketWidget:: getInstance(this);
}

void Widget::initDialogWidget(QString ico, QString role,QString text)
{
    DialogWidget* dialogWidget = DialogWidget::getInstance(mainMap);
    dialogWidget->setText(ico, role, text);
}

void Widget::Layout()
{
   QHBoxLayout* layout = new QHBoxLayout(this);
   layout->addWidget(pWidget);
   layout->addWidget(mainMap);
   layout->setSpacing(0);
   layout->setMargin(40);
   this->setFixedHeight(80 + mainMap->size().height());
   this->setFixedWidth(80 + pWidget->size().width());
}

void Widget::changeEvent(QEvent *e)
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

void Widget::resizeEvent(QResizeEvent *event)
{
    int size = this->height();
    this->setFixedWidth(12*size/9);
    int _size = mainMap->size().height();
    mainMap->setFixedWidth(_size);
    pWidget->setFixedHeight(_size);
    pWidget->setFixedWidth(2*_size/5);

    event->accept();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),QImage(":/picture/background.png"),QRect());
    event->accept();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if(key == Qt::Key_Shift){PacketWidget:: initStore();}
    if(key == Qt::Key_PageUp){qDebug() << event;PacketWidget::initFloorLeap();}
    if(key == Qt::Key_Home){PacketWidget::initSetting();}
    if(key == Qt::Key_S){PacketWidget::initSave();}
    if(key == Qt::Key_A){PacketWidget::initRead();}
    if(key == Qt::Key_M){PacketWidget::initManual();}

    Store* store = Store::getStore();
    FloorLeap* floorleap = FloorLeap::getFloorLeap();
    DialogWidget* dialog = DialogWidget::getDialogWidget();
    FileForm* fileform = FileForm::getFileForm();
    SettingForm* setting = SettingForm::getSettingForm();
    MonsterManual* manual = MonsterManual::getMonsterManual();
    if(dialog != nullptr){dialog->keyPressHandle(key); return;}
    if(store != nullptr){store->keyPresshandle(key); return;}
    if(floorleap != nullptr){floorleap->keyPressHandle(key);return;}
    if(fileform != nullptr){ return;}
    if(setting != nullptr){ return;}
    if(manual != nullptr){ return;}

    Braver::getBraver()->setKey(key);
    event->accept();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(DialogWidget::getDialogWidget() != nullptr) return;
    if(Store::getStore() != nullptr) return;
    if(FloorLeap::getFloorLeap() != nullptr) return;

    Braver::getBraver()->setKey(0);
    event->accept();
}



