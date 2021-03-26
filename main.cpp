#include "geturl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetUrl w;
    w.show();

    return a.exec();
}
