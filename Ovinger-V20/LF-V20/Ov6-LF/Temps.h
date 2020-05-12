#pragma once
#include "std_lib_facilities.h"

struct Temps {
	double max;
	double min;
};

void graphTemps(string filename);

istream& operator>>(istream& is, Temps& t);
