#include "fileitem.h"
#include "ui_fileitem.h"
#include "fileform.h"
#include <QTime>
#include "mainmapwidget.h"
#include <QCoreApplication>

FileItem::FileItem(QWidget *parent, bool isSave) :
    QWidget(parent),
    ui(new Ui::FileItem),
    IsSave(isSave)
{
    ui->setupUi(this);
}

FileItem::~FileItem()
{
    delete ui;
}

void FileItem::setTime(QString time)
{
    ui->timelab->setText(time);
}

void FileItem::setPic(QPixmap pixmap)
{
    ui->icolab->setPixmap(pixmap.scaled(ui->icolab->size()));
}

QString FileItem::getCurrentTime()
{

    QTime current_time = QTime::currentTime();
    int hour = current_time.hour();//当前的小时
    int minute = current_time.minute();//当前的分
    int second = current_time.second();//当前的秒
    QString time = QString::number(hour)+":"+QString::number(minute)+":"+QString::number(second);

    return time;
}

QPixmap FileItem::ScreenCapture()
{
    FileForm* form = FileForm::getFileForm();
    QRect rect = form->geometry();
    form->hide();
    QCoreApplication::processEvents();
    QPixmap p = MainMapWidget::getInstance()->grab(rect);
    p.scaled(ui->icolab->size());
    form->show();
    return p;
}

void FileItem::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void FileItem::on_icolab_clicked()
{
    if(IsSave){
        if(ui->icolab->text() == "NULL"){
            QString time = getCurrentTime();
            FileForm::Itemtime.append(time);
            setTime(time);
            QPixmap p = ScreenCapture();
            FileForm::Itempix.append(p);
            setPic(p);
        }else{
            QString time = ui->timelab->text();
            int i = 0;
            for (i = 0;i < FileForm::Itemtime.size(); ++i) {
                if(FileForm::Itemtime[i] == time){
                   time = getCurrentTime();
                   FileForm::Itemtime[i] = time;
                   setTime(time);
                   QPixmap p = ScreenCapture();
                   FileForm::Itempix[i] = p;
                   setPic(p);
                   break;
                }
            }
        }
        /**
          *存档
        **/

    }else{
        /**
        *读档
        **/

        FileForm::getFileForm()->deleteLater();
    }
}
