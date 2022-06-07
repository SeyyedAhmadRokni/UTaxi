#ifndef _LOC_
#define _LOC_
#include "Location.hpp"

Location::Location(double latitude, double longtude){
    this->latitude = latitude;
    this->longitude = longtude;
}

double Location::getLatitude(){
    return latitude;
}
double Location::getLongitude(){
    return longitude;
}

#endif