#ifndef _UT_EX_H
#define _UT_EX_H
#include <bits/stdc++.h>

class UTException: public std::exception{
private:
    std::string massage;

public:
    UTException(std::string m);
    std::string getMassage();

};



#endif