#ifndef _UT_
#define _UT_

#include "UTaxi.hpp"
#include "GeneralFunctions.cpp"
#include "Defines.hpp"
#include "Persons.hpp"

void UTaxi::readCities(std::string listAddress){
    std::ifstream file;
    file.open(listAddress);
    std::string readed;
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
}


void UTaxi::startTrip(std::string userName, std::string origin,
    std::string destination){

    Passenger* passenger = (Passenger*)persons.at(userName);
    trips.push_back(new Trip(trips.size()+1, userName,
        origin, destination ));
    passenger->goTrip();
}

void UTaxi::showAllTrips(std::string userName){
    for (int i = 0; i < trips.size(); i++) {
        trips[i]->print();
    }
}

void UTaxi::showATrip(std::string userName, int id){
    trips[id-1]->print();
}


#endif