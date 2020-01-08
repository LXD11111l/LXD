#ifndef VISUALWIDGET_H
#define VISUALWIDGET_H

#include <QWidget>
#include "petform.h"

namespace Ui {
class VisualWidget;
}

class VisualWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VisualWidget(QWidget *parent = nullptr);
    ~VisualWidget();
    void initForms();
private slots:
    void on_closebtn_clicked();

    void on_closebtn_2_clicked();

private:
    Ui::VisualWidget *ui;
    PetForm* forms[6];
};

#endif // VISUALWIDGET_H
