#ifndef _CITY_H
#define _CITY_H
#include <bits/stdc++.h>
#include "Location.hpp"

class City{
private:
    std::string name;
    Location *location;


public:
    City(std::string name, double latitude, double longitude);
    

};




#endif 