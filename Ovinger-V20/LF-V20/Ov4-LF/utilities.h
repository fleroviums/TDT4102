#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& a, int& b);
void randomizeVector(vector<int>& vec, int n);
void sortVector(vector<int>& vec);
double medianOfVector(const vector<int>& vec);
string randomizeString(int n, char lower, char upper);
string readInputToString(unsigned int n, char lower, char upper);
int countChar(string str, char ch);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);