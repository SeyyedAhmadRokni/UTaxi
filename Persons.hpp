#ifndef _PERSON_H
#define _PERSON_H

#include <bits/stdc++.h>

class Person{
private:
    std::string userName;
protected:
    bool isInTrip = false;
public:
    Person(std::string usernName);
    void endTrip();
};

class Passenger: public Person{
private:

public:
    Passenger(std::string userName);
    void goTrip();
};

class Driver: public Person{
private:

public:
    Driver(std::string userName);
    void getTrip();
};

#endif