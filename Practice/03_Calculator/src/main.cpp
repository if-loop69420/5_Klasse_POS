#include <QApplication>
#include "MainWindow.h"
#include <iostream>

using std::cout, std::cerr, std::endl;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return QApplication::exec();
}
