#ifndef _PERSON_
#define _PERSON_
#include <bits/stdc++.h>
#include "Persons.hpp"

Person::Person(std::string userNmae){
    this->userName = userName;
}

void Person::endTrip(){
    inTrip = false;
}

bool Person::isInTrip(){
    return inTrip;
}

Passenger::Passenger(std::string userName):Person(userName){

}

void Passenger::goTrip(){
    inTrip = true;
}


Driver::Driver(std::string userName):Person(userName){

}

void Driver::getTrip(){
    inTrip = true;
}



#endif