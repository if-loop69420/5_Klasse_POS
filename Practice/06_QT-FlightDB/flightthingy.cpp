#include "flightthingy.h"

FlightThingy::FlightThingy(QWidget *parent)
    : QWidget{parent}
{
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./AirlineRoutes.db");
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

}

void FlightThingy::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    std::cout << "Binting bogo" << std::endl;
    QPixmap backgroundImage(
        "/mnt/sda2/programming_projects/5_Klasse_POS/Practice/06_QT-FlightDB/Earthmap.jpg"
    );
    if (!backgroundImage.isNull()) {
        painter.drawPixmap(rect(), backgroundImage);
    }

    QWidget::paintEvent(event);
}
