#ifndef _PERSON_C
#define _PERSON_C
#include <bits/stdc++.h>
#include "Persons.hpp"
#include "UTException.hpp"
#include "Defines.hpp"

Person::Person(std::string userNmae){
    this->userName = userName;
}

void Person::showTrip(){
    throw UTException(PERMISSION_DENIED_MASSAGE);
}

void Person::startTrip(){
    throw UTException(PERMISSION_DENIED_MASSAGE);
}

void Person::cancleTrip(std::string user){
    throw UTException(PERMISSION_DENIED_MASSAGE);
}

void Person::getTrip(){
    throw UTException(PERMISSION_DENIED_MASSAGE);
}

void Person::finishTrip(){
    throw UTException(PERMISSION_DENIED_MASSAGE);
}

void Passenger::startTrip(){
    if (isInTrip){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    else {
        isInTrip = true;
    }
}

void Passenger::cancleTrip(std::string user){
    if (user != userName){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    else{
        isInTrip = false;

    }
}

void Driver::showTrip(){
    return;
}

bool Driver::isYou(std::string user){
    return user == userName;
}

void Driver::getTrip(){
    if (isInTrip){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    else {
        isInTrip = true;
    }
}

void Driver::finishTrip(){
    isInTrip = false;
}

#endif