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
    UTaxi(std::string citiesAddress);
    void readCities(std::string listAddress);
    void signup(std::string userName, Role role);
    void startTrip(std::string userName, std::string origin,
        std::string destination);
    void showAllTrips(std::string userName);
    void showATrip(std::string userName, int id);
    void cancleTrip(std::string userName, int id);
    void acceptTrip(std::string userName, int id);
    void finishTrip(std::string userName, int id);
    void test();
};

/*TODO: 1- handle the exceptions
        2- add make file
        3- add an interface to UTaxi + add a command reader
        4- make a differene between passenger and driver
        5- replace Trip  function with operator (?)

*/
#endif