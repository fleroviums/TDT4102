#pragma once
#include "std_lib_facilities.h"
#define yeet throw;

class Car{
    private:
        int freeSeats;
    public:
        bool hasFreeSeats() const;
        void reserveSeat();
        Car(int s) : freeSeats {s} {}
};

class Person{
    private:
        string name;
        string email;
        Car* car;
    public:
        Person(string n, string e, Car* c=nullptr) : name{n}, email{e}, car{c} {}
        string getName() const;
        string getEmail() const;
        void setEmail(string newMail);
        bool hasAvailableSeats() const;
        friend ostream& operator<<(ostream& os, const Person& p);

};