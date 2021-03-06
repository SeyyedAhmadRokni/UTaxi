#ifndef _UTAXI_
#define _UTAXI_

#include <bits/stdc++.h>
#include <algorithm>
#include "UTaxi.hpp"
#include "GeneralFunctions.hpp"
#include "Defines.hpp"
#include "../utils/include.hpp"
#include "Persons.hpp"
#include "Area.hpp"
#include "UTException.hpp"
#include "Trip.hpp"

bool sortByCostDecreasing(const std::pair<int, Trip* >& first, const std::pair<int, Trip* >& second){
    return first.second->calculateCost() > second.second->calculateCost();
}
UTaxi::UTaxi(std::string citiesAddress){
    readCities(citiesAddress);
}

UTaxi::~UTaxi(){
    for (auto itr = areas.begin(); itr != areas.end(); ++itr){
        delete itr->second;
    }
    
    for (auto itr = persons.begin(); itr != persons.end(); ++itr){
        delete itr->second; 
    }

    for (auto itr = trips.begin(); itr != trips.end(); ++itr){
        delete itr->second; 
    }
}

void UTaxi::readCities(std::string listAddress){
    std::ifstream file;
    file.open(listAddress);
    std::string read;
    getline(file, read);
    while(getline(file, read)){
        std::vector<std::string> splitted = split(read, ',');
        std::string cityName = splitted[0];
        areas.insert({cityName, 
            new Area(cityName, std::stod(splitted[1]), std::stod(splitted[2])
            , std::stoi(splitted[3]))
        });
    }
}

