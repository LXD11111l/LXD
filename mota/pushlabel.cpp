#include "pushlabel.h"

PushLabel::PushLabel(QWidget* parents)
    :QLabel(parents)
{

}

void PushLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton){
        emit clicked();
    }
    ev->accept();
}
