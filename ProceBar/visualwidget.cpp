#include "visualwidget.h"
#include "ui_visualwidget.h"
#include <QDebug>
VisualWidget::VisualWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualWidget)
{
    ui->setupUi(this);
    this->setWindowOpacity(1);//窗口透明子控件不透明
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    //this->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initForms();
}

VisualWidget::~VisualWidget()
{
    for (int i = 0; i < 6; i++) {
        delete forms[i];
        qDebug()<<i;
    }
    delete ui;
}

void VisualWidget::initForms()
{
    for (int i = 0; i < 6; ++i) {
        forms[i] = new PetForm(this);
        forms[i]->move(i*161,20);
    }
}

void VisualWidget::on_closebtn_clicked()
{
    deleteLater();
    //close();
    //this->destroy();
}

void VisualWidget::on_closebtn_2_clicked()
{
    this->hide();
}
