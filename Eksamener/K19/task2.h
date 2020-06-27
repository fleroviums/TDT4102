#pragma once
#include "std_lib_facilities.h"

double sum(vector<double>& x);
double mean(vector<double>& x);
void read_csv(string filename, vector<double>& x, vector<double>& y);
pair<double, double> linreg(vector<double>& x, vector<double>& y);