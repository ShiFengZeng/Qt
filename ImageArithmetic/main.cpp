#include "imagearithmetic.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator ts;
    ts.load("C:\\Users\\A53\\Documents\\ImageArithmetic\\taiwan.qm");
    a.installTranslator(&ts);


    ImageArithmetic w;
    w.show();

    return a.exec();
}
