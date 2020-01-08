#ifndef MAINMAPWIDGET_H
#define MAINMAPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QMap>
#include <QPoint>
#include "rolelable.h"
#include <QTimer>
#include "labelfactory.h"

#define ROW (13)//行
#define COL (13)//列
#define WID (480)
#define HEI (480)


class MainMapWidget : public QLabel
{
    Q_OBJECT
private:
    static QMap<int, unsigned char*>* Mapdata;
    static QMap<int, RoleLable*>* labeldata;
    static MainMapWidget* instance;
    QFrame* frame = nullptr;
    QTimer* timer = nullptr;
    LabelFactory* factory;
    explicit MainMapWidget(QWidget *parent = nullptr);

public:
    static MainMapWidget* getInstance(QWidget *parent = nullptr){
        if(instance == nullptr) instance = new MainMapWidget(parent);
        return instance;
    }
    ~MainMapWidget();
    void initFloor();
    void loadMap(int floor);
    void deleteLabeldata();
    void initFrame();
    static QMap<int, unsigned char*>* getMapdata(){ return Mapdata;}
    static QMap<int, RoleLable*>* getLabeldata(){ return labeldata;}
    static int Floor;// 当前层数
    inline LabelFactory* getFactory()const{ return this->factory;}
signals:

protected:

public slots:
    void animate();
};

#endif // MAINMAPWIDGET_H
