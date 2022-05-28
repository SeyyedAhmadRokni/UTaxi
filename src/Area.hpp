#ifndef _CITY_H
#define _CITY_H
#include <bits/stdc++.h>
#include "Location.hpp"

class Area{
private:
    std::string name;
    Location *location;
    int trafficFactor;

public:
    Area(std::string name, double latitude, double longitude, int trafficF);
    ~Area();
    friend std::ostream& operator<<(std::ostream& os, const Area& city);
    double dist(const Area& second) const ;
    int getTrafficFactor() const ;
};


std::ostream& operator<<(std::ostream& os, const Area& city);


#endif 