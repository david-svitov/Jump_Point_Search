#include "jps.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JPS w;
    w.show();

    return a.exec();
}
