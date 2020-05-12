#pragma once
#include "std_lib_facilities.h"

/* Teorioppgave:
private - bare klassen selv har tilgang til private medlemsfunksjoner
og medlemsvariabler
• public - alle har tilgang til public medlemsfunksjoner og
medlemsvariabler
• protected - sub-klasser har tilgang til protected medlemsfunksjoner
og medlemsvariabler til super-klassen 
*/

class Animal{
public:
    Animal(string name, int age):name{name},age{age}{};
    virtual void toString() const = 0;
    virtual ~Animal(){};
protected:
    string name;
    int age;
};


class Dog:public Animal{
public:
    Dog(string name, int age):Animal{name, age}{};
    void toString() const override;
};

class Cat:public Animal{
public:
    Cat(string name, int age):Animal{name, age}{};
    void toString() const override;
};

void testAnimal();