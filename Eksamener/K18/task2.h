#pragma once
#include "std_lib_facilities.h"

struct Obs{
    int x;
    int y;
};

vector<Obs> readData(string filename){
    vector<Obs> observations;
    ifstream ifs {filename};
    if(!ifs) throw "Couldn't open file " + filename;
    int x, y;
    do
    {
        ifs >> x >> y;
        Obs o; o.x=x; o.y=y;
        observations.push_back(o);
    } while (x!=-1);
    return observations;
}

bool operator<(const Obs& lhs, const Obs& rhs){
    if(lhs.x != rhs.x) return lhs.x < rhs.x;
    else {return lhs.y < rhs.y;}
}

void report(vector<Obs> vec, int threshold){
    map<Obs,int> freq;
    for(auto obs : vec){
        freq[obs] ++;
    }
    for(auto i : freq){
        if(i.second >= threshold){
            cout << i.first.x << " " << i.first.y << " " << i.second << endl;
        }
    }
}