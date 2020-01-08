#ifndef MONSTERITEM_H
#define MONSTERITEM_H

#include <QWidget>

namespace Ui {
class MonsterItem;
}

class MonsterItem : public QWidget
{
    Q_OBJECT

public:
    explicit MonsterItem(QWidget *parent = nullptr);
    ~MonsterItem();
    void setIco(QPixmap ico);
    void setName(QString name);
    void setAt(int at);
    void setDf(int df);
    void setHp(int hp);
    void setMo(int mo);
    void setDam(int dam);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MonsterItem *ui;
};

#endif // MONSTERITEM_H
