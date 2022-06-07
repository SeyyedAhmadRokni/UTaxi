#ifndef _GENE_
#define _GENE_
#include <bits/stdc++.h>
#include "GeneralFunctions.hpp"

std::vector<std::string> split (std::string input, char separator){
    std::vector<std::string> splitted;
    std::string current = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == separator){
            if (!current.empty())
                splitted.push_back(current);
            current = "";
        }
        else{
            current += input[i];
        }
    }

    if (!current.empty()){
        splitted.push_back(current);
    }
    
    return splitted;
}

bool stringToBool(std::string input){
    if (input == "yes"){
        return true;
    }
    else if (input == "no"){
        return false;
    }
}

#endif