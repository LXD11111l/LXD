#ifndef FILEITEM_H
#define FILEITEM_H

#include <QWidget>
#include <QVector>
#include "pushlabel.h"

namespace Ui {
class FileItem;
}

class FileItem : public QWidget
{
    Q_OBJECT

public:
    explicit FileItem(QWidget *parent = nullptr, bool isSave = true);
    ~FileItem();
    void setTime(QString time);
    void setPic(QPixmap pixmap);
    QString getCurrentTime();
    QPixmap ScreenCapture();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::FileItem *ui;
    bool IsSave = true;
private slots:
    void on_icolab_clicked();
};

#endif // FILEITEM_H
