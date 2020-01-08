#ifndef DIALOGWIDGET_H
#define DIALOGWIDGET_H

#include <QWidget>

namespace Ui {
class DialogWidget;
}

class DialogWidget : public QWidget
{
    Q_OBJECT
private:
    explicit DialogWidget(QWidget *parent = nullptr);
    Ui::DialogWidget *ui;
    static DialogWidget* instance;

public:
    static DialogWidget* getInstance(QWidget* parent = nullptr){
        if(instance == nullptr) instance = new DialogWidget(parent);
        return instance;
    }
    static DialogWidget* getDialogWidget(){return instance;}
    ~DialogWidget();
    void showDialog();
    void setText(QString ico, QString role,QString text);
    void keyPressHandle(int key);
protected:
    void changeEvent(QEvent *e);


};

#endif // DIALOGWIDGET_H
