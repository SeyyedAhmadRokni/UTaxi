#ifndef _UTAXI_H
#define _UTAXI_H
#include <bits/stdc++.h>
#include "City.hpp"
#include "Defines.hpp"
#include "Persons.hpp"
#include "Trip.hpp"

class UTaxi{
private:
    std::map<std::string, City*> cities;
    std::map<std::string, Person*> persons;
    std::vector<Trip*> trips;

    void readCities(std::string listAddress);
    void signup(std::string userName, Role role);
    void startTrip(std::string userName, std::string origin,
        std::string destination);
    void showAllTrips(std::string userName);
    void showATrip(std::string userName, int id);
    void cancleTrip(std::string userName, int id);
    void acceptTrip(std::string userName, int id);
    void finishTrip(std::string userName, int id);
    std::map<Argument, std::string> readArguments(std::string args);
    std::vector<Command> readCommands(std::string cmd);
    Role identifyRole(std::string role);
    Argument identifyArgument(std::string arg);
    Command idenifyCommand(std::string commnad);
    void doCommand(std::vector<Command> commands, 
        std::map<Argument, std::string> arguments);

public:
    ~UTaxi();
    UTaxi(std::string citiesAddress);
    void run();
};

#endif