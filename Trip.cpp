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

void Trip::print(){
    std::string statusToString;
    if (status == WAITING){
        statusToString = "waiting";
    }
    else if(status == TRAVELING){
        statusToString = "traveling";
    }
    else{
        statusToString = "finished";
    }
    std::printf("%d %s %s %s\n", id, origin, destination, statusToString);
}

void Trip::cancle(){
    status = CANCLED;
}
#endif