#ifndef FLIGHTTHINGY_H
#define FLIGHTTHINGY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QPainter>
#include <iostream>

class FlightThingy : public QWidget
{
    Q_OBJECT
public:
    explicit FlightThingy(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
signals:

private:


};

#endif // FLIGHTTHINGY_H
