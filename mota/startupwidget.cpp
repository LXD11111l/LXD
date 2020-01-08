#include "startupwidget.h"
#include "ui_startupwidget.h"
#include <QDebug>

StartupWidget::StartupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartupWidget)
{
    ui->setupUi(this);

    QPixmap pixmap = QPixmap::fromImage(QImage(":/picture/bg.png"));
    QPalette pal = palette();
    pal.setBrush(QPalette::Background, pixmap.scaled(this->size()));
    //pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x66));
    this->setPalette(pal);
    //this->setAttributte(Qt::WA_TranslucentBackground, true);
    ui->widget->setStyleSheet("background-color:rgba(0,0,0,180)");
    //setWindowFlags (Qt::CustomizeWindowHint);
    setWindowFlags (Qt::FramelessWindowHint);
    setWindowOpacity(0.7);//所有控件半透明
    swidget = this;
    this->setWindowFlag(Qt::WindowStaysOnTopHint);//窗口置顶
}

StartupWidget::~StartupWidget()
{
    swidget = nullptr;
    delete ui;
}

StartupWidget* StartupWidget::swidget = nullptr;

void StartupWidget::changeEvent(QEvent *e)
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

void StartupWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        StartPos = event->globalPos() - this->frameGeometry().topLeft();
        //qDebug()<< StartPos;
    }
}

void StartupWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPos;
    if(event->buttons()==Qt::LeftButton){
        EndPos = event->globalPos()- StartPos;
        this->move(EndPos);
    }
}

void StartupWidget::on_startlab_clicked()
{
    qDebug() << "start";
    if(w == nullptr) w = new Widget();
    w->show();
    this->hide();

}

void StartupWidget::on_loadlab_clicked()
{
    qDebug() << "load";
    if(w == nullptr) w = new Widget();
    w->show();
    this->hide();
    PacketWidget::initRead();
}

void StartupWidget::on_exitlab_clicked()
{
    qDebug() << "exit";
    QApplication::exit(0);
}

void StartupWidget::showEvent(QShowEvent*ev)
{
    if(w != nullptr) delete  w;
    w = nullptr;
    ev->accept();
}


