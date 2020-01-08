#ifndef MONSTERMANUAL_H
#define MONSTERMANUAL_H

#include <QWidget>
#include "monsteritem.h"
#include <QMap>
#include "mainmapwidget.h"
#include "labelfactory.h"
#include <QVBoxLayout>
#include "pushlabel.h"

namespace Ui {
class MonsterManual;
}

class MonsterManual : public QWidget
{
    Q_OBJECT
private:
    Ui::MonsterManual *ui;
    QMap<int, MON> monster;
    int index = 1;
    int total = 0;
    MonsterItem* items[6] = {nullptr};
    explicit MonsterManual(QWidget *parent = nullptr);
    static MonsterManual* instance;
    QVBoxLayout * layout = nullptr;
    QWidget* w = nullptr;
public:
    static bool isActive;
    static MonsterManual* getInstance(QWidget *parent = nullptr){
        if(instance == nullptr && isActive) instance = new MonsterManual(parent);
        return instance;
    }
    static MonsterManual* getMonsterManual(){ return instance;}
    static void setActive(bool isactive);
    ~MonsterManual();
    void initMonsterdata();
    void loadItem();
    void deletItem();
    void setPage();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_prelab_clicked();
    void on_nextlab_clicked();
    void on_relab_clicked();


};

#endif // MONSTERMANUAL_H
