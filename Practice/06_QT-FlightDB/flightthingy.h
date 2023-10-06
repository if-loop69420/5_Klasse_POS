#ifndef FLIGHTTHINGY_H
#define FLIGHTTHINGY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QPainter>
#include <iostream>
#include "flightplan.h"

class FlightThingy : public QWidget
{
    Q_OBJECT
public:
    explicit FlightThingy(QWidget *parent = nullptr);
    ~FlightThingy();
protected:
    void paintEvent(QPaintEvent *event) override;
signals:

private:
    QSqlDatabase db;
    FlightPlan fp;
};

#endif // FLIGHTTHINGY_H
