#pragma once
#include "std_lib_facilities.h"

struct Temps {
	double max, min;
};
istream& operator>>(istream& is, Temps& t);
ostream & operator<<(ostream & os, vector<Temps>& temps);
vector<Temps> readTemps(string inFile);
void drawTemp();