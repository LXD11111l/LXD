#include "widget.h"
#include "ui_widget.h"
#include <QProgressBar>
#include <probar.h>
#include <QRgb>
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setAlignment(Qt::AlignCenter);
    ui->progressBar->setStyleSheet("border-radius:10px;");
    ui->progressBar->setFont(QFont("微软雅黑",16,75,true));
    ui->progressBar->setPalette(QColor(QColor::fromRgb(0,0,255)));
    //bar = new Probar(this);
    //bar->setGeometry(30,30,400,20);
    bar = ui->widget;
    ui->label_2->setBubleText("-1");
    QString t2 = QString::fromStdString("用Qt实现客户端服务器的搭建，内容包括用户登录注册、客户端界面设计、房间创建、音视频直播、在线用户之间群聊以及私聊等。用户登录后，可在主界面创建房间，同时刷新所有在线用户列表和房间，通过点击可进入房间，可观看主播直可以在直播房间内给主播赠送礼物以及发送弹幕");
    ui->label_3->setBubleText(t2);
    //box = new BubleBox;
    //box->show();
    form = new PetForm(this);
    form->move(20,20);

}

Widget::~Widget()
{
    delete form;
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(QPen(QColor(11,67,127),3));

    QRectF rect(340.0, 340.0, 100.0, 100.0);

    painter.setRenderHint(QPainter:: Antialiasing, true);  //设置渲染,启动反锯齿

    painter.drawPie(rect,30*16,150*16); //绘画角度为30°~(30+150°)
}

void Widget::on_pushButton_clicked()
{
    bar->setMaxSize(200);
    bar->setColor("rgb(255,255,0)");
    bar->setTextColor(QColor(240,240,0),QColor(0,0,255));
    bar->setFont(QFont("黑体",9,75,false));

    bar->setCurrentSize(150);
    //box->setText("aaaaaaaaaaaaaaaaaaaaaaa");
}

void Widget::on_pushButton_2_clicked()
{
    bar->setMaxSize(200);
    bar->setColor("rgb(255,0,0)");
    bar->setTextColor(QColor(240,240,0),QColor(0,255,0));
    bar->setFont(QFont("微软雅黑",9,75,true));
    bar->setCurrentSize(0);
}

void Widget::on_label_2_doubleclicked()
{
    ui->label_2->setBuble();
}


