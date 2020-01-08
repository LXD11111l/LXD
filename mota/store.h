#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QKeyEvent>


namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT
private:
    explicit Store(QWidget *parent = nullptr);
    static Store* instance;
    Ui::Store *ui;
    int index = 1;//现行选中项

public:
    static Store* getInstance(QWidget *parent = nullptr);
    static Store* getStore(){return instance;}
    ~Store();
    void Storeshow();
    void selected();
    void keyPresshandle(int key);
    void Comfirm();
    inline void setIndex(int i){ this->index = i; }
    inline int getIndex() const { return this->index;}
    static int price;
    static int hp;
    static int at;
    static int df;
protected:
    void changeEvent(QEvent *e);

};

#endif // STORE_H
