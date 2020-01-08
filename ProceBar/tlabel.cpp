#include "tlabel.h"
#include <QPainter>

TLabel::TLabel(QWidget* parent)
    :QLabel(parent)
{
    setinnerCol(QColor(240,240,240));
    setborderCol(QColor(0,100,220));
    adjustText();
}

TLabel::~TLabel()
{

}

void TLabel::setborderCol(QColor col)
{
    this->col = col;
    this->update();
}

void TLabel::setinnerCol(QColor col)
{
    QPalette pe;
    pe.setColor(QPalette::WindowText, col);
    this->setPalette(pe);
}

void TLabel::adjustText()
{
    //this->setMaximumWidth(160);
    //this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->setWordWrap(true);
    this->adjustSize();
}

void TLabel::paintEvent(QPaintEvent *ev)
{

    QPainter painter(this);
    painter.save();
    painter.setPen(QPen(col, 2));
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
