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
    for (auto itr = cities.begin(); itr != cities.end(); ++itr){
        delete[] itr->second;
    }
    
    for (auto itr = persons.begin(); itr != persons.end(); ++itr){
        delete[] itr->second; 
    }

    for (auto itr = trips.begin(); itr != trips.end(); ++itr){
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

    std::cout << SUCCESS_MASSAGE;
}

void UTaxi::startTrip(std::string userName, std::string origin,
    std::string destination){
    if (!persons.count(userName) || !cities.count(origin)
        || !cities.count(destination)){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->startTrip();
    trips.push_back(new Trip(trips.size()+1, (Passenger*)persons.at(userName),
        origin, destination ));
    
    std::cout << trips[trips.size()-1]->getId();
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
        for (int i = 0; i < trips.size(); i++) {
            std::cout << trips[i] << std::endl;
        }
    }
}

void UTaxi::showATrip(std::string userName, int id){
    if (!persons.count(userName) || id < trips.size()){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->showTrip();
    std::cout << trips[id-1] << std::endl;
}

void UTaxi::cancleTrip(std::string userName, int id){
    if (!persons.count(userName) || id < trips.size()){
        throw UTException(ABSENCE_MASSAGE);
    }
    trips[id-1]->cancle(userName);
    std::cout << SUCCESS_MASSAGE;
}

void UTaxi::acceptTrip(std::string userName, int id){
    if (!persons.count(userName) || id < trips.size()){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->getTrip();
    Trip* trip = trips[id-1];
    trip->getBy((Driver*)persons.at(userName));
    std::cout << SUCCESS_MASSAGE;
}

void UTaxi::finishTrip(std::string userName, int id){
    if (!persons.count(userName) || id < trips.size()){
        throw UTException(ABSENCE_MASSAGE);
    }
    persons.at(userName)->finishTrip();
    Trip* trip = trips[id-1];
    trip->finish(userName);
    std::cout << SUCCESS_MASSAGE;
}

void UTaxi::test(){
    for (auto itr = cities.begin(); itr != cities.end(); itr++) {
        std::cout << itr->second << std::endl;
    }
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
    else{
        throw UTException(INCORRECT_REQUEST_MASSAGE);
    }
}

Role UTaxi::identifyRole(std::string role){
    if (role == "PASSENGER"){
        return PASSENGER;
    }
    else if (role == "DRIVER"){
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

void UTaxi::doCommand(std::vector<Command> commands, 
    std::map<Argument, std::string> arguments){
    try{
        if (commands[0] == GET){
            if (commands[1] == TRIPS){
                if (arguments.count(ID)){
                    showATrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
                }
                else{
                    showAllTrips(arguments.at(USERNAME));
                }
            }
        }
        else if (commands[0] == POST){
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
        }
        else if (commands[0] == DELETE){
            if (commands[1] == TRIPS){
                cancleTrip(arguments.at(USERNAME), std::stoi(arguments.at(ID)));
            }
        }
    }
    catch(UTException& ex){
        throw ex;
    }
    catch(...){
        throw UTException(INCORRECT_REQUEST_MASSAGE);
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
        std::vector<std::string> splited = split(input, '?');
        std::vector<Command> commands = readCommands(splited[0]);
        std::map<Argument, std::string> arguments = readArguments(splited[1]);
        try {
            doCommand(commands, arguments);
        }
        catch(UTException& ex) {
            ex.showMassage();
        }
        
    }
}


#endif