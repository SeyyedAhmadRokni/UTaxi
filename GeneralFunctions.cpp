#ifndef _GENE_
#define _GENE_
#include <bits/stdc++.h>

std::vector<std::string> split (std::string input, char seprator){
    std::vector<std::string> splited;
    
    std::string current = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == seprator){
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