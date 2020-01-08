#ifndef WIDGET_H
#define WIDGET_H
#include <QResizeEvent>
#include <QWidget>
#include <QPoint>
#include <rolelable.h>
#include <QPaintEvent>
#include <QKeyEvent>
#include <mainmapwidget.h>
#include "braver.h"
#include "store.h"
#include "packetwidget.h"
#include "dialogwidget.h"
#include "floorleap.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void initMap();
    void initMainRole(QString picsource, QPoint p);
    void initStore();
    void initPacketWidget();
    void initDialogWidget(QString ico, QString role,QString text);
    void Layout();
protected:
    void changeEvent(QEvent *e);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void paintEvent(QPaintEvent * event);
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);

private slots:


private:
    Ui::Widget *ui;
    MainMapWidget* mainMap;
    PacketWidget* pWidget;
};

#endif // WIDGET_H
