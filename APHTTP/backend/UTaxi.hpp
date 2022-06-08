#ifndef _UTAXI_H
#define _UTAXI_H
#include <bits/stdc++.h>
#include "Area.hpp"
#include "Defines.hpp"
#include "Persons.hpp"
#include "Trip.hpp"

class UTaxi{
private:
    std::map<std::string, Area*> areas;
    std::map<std::string, Person*> persons;
    std::map<int, Trip*> trips;
    int lastTripId = 0;

public:
    void readCities(std::string listAddress);
    void signup(std::string userName, Role role);
    void startTrip(std::string userName, std::string origin,
        std::string destination, bool hurry);
    void showAllTrips(std::string userName, bool sortByCost);
    void showATrip(std::string userName, int id);
    void cancelTrip(std::string userName, int id);
    void acceptTrip(std::string userName, int id);
    void finishTrip(std::string userName, int id);
   std::map<Argument, std::string> readArguments(std::string args);
    std::vector<Command> readCommands(std::string cmd);
    Role identifyRole(std::string role);
    Argument identifyArgument(std::string arg);
    Command identifyCommand(std::string command);
    void getTripCost(std::string userName, std::string origin,
        std::string destination, bool hurry);
    void manageGetCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments);
    void managePostCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments);
    void manageDeleteCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments);
    void doCommand(const std::vector<Command>& commands, 
        std::map<Argument, std::string> arguments);

    ~UTaxi();
    UTaxi(std::string citiesAddress);
};

bool sortByCostDecreasing(const std::pair<int, Trip* >& first, const std::pair<int, Trip* >& second);


#endif