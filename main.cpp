#include "qqmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQMainWindow w;
    w.show();

    return a.exec();
}
