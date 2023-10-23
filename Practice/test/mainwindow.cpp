#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "airport.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./flugdb.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

    qx::QxSqlQuery query("WHERE airport.iata = :!iata");
    query.bind(":iata", "VIE");

    list_airport list_of_airports;
    QSqlError daoError = qx::dao::fetch_by_query(query, list_of_airports);
    if (list_of_airports._count() == 1){
        ui->label->setText(list_of_airports.getByIndex(0)->m_name);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

