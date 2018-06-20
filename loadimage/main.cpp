#include "loadimage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadimage w;
    w.show();

    return a.exec();
}
