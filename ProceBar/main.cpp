#include "widget.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
#include "bublebox.h"
#include "visualwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VisualWidget* f = new VisualWidget();
    f->show();
    return a.exec();
}
