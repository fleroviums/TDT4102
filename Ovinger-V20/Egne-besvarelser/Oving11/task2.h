#pragma once
#include <string> //To use strings
#include <iostream> // Basic istream/ostream
#include <list> //To use lists
using namespace std;

class Person{
    private:
        string firstName;
        string lastName;
    public:
        Person(string fN, string lN) : firstName{fN}, lastName{lN} {}
        friend ostream& operator<<(ostream& os, Person p);
        friend bool operator< ( Person& p1, Person& p2);
}; 

void insertOrdered(list<Person> &l, const Person& p);