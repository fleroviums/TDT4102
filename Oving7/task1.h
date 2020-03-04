#pragma once
#include "std_lib_facilities.h"

class Animal{
    protected:
        string name;
        int age;
    public:
        Animal(string n, int a) : name{n}, age{a} {}
        virtual string toString() = 0{
            return "Animal: " + name + ", " + to_string(age) +'\n';
        } // Må virtual funksjoner defineres i header?
};

class Cat : public Animal{
    public:
        Cat(string n, int a) : Animal{n,a} {}
        string toString() override{
            return "Cat: " + name + ", " + to_string(age) + '\n';
        }
};
class Dog : public Animal{
    public:
        Dog(string n, int a) : Animal{n,a} {} 
        string toString() override{
            return "Dog: " + name + ", " + to_string(age) + '\n';
        }
};