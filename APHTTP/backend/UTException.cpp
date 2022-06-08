#ifndef _UT_EX_
#define _UT_EX_
#include <bits/stdc++.h>
#include "UTException.hpp"

UTException::UTException(std::string massage){
    this->massage = massage;
}

std::string UTException::getMassage(){
    return massage;
}





#endif