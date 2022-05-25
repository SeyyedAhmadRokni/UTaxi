#ifndef _TRIP_H
#define _TRIP_H
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Persons.hpp"
#include "Area.hpp"

class Trip{
private:
    int id;
    Driver* driver = NULL;
    Passenger* passenger;
    Area* origin;
    Area* destination;
    TripStatus status = WAITING;
    double price;
    bool inHurry;
public:
    double calculatePrice();
    Trip(int id, Passenger* passenger,
        Area* origin, Area* destination, bool hurry);
    void getBy(Driver* driver);
    void checkIsTripDriver(std::string name);
    void finish(std::string user);
    friend std::ostream& operator<<(std::ostream& os, const Trip& trip);
    void cancel(std::string user);
    int getId();
    TripStatus getStatus();
};

std::ostream& operator<<(std::ostream& os, const Trip& trip);

#endif