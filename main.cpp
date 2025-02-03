#include "maincontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController w;
    w.setWindowTitle("Workers DB editor");
    w.show();
    return a.exec();
}
