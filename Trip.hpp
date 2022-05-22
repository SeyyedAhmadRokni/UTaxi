#ifndef _TRIP_H
#define _TRIP_H
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Persons.hpp"

class Trip{
private:
    int id;
    Driver* driver;
    Passenger* passenger;
    std::string origin;
    std::string destination;
    TripStatus status = WAITING;
public:
    Trip(int id, Passenger* passenger,
        std::string origin, std::string destination);
    void getBy(Driver* driver);
    void finish(std::string user);
    bool isForDriver(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const Trip& trip);
    void cancle(std::string user);
};



#endif