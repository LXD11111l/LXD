#include "fileform.h"
#include "ui_fileform.h"
#include "fileitem.h"


FileForm::FileForm(QWidget *parent, bool isSave) :
    QWidget(parent),
    ui(new Ui::FileForm),
    IsSave(isSave)
{
    ui->setupUi(this);
    this->resize(parent->size());
    layout = new QGridLayout(ui->frame_2);
    setPage();
    loadItem();
    this->show();
}

FileForm* FileForm::instance = nullptr;
QVector<QPixmap> FileForm::Itempix;
QVector<QString> FileForm::Itemtime;

FileForm::~FileForm()
{
    instance = nullptr;
    delete ui;
}

void FileForm::loadItem()
{
    deletItem();
    int num = Itemtime.size() - (index-1)*6;
    if(num > 6)  num = 6;
    for (int i = 0; i < 6; ++i) {
        items[i] = new FileItem(this, IsSave);
        if(i < num){
            items[i]->setPic(Itempix[(index-1)*6 + i]);
            items[i]->setTime(Itemtime[(index-1)*6 + i]);
        }
        layout->addWidget(items[i],i/3,i%3,1,1,Qt::AlignVCenter | Qt::AlignVCenter);
    }
}

void FileForm::deletItem()
{
    for (int i = 0; i < 6; ++i) {
        if(items[i] != nullptr) delete items[i];
        items[i] = nullptr;
    }
}

void FileForm::setPage()
{
    total = Itemtime.size()/6;
    if(Itemtime.size()%6 > 0) ++total;
    if(total == 0) ++total;
    ui->pagelab->setText(QString::number(index) + "/" + QString::number(total));
}

void FileForm::changeEvent(QEvent *e)
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

void FileForm::on_prelab_clicked()
{
    if(index == 1) return;
    --index;
    setPage();
    loadItem();
}

void FileForm::on_nextlab_clicked()
{
    if(index == total && IsSave == false) return;
    ++index;
    setPage();
    loadItem();
}

void FileForm::on_relab_clicked()
{
    deleteLater();
}
