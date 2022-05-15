#ifndef _TRIP_
#define _TRIP_
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Trip.hpp"

Trip::Trip(int id, std::string passenger,
    std::string origin, std::string destination){
    this->id = id;
    this->passenger = passenger;
    this->origin = origin;
    this->destination = destination;
}

void Trip::getBy(std::string driverName){
    driver = driverName;
    status = TRAVELING;
}

void Trip::finish(){
    status = FINISHED;
}

bool Trip::isForDriver(std::string name){
    return name == driver;
}

std::ostream& operator<<(std::ostream& os, const Trip& trip){
    std::string statusToString;
    if (trip.status == WAITING){
        statusToString = "waiting";
    }
    else if(trip.status == TRAVELING){
        statusToString = "traveling";
    }
    else{
        statusToString = "finished";
    }

    os << trip.id << ' ' << trip.origin << ' ' << trip.destination
        << ' ' << statusToString ;

    return os;
}

void Trip::cancle(){
    status = CANCLED;
}
#endif