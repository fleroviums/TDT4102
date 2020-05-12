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
void swapNumbers(
                            int& num1,
                            int& num2
                        );
vector<int> randomizeVector(
                            vector<int>& initVec,
                            int n
                            );
void printIntVec(           vector<int> toPrint
                            );

vector<int> sortVector(
                            vector<int>& initVec
                            );
double medianOfVector(
                            vector<int> A
                            );
struct Student{
    string name;
    string studyProgram;
    int age;
    Student(string n, string s, int a);
};

void printStudent(Student studthing);

string randomizeString(int charLen, char lowerLim, char upperLim);
string readInputToString(int n, char lowerCh, char upperCh);
int countChar(string data, char ch);