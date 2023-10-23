#include "mainwindow.h"
#include "precompiled.h"
#include "driver.h"
#include <QxOrm_Impl.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./Formula1.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

    MainWindow w;
    w.show();
    return a.exec();
}
