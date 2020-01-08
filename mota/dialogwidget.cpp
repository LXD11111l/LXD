#include "dialogwidget.h"
#include "ui_dialogwidget.h"

DialogWidget::DialogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogWidget)
{
    ui->setupUi(this);
    ui->textlab->adjustSize();
    ui->textlab->setGeometry(QRect(328, 240, 300, 27*4));  //四倍行距
    ui->textlab->setWordWrap(true);
    ui->textlab->setAlignment(Qt::AlignTop);
    showDialog();
}

DialogWidget* DialogWidget::instance = nullptr;

DialogWidget::~DialogWidget()
{
    instance = nullptr;
    delete ui;
}

void DialogWidget::showDialog()
{
    int x = static_cast<QWidget*>(this->parent())->width()/2 - this->size().width()/2;
    int y = static_cast<QWidget*>(this->parent())->height()/2 - this->size().height()/2;
    this->move(x, y);
    this->show();
}

void DialogWidget::setText(QString ico, QString role, QString text)
{
    this->ui->textlab->setText(text);
    ui->rolelab->setText(role);
    QPixmap pixmap = QPixmap::fromImage(QImage(ico));
    ui->icolab->setPixmap(pixmap.scaled(ui->icolab->width(),ui->icolab->height()));
}

void DialogWidget::keyPressHandle(int key)
{
    if(instance != nullptr){
        if(key == Qt::Key_Return || key == Qt::Key_Enter){deleteLater();}
        return;
    }
}

void DialogWidget::changeEvent(QEvent *e)
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
