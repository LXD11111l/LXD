#ifndef PUSHLABEL_H
#define PUSHLABEL_H

#include <QtCore/qglobal.h>
#include <QLabel>
#include <QMouseEvent>

class PushLabel : public QLabel
{
    Q_OBJECT
public:
    PushLabel(QWidget* parents = nullptr);
signals:
    void clicked();
public slots:

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // PUSHLABEL_H
