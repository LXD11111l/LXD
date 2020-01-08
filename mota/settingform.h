#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include <QWidget>

namespace Ui {
class SettingForm;
}

class SettingForm : public QWidget
{
    Q_OBJECT
private:
    Ui::SettingForm *ui;
    explicit SettingForm(QWidget *parent = nullptr);
    static SettingForm* instance;
public:
    static SettingForm* getInstance(QWidget *parent = nullptr){
        if(instance == nullptr) instance = new SettingForm(parent);
        return instance;
    }
    static SettingForm* getSettingForm(){ return instance;}
    ~SettingForm();
    void showForm();

protected:
    void changeEvent(QEvent *e);
private slots:
    void on_regameLab_clicked();
    void on_retitleLab_clicked();

};

#endif // SETTINGFORM_H
