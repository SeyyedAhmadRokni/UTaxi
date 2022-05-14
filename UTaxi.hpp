#ifndef _UTAXI_H
#define _UTAXI_H
#include <bits/stdc++.h>
#include "City.hpp"

class UTaxi{
private:
    std::map<std::string, City*> cities;
    

public:

    void readCities(std::string listAddress);
};

#endif