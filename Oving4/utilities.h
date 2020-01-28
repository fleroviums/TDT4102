#pragma once
#include "std_lib_facilities.h" //Må denne inkluderes i alle h-filer?
int incrementByValueNumTimes(
                            int startValue,
                            int increment,
                            int numTimes
                            );
int incrementByValueNumTimesRef(
                            int& startValue,
                            int increment,
                            int numTimes
                            );
vector<int> swapNumbers(
                            int& num1,
                            int& num2
                        );
vector<int> randomizeVector(
                            vector<int>& initVec,
                            int n
                            );
void printIntVec(vector<int> toPrint);