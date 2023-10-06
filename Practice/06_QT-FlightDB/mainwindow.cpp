#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(
        "/mnt/sda2/programming_projects/5_Klasse_POS/Practice/06_QT-FlightDB/AirlineRoutes.db"
    );
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM Airline");
    if(query.exec()){
        std::cout << "query executed" << std::endl;
        int idName = query.record().indexOf("name");
        std::cout << idName << std::endl;
        while (query.next()) {
          QString name = query.value(idName).toString();
          std::cout << name.toStdString() << std::endl;
        }
    } else {
        std::cout << "Query didn't exec" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

