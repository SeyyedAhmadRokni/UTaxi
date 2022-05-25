#ifndef _PERSON_H
#define _PERSON_H

#include <bits/stdc++.h>

class Person{
private:
protected:
    std::string userName;
    bool isInTrip = false;
public:
    Person(std::string usernName);
    virtual void startTrip();
    virtual void showTrip();
    void finishTrip();
    virtual void cancelTrip(std::string user);
    virtual void getTrip();
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    std::string getName();
};

std::ostream& operator<<(std::ostream& os, const Person& person);

class Passenger: public Person{
private:

public:
    Passenger(std::string userName);
    void startTrip();
    virtual void cancelTrip(std::string user);
};

class Driver: public Person{
private:

public:
    Driver(std::string userName);
    void showTrip();
    void finishTrip();
    bool isYou(std::string name);
    virtual void getTrip();
};

#endif