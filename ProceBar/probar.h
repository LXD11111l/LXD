#ifndef PROBAR_H
#define PROBAR_H

#include <QWidget>
#include <QString>
#include <QTimer>

namespace Ui {
class Probar;
}

class Probar : public QWidget
{
    Q_OBJECT
private:
    QString backrgb = "transparent;";
    QString rgb = "qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(250,238,0,90%),stop:0.5 rgba(255,200,0,90%),stop:0.7 rgba(255,181,0,90%),stop:1 rgba(250,130,0,90%));";
    int MaxSize = 0;
    int cSize = 0;
    QTimer* timer = nullptr;
    Ui::Probar *ui;

public:
    explicit Probar(QWidget *parent = nullptr);
    ~Probar();
    inline void setMaxSize(int size){ MaxSize = size;}
    inline bool setCurrentSize(int size);
    void setColor(QString rgb);
    void setFont(QFont font);
    void setTextColor(QColor innercol, QColor bordercol);
    inline void setRate();
protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *event);
public slots:
    void barReset();
};

#endif // PROBAR_H
