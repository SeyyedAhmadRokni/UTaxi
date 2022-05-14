#ifndef _UT_
#define _UT_

#include "UTaxi.hpp"
#include "GeneralFunctions.cpp"

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

#endif