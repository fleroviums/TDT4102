#pragma once
#include <iostream> // Basic istream/ostream
#include <clocale> //To use nordic letters in terminal
#include <ctime> //To genereate random numbers (with time as seed)
#include <cstdlib> //To generate random numbers
#include <vector> //For vector container
#include <set> // For set container

using namespace std;

void task1();
void printIt(vector<string> vStr);
void replace(vector<string> &sVec, string old, string replacement);
void replaceSet(set<string> &sSet, string old, string replacement);