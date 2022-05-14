#ifndef _PERSON_
#define _PERSON_
#include <bits/stdc++.h>
#include "Persons.hpp"

Person::Person(std::string userNmae){
    this->userName = userName;
}

void Person::endTrip(){
    isInTrip = false;
}

Passenger::Passenger(std::string userName):Person(userName){

}

void Passenger::goTrip(){
    isInTrip = true;
}


Driver::Driver(std::string userName):Person(userName){

}

void Driver::getTrip(){
    isInTrip = true;
}



#endif