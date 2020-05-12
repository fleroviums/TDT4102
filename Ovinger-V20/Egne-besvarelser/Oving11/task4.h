#pragma once
#include <ctime> //To genereate random numbers (with time as seed)
#include <cstdlib> //To generate random numbers
#include <vector> //For vector container
#include <iostream> // Basic istream/ostream


template <typename T>
T maximum(T a, T b){
    return a>b?a:b;
}
/* Teori: Med mindre typename T har riktig overlastet kopikonstruktør og > operator vil koden ikke kompilere */


template <typename T> //Usikker på om jeg trenger denne siden jeg allerede har template på linje 6, har den for sikkerhets skyld
void shuffle(vector<T> &vec){ //random seed set in main
    for(auto it=vec.begin();it!=vec.end();++it){
        int rInd = rand() % vec.size(); //random index
        T tmp = vec[rInd]; //swap current index in loop with random index (possibly itself, not necessarily a problem)
        vec[rInd] = *it;
        *it = tmp;
    }
}

template <typename T> //Usikker på om jeg trenger denne siden jeg allerede har template på linje 6, har den for sikkerhets skyld
void printVec(vector<T> vec){
    for(auto it=vec.begin();it!=vec.end();++it){
        cout << *it << ' ';
    }
    cout << endl;
}