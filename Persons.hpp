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


public:
    Passenger(std::string userName);

};

class Driver: public Person{
private:

public:
    Driver(std::string userName);

};

#endif