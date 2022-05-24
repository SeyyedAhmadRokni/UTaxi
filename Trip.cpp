#ifndef _TRIP_
#define _TRIP_
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Trip.hpp"
#include "Persons.hpp"
#include "UTException.hpp"

Trip::Trip(int id, Passenger* passenger,
    std::string origin, std::string destination){
    this->id = id;
    this->passenger = passenger;
    this->origin = origin;
    this->destination = destination;
}

void Trip::getBy(Driver* driver){
    driver = driver;
    status = TRAVELING;
    std::cout << SUCCESS_MASSAGE << std::endl;
}

void Trip::finish(std::string user){
    if (!driver->isYou(user)){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    driver->finishTrip();
    status = FINISHED;
    std::cout << SUCCESS_MASSAGE << std::endl;
}

bool Trip::isForDriver(std::string name){
    return driver->isYou(name);
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

void Trip::cancle(std::string user){
    try{
        passenger->cancleTrip(user);
        if (driver != NULL){
            driver->finishTrip();
        }
        status = CANCLED;
        std::cout << SUCCESS_MASSAGE << std::endl;
    }
    catch(std::exception& ex){
        throw ex;
    }
}


int Trip::getId(){
    return id;
}
#endif