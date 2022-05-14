#ifndef _PERSON_H
#define _PERSON_H

#include <bits/stdc++.h>

class Person{
private:
    std::string userName;
public:
    Person(std::string usernName);
};

class Passenger: public Person{
private:
    bool isInTrip = false;

public:
    Passenger(std::string userName);
    void goTrip();
    void endTrip();
};

class Driver: public Person{
private:

public:
    Driver(std::string userName);

};

#endif