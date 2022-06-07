#ifndef _CITY_
#define _CITY_

#include <bits/stdc++.h>
#include "Area.hpp"

Area::Area(std::string name, double latitude, double longitude, int trafficF){
        this->name = name;        
        location = new Location(latitude, longitude);
        trafficFactor = trafficF;
}

double Area::dist(const Area& second) const {
    return 110.5 * sqrt(pow(location->getLatitude()- second.location->getLatitude(), 2)
     + pow(location->getLongitude()-second.location->getLongitude(), 2));
}

Area::~Area(){
    delete location;
}

std::ostream& operator<<(std::ostream& os, const Area& city){
    os << city.name;
    return os;
}

int Area::getTrafficFactor() const {
    return trafficFactor;
}
#endif