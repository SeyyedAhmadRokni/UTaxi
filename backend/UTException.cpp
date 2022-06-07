#ifndef _UT_EX_
#define _UT_EX_
#include <bits/stdc++.h>
#include "UTException.hpp"

UTException::UTException(std::string massage){
    this->massage = massage;
}

void UTException::showMassage(){
    std::cout << massage << std::endl;
}





#endif