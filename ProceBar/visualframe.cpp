#include "visualframe.h"
#include "ui_visualframe.h"

VisualFrame::VisualFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VisualFrame)
{
    ui->setupUi(this);
    initForms();
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->setWindowOpacity(1);//窗口透明子控件不透明
}

VisualFrame::~VisualFrame()
{
    for (int i = 0; i < 6; i++) {
        delete forms[i];
    }
    delete ui;
}

void VisualFrame::initForms()
{
    for (int i = 0; i < 6; ++i) {
        forms[i] = new PetForm(this);
        forms[i]->move(i*161,20);
    }
}
