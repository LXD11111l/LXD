#ifndef PUSHLABEL_H
#define PUSHLABEL_H

#include <QtCore/qglobal.h>
#include <QLabel>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include "bublebox.h"
#include <QPaintEvent>

class PushLabel : public QLabel
{
    Q_OBJECT
public:
    PushLabel(QWidget* parent = nullptr);
    void setBuble();
    void setBubleText(QString text);
    ~PushLabel()override;
    void setborderCol(QColor col);
private:
    static BubleBox* bublebox;
    QString bubleText;
    static int s;
    QColor col;

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent * ev) override;
signals:
    void clicked();
    void doubleclicked();
private slots:
    void count();
};

#endif // PUSHLABEL_H
