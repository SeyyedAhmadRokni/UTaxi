#ifndef _CITY_
#define _CITY_

#include <bits/stdc++.h>
#include "City.hpp"

City:: City(std::string name, double latitude, double longitude){
        this->name = name;        
        location = new Location(latitude, longitude);
}

std::ostream& operator<<(std::ostream& os, const City& city){
    os << city.name << ' ';
    return os;
}
#endif