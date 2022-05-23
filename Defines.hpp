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
    CANCLED,
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

std::string SUCCESS_MASSAGE = "OK";
std::string EMPTY_MASSAGE = "EMPTY";
std::string ABSENCE_MASSAGE = "Not Found";
std::string INCORRECT_REQUEST_MASSAGE = "Bad Request";
std::string PERMISSION_DENIED_MASSAGE = "Permission Denied";


#endif 