#ifndef FILEFORM_H
#define FILEFORM_H

#include <QWidget>
#include "fileitem.h"
#include <QGridLayout>
#include "pushlabel.h"
#include <QVector>

namespace Ui {
class FileForm;
}

class FileForm : public QWidget
{
    Q_OBJECT
private:
    Ui::FileForm *ui;
    bool IsSave = true;
    static FileForm* instance;
    explicit FileForm(QWidget *parent = nullptr, bool isload = true);
    char arr[7];
    int index = 1;
    int total = 1;
    FileItem* items[6] = {nullptr};
    QGridLayout* layout;
public:
    static FileForm* getInstance(QWidget *parent = nullptr, bool isSave = true){
        if(instance == nullptr) instance = new FileForm(parent, isSave);
        return instance;
    }
    static FileForm* getFileForm(){ return instance;}
    ~FileForm();
    void loadItem();
    void deletItem();
    void setPage();
    static QVector<QPixmap> Itempix;
    static QVector<QString> Itemtime;
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_prelab_clicked();
    void on_nextlab_clicked();
    void on_relab_clicked();

};

#endif // FILEFORM_H
