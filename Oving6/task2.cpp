#include "std_lib_facilities.h"
vector<int> getCharStats(string infile){
    vector<int> charStat (26); // char[97]=a, char[122]=z

    ifstream in{infile};
    if(!in){cerr << "Could not open file " << infile;}
    char c;
    while(in.get(c)){
        c = tolower(c);
        if(c >= 97 && c <= 122){ 
            charStat[c-97] += 1;
        }
    }
    return charStat;
}