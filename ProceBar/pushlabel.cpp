#include "pushlabel.h"
#include <QDebug>
#include <QPainter>
#include <QApplication>
PushLabel::PushLabel(QWidget* parent)
    :QLabel(parent)
{
    bublebox = nullptr;
    setMouseTracking(true);
    setBubleText("");
    setborderCol(QColor(80,20,240));
}

BubleBox* PushLabel::bublebox = nullptr;
int PushLabel::s = 0;

void PushLabel::setBuble()
{
    if(bublebox!=nullptr)return;
    bublebox = new BubleBox(nullptr);
    bublebox->hide();
}

void PushLabel::setBubleText(QString text)
{
    QString temp;
    int i;
    for (i = 0; i + 10 < text.length();i += 10) {
        temp += text.mid(i,10);
        temp = temp.append('\n');
    }
    temp = temp + text.mid(i,text.length()-i+1);
    bubleText = temp;
}

PushLabel::~PushLabel()
{
    if(bublebox!= nullptr) delete bublebox;
    bublebox = nullptr;
}

void PushLabel::setborderCol(QColor col)
{
    this->col = col;
    this->update();
}

void PushLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //qDebug() << ev;
    QPoint pos = ev->pos();
    if(bublebox != nullptr && bubleText != "") {
        if(pos.x()<2 || this->size().width()-pos.x()<2 ||
                pos.y()<2 || this->size().height()-pos.y()<2){
           if(!(bublebox->isHidden()))bublebox->hide();
        }else{
            bublebox->setText(bubleText);
            bublebox->move(ev->globalX(),ev->globalY()-bublebox->size().height());
            if(bublebox->isHidden())bublebox->show();
        }
    }
}

void PushLabel::mousePressEvent(QMouseEvent *ev)
{
    //qDebug() << ev;
    if(ev->buttons() == Qt::LeftButton && ev->type() == QEvent::MouseButtonPress){
        emit clicked();
    }
    if(ev->buttons() == Qt::LeftButton && ev->type() == QEvent::MouseButtonDblClick){
        emit doubleclicked();
    }
    ev->accept();
}

void PushLabel::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.save();
    painter.setPen(QPen(col, 1));
    painter.setBrush(Qt::NoBrush);
    int offset_x[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int offset_y[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    for (int i = 0; i < 8; ++i)
    {
        QRectF r = ev->rect(); // 预定绘制文字的Rectangle
        r.moveCenter(r.center() + QPointF(offset_x[i], offset_y[i]));
        painter.drawText(r, this->alignment(), this->text());
    }
    painter.restore();
    painter.drawText(ev->rect(), this->alignment(), this->text());
}

void PushLabel::count()
{
    //qDebug() << s;
    if(bublebox == nullptr || bubleText == "") return;
    if(s) --s;
    else if(!(bublebox->isHidden())) bublebox->hide();
}




