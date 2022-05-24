#ifndef _MAIN_C
#define _MAIN_C

#include <bits/stdc++.h>
#include "UTaxi.hpp"

using namespace std;


int main(int argc, char* argv[]){
    string areasAddress = std::string(argv[1]);
    UTaxi ut(areasAddress);
    ut.run();    
}


#endif