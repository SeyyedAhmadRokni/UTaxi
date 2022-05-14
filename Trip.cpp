#ifndef _TRIP_
#define _TRIP_
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Trip.hpp"

Trip::Trip(int id, std::string driver, std::string passenger){
    this->id = id;
    this->driver = driver;
    this->passenger = passenger;
}

void Trip::finish(){
    status = FINISHED;
}

void Trip::traveling(){
    status = TRAVELING;
}

#endif