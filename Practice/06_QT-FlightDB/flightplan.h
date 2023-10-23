#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include <unordered_map>
#include <string>
#include <vector>

struct Airport{
    int id;
    double latitude;
    double longitude;
    std::string name;
    std::string iata;
};


class FlightPlan
{
public:
    FlightPlan();
    void add_airport(Airport a, std::vector<int> connections);
    std::vector<Airport> find_shortest_route(Airport a, Airport b);
private:
    std::unordered_map<int,std::vector<Airport>> airports_and_connections;
};

#endif // FLIGHTPLAN_H
