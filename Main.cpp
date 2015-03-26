#include "CheckerboardPrinter.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckerboardPrinter w;
    w.show();
    
    return a.exec();
}
