#include "mainwindow.h"

#include <QApplication>
#include<mainwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.resize(800,600);
    w.show();

    return a.exec();
}
