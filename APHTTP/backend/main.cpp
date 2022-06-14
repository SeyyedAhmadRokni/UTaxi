#ifndef _MAIN_C
#define _MAIN_C

#include <bits/stdc++.h>
#include "handlers.hpp"

using namespace std;

int main(int argc, char* argv[]){
    string areasAddress = std::string(argv[1]);
    API api(areasAddress);
    api.run();
}


#endif