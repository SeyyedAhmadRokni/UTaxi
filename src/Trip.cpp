#ifndef _TRIP_
#define _TRIP_
#include <bits/stdc++.h>
#include "Defines.hpp"
#include "Trip.hpp"
#include "Persons.hpp"
#include "UTException.hpp"

double Trip::calculateCost(){
    double cost = origin->dist(*destination) * BASE_PRICE * 
        (origin->getTrafficFactor() + destination->getTrafficFactor());
    
    if (inHurry){
        return cost * IN_HURRY_FACTOR;
    }
    return cost;
}

Trip::Trip(int id, Passenger* passenger,
    Area* origin, Area* destination, bool hurry){
    this->id = id;
    this->passenger = passenger;
    this->origin = origin;
    this->destination = destination;
    inHurry = hurry;
    price = calculateCost();
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
    os << trip.id << ' ' << trip.passenger->getName() << ' '<< *trip.origin << ' ' << *trip.destination
        << ' ' << statusToString << ' ' << trip.price;

    return os;
}

void Trip::cancel(std::string user){
    if (status == TRAVELING || status == FINISHED){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    passenger->cancelTrip(user);
    if (driver != NULL){
        driver->finishTrip();
    }
    std::cout << SUCCESS_MASSAGE << std::endl;
}

TripStatus Trip::getStatus(){
    return status;
}
int Trip::getId(){
    return id;
}

#endif