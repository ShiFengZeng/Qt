#include "loadimage2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadimage2 w;
    w.show();

    return a.exec();
}
