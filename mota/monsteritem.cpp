#include "monsteritem.h"
#include "ui_monsteritem.h"

MonsterItem::MonsterItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterItem)
{
    ui->setupUi(this);
}

MonsterItem::~MonsterItem()
{
    delete ui;
}

void MonsterItem::setIco(QPixmap ico)
{
    ui->icolab->setPixmap(ico.scaled(ui->icolab->size()));
}

void MonsterItem::setName(QString name)
{
    ui->namelab->setText(name);
}

void MonsterItem::setAt(int at)
{
    QString text = "攻击：" + QString::number(at);
    ui->atlab->setText(text);
}

void MonsterItem::setDf(int df)
{
    QString text = "防御：" + QString::number(df);
    ui->dflab->setText(text);
}

void MonsterItem::setHp(int hp)
{
    QString text = "生命：" + QString::number(hp);
    ui->hplab->setText(text);
}

void MonsterItem::setMo(int mo)
{
    QString text = "金钱：" + QString::number(mo);
    ui->molab->setText(text);
}

void MonsterItem::setDam(int dam)
{
    QString text = "伤害：" + QString::number(dam);
    ui->damlab->setText(text);
}

void MonsterItem::changeEvent(QEvent *e)
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
