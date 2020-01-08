#include "settingform.h"
#include "ui_settingform.h"
#include <QMessageBox>
#include "startupwidget.h"

SettingForm::SettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);
    setWindowOpacity(0.7);//所有控件半透明
    showForm();
}

SettingForm::~SettingForm()
{
    instance = nullptr;
    delete ui;
}

SettingForm* SettingForm::instance = nullptr;

void SettingForm::showForm()
{
    int x = static_cast<QWidget*>(this->parent())->width()/2 - this->size().width()/2;
    int y = static_cast<QWidget*>(this->parent())->height()/2 - this->size().height()/2;
    this->move(x, y);
    this->show();

}

void SettingForm::changeEvent(QEvent *e)
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

void SettingForm::on_regameLab_clicked()
{
    deleteLater();
}

void SettingForm::on_retitleLab_clicked()
{
    QMessageBox msgbox;
    msgbox.setText("确定返回标题页面？");
    msgbox.addButton(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::Cancel);
    int ret = msgbox.exec();
    if(ret == QMessageBox::Yes){
        StartupWidget::swidget->show();
    }else{
        deleteLater();
    }
}
