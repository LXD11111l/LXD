#include "widget.h"
#include <QApplication>
#include "startupwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    StartupWidget startwidget;
    startwidget.show();

    return a.exec();
}
