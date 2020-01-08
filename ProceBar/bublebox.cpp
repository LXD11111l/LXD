#include "bublebox.h"
#include "ui_bublebox.h"
#include <QDebug>

BubleBox::BubleBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BubleBox)
{
    ui->setupUi(this);
    this->setWindowOpacity(1);//窗口透明子控件不透明
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    //this->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    this->setAttribute(Qt::WA_TranslucentBackground);
    label = new TLabel(ui->frame);
    label->setFont(QFont("微软雅黑",9,75,false));
    label->setStyleSheet("border-image: url();"
                         "border-radius:5px;"
                         "line-height:100%;"
                         "background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:1,y2:0,stop:0 rgba(150,52,255,75%),stop:0.4 rgba(75,101,255,10%),stop:0.6 rgba(75,101,255,10%),stop:1 rgba(0,150,255,75%));"
                         "color:rgb(240,240,250);");
    layout = new QVBoxLayout(ui->frame);
    layout->addWidget(label,1);

}

BubleBox::~BubleBox()
{
    delete label;
    delete layout;
    delete ui;
}

void BubleBox::setText(QString text)
{
    int num = text.size();
    if(num > 9){
        label->setFixedWidth(125);
        label->setFixedHeight((num/10 + 1)*16);
    }
    else {
        label->setFixedSize(16*num,18);
    }
    label->setText(text);
}

void BubleBox::changeEvent(QEvent *e)
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