void UTaxi::signup(std::string userName, Role role){
    if (persons.count(userName)){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
    Person *person;
    if (role == PASSENGER){
        person = new Passenger(userName);
        persons.insert({userName, person});
    }
    else if (role == DRIVER){
        person = new Driver(userName);
        persons.insert({userName, person});
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

int UTaxi::startTrip(std::string userName, std::string origin,
    std::string destination, bool hurry){
    if (!persons.count(userName) || !areas.count(origin)
        || !areas.count(destination)){
        throw UTException(ABSENCE_MASSAGE);
    }

    persons.at(userName)->startTrip();
    lastTripId++;
    trips.insert({lastTripId,
        new Trip(lastTripId, (Passenger*)persons.at(userName),
        areas[origin], areas[destination], hurry)});
    return trips[lastTripId]->getId();
}

std::string UTaxi::getAllTrips(std::string userName, bool sortByCost){
    if (!persons.count(userName)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->showTrip();
    if (trips.size() == 0){
        return EMPTY_MASSAGE;
    }
    else{
        std::ostringstream os;
        if (sortByCost){
            std::vector <std::pair<int, Trip*> > tripVector(trips.begin(), trips.end());
            sort(tripVector.begin(), tripVector.end(), sortByCostDecreasing);
            for (auto itr = tripVector.begin(); itr != tripVector.end(); ++itr){
                os << itr->second->getTableRowData(userName);

            }
        }
        else{
            for (auto itr = trips.begin(); itr != trips.end(); ++itr){
                os << itr->second->getTableRowData(userName);
            }
        }
        return os.str();
    }
}

void UTaxi::showATrip(std::string userName, int id){
    if (!persons.count(userName) || !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->showTrip();
    std::cout << *trips[id] << std::endl;
}

void UTaxi::cancelTrip(std::string userName, int id){
    if (!persons.count(userName) || !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    trips[id]->cancel(userName);
    delete trips[id];
    trips.erase(id);
}

void UTaxi::acceptTrip(std::string userName, int id){
    if (!persons.count(userName) || !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->getTrip();
    Trip* trip = trips[id];
    trip->getBy((Driver*)persons.at(userName));
}

void UTaxi::finishTrip(std::string userName, int id){
    if (!persons.count(userName) ||  !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    trips[id]->finish(userName);
}

Command UTaxi::identifyCommand(std::string command){
    if (command == "signup"){
        return SIGNUP;
    }
    else if (command == "trips"){
        return TRIPS;
    }
    else if (command == "finish"){
        return FINISH;
    }
    else if (command == "accept"){
        return ACCEPT;
    }
    else if (command == "POST_C"){
        return POST_C;
    }
    else if (command == "DELETE"){
        return DELETE;
    }
    else if (command == "GET_C"){
        return GET_C;
    }
    else if (command == "cost"){
        return COST;
    }
    else{
        throw UTException(ABSENCE_MASSAGE);
    }
}

Role UTaxi::identifyRole(std::string role){
    if (role == "passenger"){
        return PASSENGER;
    }
    else if (role == "driver"){
        return DRIVER;
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

Argument UTaxi::identifyArgument(std::string arg){
    if (arg == "username"){
        return USERNAME;
    }
    else if (arg == "id"){
        return ID;
    }
    else if (arg == "origin"){
        return ORIGIN;
    }
    else if (arg == "destination"){
        return DESTINATION;
    }
    else if (arg == "role"){
        return ROLE;
    }
    else if (arg == "in_hurry"){
        return IN_HURRY;
    }
    else if (arg == "sort_by_cost"){
        return SORT_BY_COST;
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

std::vector<Command> UTaxi::readCommands(std::string cmd){
    std::vector<std::string> splited = split(cmd, ' ');
    std::vector<Command> commands;
    for (int i = 0; i < splited.size(); i++){
        commands.push_back(identifyCommand(splited[i]));
    }
    return commands;
}

void UTaxi::manageGetCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments){
    if (commands[1] == TRIPS){
        if (arguments.count(ID)){
            showATrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
        }
        else{
            getAllTrips(arguments.at(USERNAME),
                stringToBool(arguments.at(SORT_BY_COST)));
        }
    }
    else if (commands[1] == COST){
        getTripCost(arguments.at(USERNAME), arguments.at(ORIGIN),
            arguments.at(DESTINATION), stringToBool(arguments.at(IN_HURRY)));
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}
void UTaxi::managePostCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments){
    if (commands[1] == SIGNUP){
        signup(arguments.at(USERNAME),
            identifyRole(arguments.at(ROLE)));
    }
    else if (commands[1] == TRIPS){
        startTrip(arguments.at(USERNAME), arguments.at(ORIGIN),
            arguments.at(DESTINATION), stringToBool(arguments.at(IN_HURRY)));
    }
    else if (commands[1] == FINISH){
        finishTrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
    }
    else if (commands[1] == ACCEPT){
        acceptTrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

void UTaxi::manageDeleteCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments){
    if (commands[1] == TRIPS){
        cancelTrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

void UTaxi::doCommand(const std::vector<Command>& commands, 
    std::map<Argument, std::string> arguments){
    try{
        if (commands[0] == GET_C){
            manageGetCommands(commands, arguments);
        }
        else if (commands[0] == POST_C){
            managePostCommands(commands, arguments);
        }
        else if (commands[0] == DELETE){
            manageDeleteCommands(commands, arguments);
        }
        else {
            throw UTException(INCORRECT_REQUEST_MASSAGE);
        }
    }
    catch(UTException& ex){
        throw ex;
    }
}

std::map<Argument, std::string> UTaxi::readArguments(std::string args){
    std::map<Argument, std::string> arguments;
    std::vector<std::string> splitted = split(args, ' ');
    for (int i = 0; i < splitted.size(); i+=2){
        arguments.insert({identifyArgument(splitted[i]), splitted[i+1]});
    }
    return arguments;
}

double UTaxi::getTripCost(std::string userName, std::string origin,
    std::string destination, bool hurry){
    if (!persons.count(userName) || !areas.count(destination)
        || !areas.count(origin)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons[userName]->getTripCost();
    Trip trip (lastTripId+1, (Passenger *)persons[userName], areas[origin],
        areas[destination], hurry);
    return trip.calculateCost();
}

#endif