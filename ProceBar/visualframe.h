#ifndef VISUALFRAME_H
#define VISUALFRAME_H

#include <QFrame>
#include "petform.h"

namespace Ui {
class VisualFrame;
}

class VisualFrame : public QFrame
{
    Q_OBJECT

public:
    explicit VisualFrame(QWidget *parent = nullptr);
    ~VisualFrame();
    void initForms();
private:
    Ui::VisualFrame *ui;
    PetForm* forms[6];
};

#endif // VISUALFRAME_H
