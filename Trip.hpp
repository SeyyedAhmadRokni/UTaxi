#ifndef _TRIP_H
#define _TRIP_H
#include <bits/stdc++.h>
#include "Defines.hpp"

class Trip{
private:
    int id;
    std::string driver;
    std::string passenger;
    std::string origin;
    std::string destination;
    TripStatus status = WAITING;
public:
    Trip(int id, std::string passenger,
        std::string origin, std::string destination);
    void getBy(std::string name);
    void finish();
    bool isForDriver(std::string name);
    void print();
    void cancle();
    void acceptTrip(std::string userName, int id);
};



#endif