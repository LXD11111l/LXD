#ifndef PETFORM_H
#define PETFORM_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "tlabel.h"

namespace Ui {
class PetForm;
}

class PetForm : public QWidget
{
    Q_OBJECT

public:
    explicit PetForm(QWidget *parent = nullptr);
    ~PetForm();
    inline void effect_init();
protected:
    void changeEvent(QEvent *e);
private:
    Ui::PetForm *ui;
    QGraphicsDropShadowEffect* w_shadow;
    static int count;
private slots:
    void on_skill_1_clicked();
    void on_skill_2_clicked();
};

#endif // PETFORM_H
