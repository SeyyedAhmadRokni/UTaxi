#ifndef _DEF_H
#define _DEF_H

#include <bits/stdc++.h>

enum Role{
    PASSENGER,
    DRIVER,
};

enum TripStatus{
    WAITING,
    TRAVELING,
    FINISHED,
};

enum Command{
    TRIPS,
    SIGNUP,
    FINISH,
    POST,
    DELETE,
    GET,
    ACCEPT,
};

enum Argument{
    USERNAME,
    ID,
    ORIGIN,
    DESTINATION,
    ROLE, 
};

const double BASE_PRICE = 1000;
const double IN_HOURY_FACTOR = 1.2;

const std::string SUCCESS_MASSAGE = "OK";
const std::string EMPTY_MASSAGE = "EMPTY";
const std::string ABSENCE_MASSAGE = "Not Found";
const std::string INCORRECT_REQUEST_MASSAGE = "Bad Request";
const std::string PERMISSION_DENIED_MASSAGE = "Permission Denied";


#endif 