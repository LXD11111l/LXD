#include "monstermanual.h"
#include "ui_monstermanual.h"
#include <QPixmap>
#include <QDebug>
#include "packetwidget.h"

MonsterManual::MonsterManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterManual)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(ui->frame_2);
    initMonsterdata();
    setPage();
    loadItem();
    this->resize(parent->size());
    this->show();
}

void MonsterManual::setActive(bool isactive)
{
    PacketWidget::getInstance()->addIco(":/picture/Icons/Item01-05_1_1.png", isactive, 1);
    isActive = isactive;
}

MonsterManual::~MonsterManual()
{
    //deletItem();
    //delete layout;
    instance = nullptr;
    delete ui;
}

MonsterManual* MonsterManual::instance = nullptr;
bool MonsterManual::isActive = false;

void MonsterManual::initMonsterdata()
{
    LabelFactory* factory = MainMapWidget::getInstance()->getFactory();
    unsigned char* data = MainMapWidget::getMapdata()->value(MainMapWidget::Floor);
    for (int i = 0; i < 169; ++i) {
        if(data[i] > 40 && data[i] < 101){
            monster.insert(data[i],factory->monsterdata[data[i] - 40]);
        }
    }
}

void MonsterManual::deletItem()
{
    for (int i = 0; i < 6; ++i) {
        if(items[i] != nullptr) delete items[i];
        items[i] = nullptr;
    }
    if(w != nullptr) delete w;
    w = nullptr;
}

void MonsterManual::setPage()
{
    int total = monster.size()/6;
    if(monster.size()%6 > 0) ++total;
    if(total == 0) ++total;
    ui->pagelab->setText(QString::number(index) + "/" + QString::number(total));
}

void MonsterManual::loadItem()
{
    deletItem();
    //qDebug() << "num=" << monster.size();
    int num = monster.size() - (index-1)*6;
    if(num > 6)  num = 6;
    LabelFactory* factory = MainMapWidget::getInstance()->getFactory();
    QList<int> key = monster.keys();
    for (int i = 0; i < 6; ++i) {
        if(i < num){
            int id = key[i + (index-1)*6];
            //qDebug() << "id=" << id;
            items[i] = new MonsterItem(this);
            items[i]->setAt(monster.value(id).at);
            items[i]->setDf(monster.value(id).df);
            items[i]->setHp(monster.value(id).hp);
            items[i]->setDf(monster.value(id).df);
            items[i]->setMo(monster.value(id).mo);
            items[i]->setName(monster.value(id).name);
            QPixmap pixmap = QPixmap::fromImage(QImage(factory->source[id]));
            pixmap = pixmap.copy(factory->rect[id].x(),factory->rect[id].y(),32,32);
            items[i]->setIco(pixmap);
            items[i]->show();
            layout->addWidget(items[i], Qt::AlignVCenter | Qt::AlignTop);
        }
        else items[i] = nullptr;
    }
    w = new QWidget(this);
    layout->addWidget(w,1);
}

void MonsterManual::changeEvent(QEvent *e)
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

void MonsterManual::on_prelab_clicked()
{
    if(index == 1) return;
    --index;
    setPage();
    loadItem();
}

void MonsterManual::on_nextlab_clicked()
{
    int total = monster.size()/6;
    if(monster.size()%6 > 0) ++total;
    if(index == total)return;
    ++index;
    setPage();
    loadItem();
}

void MonsterManual::on_relab_clicked()
{

    deleteLater();
}
