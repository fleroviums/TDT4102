#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Dummy {
    public:
        int *num;
        Dummy() {
            num = new int{0};
        }
        ~Dummy() {
            delete num;
        }

        Dummy(const Dummy & other);
        Dummy &operator=(Dummy rhs);
};

void dummyTest();