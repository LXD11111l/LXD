#include "petform.h"
#include "ui_petform.h"

PetForm::PetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetForm)
{
    ui->setupUi(this);
    effect_init();
    ++count;
    ui->name->setText("宠【"+QString::number(count)+"】");
}
int PetForm::count = 0;
PetForm::~PetForm()
{
    delete[] w_shadow;
    delete ui;
}

void PetForm::effect_init()
{
    w_shadow = new QGraphicsDropShadowEffect[9];
    for (int i = 0 ; i<9;++i) {
        w_shadow[i].setParent(this);
        w_shadow[i].setOffset(QPointF(2,2));
        if(i==6)w_shadow[i].setBlurRadius(4);
        else w_shadow[i].setBlurRadius(8);
        if(i<6) w_shadow[i].setColor(QColor(0, 0,255));
        if(i==6)w_shadow[i].setColor(QColor(Qt::black));
        if(i==7)w_shadow[i].setColor(QColor(255,0,255));
        if(i==8)w_shadow[i].setColor(QColor(0,200,50));
    }

    ui->skill_1->setGraphicsEffect(&w_shadow[0]);
    ui->skill_2->setGraphicsEffect(&w_shadow[1]);
    ui->skill_3->setGraphicsEffect(&w_shadow[2]);
    ui->skill_4->setGraphicsEffect(&w_shadow[3]);
    ui->name->setGraphicsEffect(&w_shadow[4]);
    ui->name->setborderCol(QColor(0, 110, 222));
    ui->level->setGraphicsEffect(&w_shadow[5]);
    ui->level->setborderCol(QColor(0, 110, 222));
    ui->Hint->setGraphicsEffect(&w_shadow[6]);
    ui->Intimacy->setGraphicsEffect(&w_shadow[7]);
    ui->Intimacy->setborderCol(QColor(255, 0, 255));

}

void PetForm::changeEvent(QEvent *e)
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

void PetForm::on_skill_1_clicked()
{
    ui->hp->setMaxSize(100);
    //ui->skill_1->setText("一二三四:22");
    ui->skill_1->setborderCol(QColor(80,20,255));
    ui->skill_1->setBubleText("必中，踏云逐月般的攻击，当自身处于劣势时会提升技能威力。攻击后清除对方的强化，若清除失败则追加一段同等伤害，若清除成功，则回复自身等于伤害值的血量。洛克最强晨院长，有意向者请加QQ:1355038299。");
    ui->skill_1->setBuble();
    ui->hp->setCurrentSize(100);
}

void PetForm::on_skill_2_clicked()
{
    ui->hp->setCurrentSize(4);
}
