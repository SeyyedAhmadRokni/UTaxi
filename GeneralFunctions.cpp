#ifndef _GENE_
#define _GENE_
#include <bits/stdc++.h>
#include "GeneralFunctions.hpp"

std::vector<std::string> split (std::string input, char seprator){
    std::vector<std::string> splited;
    std::string current = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == seprator){
            if (!current.empty())
                splited.push_back(current);
            current = "";
        }
        else{
            current += input[i];
        }
    }

    if (!current.empty()){
        splited.push_back(current);
    }
    
    return splited;
}

#endif