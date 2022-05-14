#ifndef _UTAXI_H
#define _UTAXI_H
#include <bits/stdc++.h>
#include "City.hpp"
#include "Persons.hpp"
#include "Defines.hpp"
#include "Trip.hpp"
class UTaxi{
private:
    std::map<std::string, City*> cities;
    std::map<std::string, Person*> persons;
    std::vector<Trip*> trips;
public:

    void readCities(std::string listAddress);
    void signup(std::string userName, Role role);
    void startTrip(std::string userName, std::string origin,
        std::string destination);
    void showAllTrips(std::string userName);
    void showATrip(std::string userName, int id);
};

#endif