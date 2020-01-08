#ifndef BUBLEBOX_H
#define BUBLEBOX_H

#include <QWidget>
#include "tlabel.h"
#include <QVBoxLayout>

namespace Ui {
class BubleBox;
}

class BubleBox : public QWidget
{
    Q_OBJECT

public:
    explicit BubleBox(QWidget *parent = nullptr);
    ~BubleBox();
    void setText(QString text);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::BubleBox *ui;
    TLabel* label = nullptr;
    QVBoxLayout* layout;
};

#endif // BUBLEBOX_H
