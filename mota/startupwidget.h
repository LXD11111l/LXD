#ifndef STARTUPWIDGET_H
#define STARTUPWIDGET_H

#include <QWidget>
#include "widget.h"
#include <QMouseEvent>

namespace Ui {
class StartupWidget;
}

class StartupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartupWidget(QWidget *parent = nullptr);
    ~StartupWidget();
    static StartupWidget* swidget;
protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    virtual void showEvent(QShowEvent*ev);

private slots:
    void on_startlab_clicked();
    void on_loadlab_clicked();
    void on_exitlab_clicked();
private:
    Ui::StartupWidget *ui;
    Widget* w = nullptr;
    QPoint StartPos;
};

#endif // STARTUPWIDGET_H
