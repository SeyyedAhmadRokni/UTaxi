#ifndef _MAIN_C
#define _MAIN_C

#include <bits/stdc++.h>
#include "UTaxi.hpp"

using namespace std;


int main(){
    string address = "locations.csv";
    UTaxi ut(address);
    ut.run();    
}


#endif