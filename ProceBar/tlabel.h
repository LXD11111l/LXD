#ifndef TLABEL_H
#define TLABEL_H

#include <QtCore/qglobal.h>
#include <QLabel>
#include <QPaintEvent>
#include <QColor>

class TLabel : public QLabel
{
public:
    TLabel(QWidget* parent = nullptr);
    ~TLabel()override;
    inline void setborderCol(QColor col);
    inline void setinnerCol(QColor col);
    inline void adjustText();
private:
    QColor col;
protected:
    void paintEvent(QPaintEvent * ev) override;

};

#endif // TLABEL_H
