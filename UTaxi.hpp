#ifndef _UTAXI_H
#define _UTAXI_H
#include <bits/stdc++.h>
#include "City.hpp"
#include "Persons.hpp"
#include "Defines.hpp"

class UTaxi{
private:
    std::map<std::string, City*> cities;
    std::map<std::string, Person*> persons;

public:

    void readCities(std::string listAddress);
    void signup(std::string userName, Role role);
    
};

#endif