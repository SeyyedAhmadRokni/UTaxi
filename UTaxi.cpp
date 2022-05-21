#ifndef _UTAXI_
#define _UTAXI_

#include <bits/stdc++.h>
#include "UTaxi.hpp"
#include "GeneralFunctions.hpp"
#include "Defines.hpp"
#include "Persons.hpp"
#include "City.hpp"
#include "UTException.hpp"

UTaxi::UTaxi(std::string citiesAddress){
    readCities(citiesAddress);
}

UTaxi::~UTaxi(){
    for (auto itr = cities.begin();itr != cities.end();++itr){
        delete[] itr->second;
    }
    
    for (auto itr = persons.begin();itr != persons.end();++itr){
        delete[] itr->second; 
    }

    for (auto itr = trips.begin();itr != trips.end();++itr){
        delete[] *itr; 
    }
    
    
}

void UTaxi::readCities(std::string listAddress){
    std::ifstream file;
    file.open(listAddress);
    std::string readed;
    getline(file, readed);
    while(getline(file, readed)){
        std::vector<std::string> splited = split(readed, ',');
        std::string cityName = splited[0];
        cities.insert({cityName, 
            new City(cityName, std::stod(splited[1]), std::stod(splited[2]))}
        );
    }
}

void UTaxi::signup(std::string userName, Role role){
    if (role == PASSENGER){
        persons.insert({userName, 
            new Passenger(userName)
        });
    }
    else if (role == DRIVER){
        persons.insert({userName, 
            new Driver(userName)
        });
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

void UTaxi::startTrip(std::string userName, std::string origin,
    std::string destination){
    
    if (!persons.count(userName) || !cities.count(origin)
        || cities.count(destination)){
        throw UTException(ABSENCE_MASSAGE);
    }
    try{
        Passenger* passenger;
        passenger = (Passenger*)persons.at(userName);       
        if (passenger->isInTrip()){
            throw UTException(INCORRECT_REQUEST_MASSAGE);
        }
        trips.push_back(new Trip(trips.size()+1, userName,
            origin, destination ));
        passenger->goTrip();
    }
    catch(UTException& ex){
        throw ex;
    }
    catch(...){
        throw UTException(PERMISSION_DENIED_MASSAGE);
    }
    
}

void UTaxi::showAllTrips(std::string userName){
    if (trips.size() == 0){
        std::cout << EMPTY_MASSAGE << std::endl;
    }
    
    for (int i = 0; i < trips.size(); i++) {
        std::cout << trips[i] << std::endl;
    }
}

void UTaxi::showATrip(std::string userName, int id){
    std::cout << trips[id-1] << std::endl;
}

void UTaxi::cancleTrip(std::string userName, int id){
    trips[id-1]->cancle();
}

void UTaxi::acceptTrip(std::string userName, int id){
    Trip* trip = trips[id-1];
    trip->getBy(userName);
    try{
    ((Driver*)persons.at(userName))->getTrip();
    } 
    catch(...){
        throw UTException(PERMISSION_DENIED_MASSAGE);
    }
}

void UTaxi::finishTrip(std::string userName, int id){
    Trip* trip = trips[id-1];
    trip->finish();
    
    ((Driver*)persons.at(userName))->endTrip();
}

void UTaxi::test(){
    for (auto itr = cities.begin(); itr != cities.end(); itr++) {
        std::cout << itr->second << std::endl;
    }
    
}

#endif