#include "flightthingy.h"

FlightThingy::FlightThingy(QWidget *parent)
    : QWidget{parent}
{
    this->fp = FlightPlan();
}


void FlightThingy::readFlightData(QSqlDatabase db) {
    this->db = db;

    QSqlQuery query(this->db);
    QSqlQuery route_query(this->db);
    query.prepare("SELECT * FROM Airport");
    route_query.prepare("SELECT airport2 FROM Route WHERE airport1 = (:ap)");
    if(query.exec()){
        int id_id = query.record().indexOf("id");
        int name_id = query.record().indexOf("name");
        int long_id = query.record().indexOf("longitude");
        int lat_id = query.record().indexOf("latitude");
        int iata_id = query.record().indexOf("iata");
        while (query.next()) {
            auto id = query.value(id_id).toInt();
            auto name = query.value(name_id).toString();
            auto longitude = query.value(long_id).toDouble();
            auto latitude = query.value(lat_id).toDouble();
            auto iata = query.value(iata_id).toString();
            route_query.bindValue(":ap", id);
            if(route_query.exec()){
                int ap2_id = query.record().indexOf("airport2");
                while(route_query.next()) {
                    auto ap2 = query.value(ap2_id).toInt();
                }
            }
        }
    } else {
        std::cout << "Query didn't exec" << std::endl;
    }
}


FlightThingy::~FlightThingy() {
    if(this->db != nullptr) {
        this->db.close();
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
