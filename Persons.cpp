#ifndef _PERSON_
#define _PERSON_
#include <bits/stdc++.h>
#include "Persons.hpp"

Person::Person(std::string userNmae){
    this->userName = userName;
}

Passenger::Passenger(std::string userName):Person(userName){

}

void Passenger::goTrip(){
    isInTrip = true;
}

void Passenger::endTrip(){
    isInTrip = false;
}

Driver::Driver(std::string userName):Person(userName){

}




#endif