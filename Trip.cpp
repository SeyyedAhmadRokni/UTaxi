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

void Trip::getBy(Driver* driv){
    driver = driv;
    status = TRAVELING;
    std::cout << SUCCESS_MASSAGE << std::endl;
}

void Trip::checkIsTripDriver(std::string name){
    if (driver == NULL){
        throw UTException(ABSENCE_MASSAGE); 
    }
    else if(!driver->isYou(name)){
        throw UTException(ABSENCE_MASSAGE);
    }
}

void Trip::finish(std::string user){
    checkIsTripDriver(user);
    driver->finishTrip();
    status = FINISHED;
    std::cout << SUCCESS_MASSAGE << std::endl;
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
    os << trip.id << ' ' << trip.passenger->getName() << ' '<< trip.origin << ' ' << trip.destination
        << ' ' << statusToString ;

    return os;
}

void Trip::cancle(std::string user){
    if (status == TRAVELING || status == FINISHED){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    passenger->cancleTrip(user);
    if (driver != NULL){
        driver->finishTrip();
    }
    std::cout << SUCCESS_MASSAGE << std::endl;
}

int Trip::getId(){
    return id;
}
#endif