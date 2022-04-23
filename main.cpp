#include "mini_browser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mini_browser w;
    w.show();
    return a.exec();
}
