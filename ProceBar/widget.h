#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif
#include <probar.h>
#include <QMouseEvent>
#include "bublebox.h"
#include "petform.h"
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_label_2_doubleclicked();
protected:
    //void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;
    Probar* bar;
    BubleBox* box;
    PetForm*  form;
};
#endif // WIDGET_H
