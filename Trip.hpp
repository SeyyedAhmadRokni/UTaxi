#ifndef _TRIP_H
#define _TRIP_H
#include <bits/stdc++.h>
#include "Defines.hpp"

class Trip{
private:
    int id;
    std::string driver;
    std::string passenger;
    TripStatus status = WAITING;
public:
    Trip(int id, std::string driver, std::string passenger);
    void traveling();
    void finish();
    
};



#endif