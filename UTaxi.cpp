#ifndef _UTAXI_
#define _UTAXI_

#include <bits/stdc++.h>
#include "UTaxi.hpp"
#include "GeneralFunctions.hpp"
#include "Defines.hpp"
#include "Persons.hpp"
#include "Area.hpp"
#include "UTException.hpp"
#include "Trip.hpp"

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
    std::string readed;
    getline(file, readed);
    while(getline(file, readed)){
        std::vector<std::string> splited = split(readed, ',');
        std::string cityName = splited[0];
        areas.insert({cityName, 
            new Area(cityName, std::stod(splited[1]), std::stod(splited[2])
            , std::stoi(splited[3]))
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
    std::cout << SUCCESS_MASSAGE << std::endl;
}

void UTaxi::startTrip(std::string userName, std::string origin,
    std::string destination){
    if (!persons.count(userName) || !areas.count(origin)
        || !areas.count(destination)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->startTrip();
    trips.insert({trips.size()+1,
        new Trip(trips.size()+1, (Passenger*)persons.at(userName),
        areas[origin], areas[destination] )});
    std::cout << trips[trips.size()]->getId() << std::endl;
}

void UTaxi::showAllTrips(std::string userName){
    if (!persons.count(userName)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->showTrip();
    if (trips.size() == 0){
        std::cout << EMPTY_MASSAGE << std::endl;
    }
    else{
        for (auto itr = trips.begin(); itr != trips.end(); ++itr){
            std::cout << *(itr->second) << std::endl;
        }
    }
}

void UTaxi::showATrip(std::string userName, int id){
    if (!persons.count(userName) || !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->showTrip();
    std::cout << *trips[id] << std::endl;
}

void UTaxi::cancleTrip(std::string userName, int id){
    if (!persons.count(userName) || !trips.count(id)){
        throw UTException(ABSENCE_MASSAGE);
    }
    trips[id]->cancle(userName);
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

Command UTaxi::idenifyCommand(std::string command){
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
    else if (command == "POST"){
        return POST;
    }
    else if (command == "DELETE"){
        return DELETE;
    }
    else if (command == "GET"){
        return GET;
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
    else if (arg == "yes"){
        return YES;
    }
    else if(arg == "no"){
        return NO;
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

std::vector<Command> UTaxi::readCommands(std::string cmd){
    std::vector<std::string> splited = split(cmd, ' ');
    std::vector<Command> commands;
    for (int i = 0; i < splited.size(); i++){
        commands.push_back(idenifyCommand(splited[i]));
    }
    return commands;
}


void UTaxi::manageGetCommands(const std::vector<Command>& commands, const std::map<Argument, std::string>& arguments){
    if (commands[1] == TRIPS){
        if (arguments.count(ID)){
            showATrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
        }
        else{
            showAllTrips(arguments.at(USERNAME));
        }
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
            arguments.at(DESTINATION));
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
        cancleTrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
    }
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

void UTaxi::doCommand(const std::vector<Command>& commands, 
    std::map<Argument, std::string> arguments){
    try{
        if (commands[0] == GET){
            manageGetCommands(commands, arguments);
        }
        else if (commands[0] == POST){
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
    std::vector<std::string> splited = split(args, ' ');
    for (int i = 0; i < splited.size(); i+=2){
        arguments.insert({identifyArgument(splited[i]), splited[i+1]});
    }
    return arguments;
}

void UTaxi::run(){
    std::string input;
    while(getline(std::cin, input)){
        try {
            std::vector<std::string> splited = split(input, '?');
            if (splited.empty()){
                continue;
            }
            std::vector<Command> commands = readCommands(splited[0]);
            std::map<Argument, std::string> arguments = readArguments(splited[1]);
            doCommand(commands, arguments);
        }
        catch(UTException& ex){
            ex.showMassage();
        }
        catch(...){

        }
        
    }
}


#endif