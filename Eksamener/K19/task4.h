#pragma once
#include "std_lib_facilities.h"

class RingBuf{
    private:
        char *buf;
        int capacity;
        int start;
        int size;
    public:
        RingBuf(int capacity);
        RingBuf(const RingBuf &other);
        RingBuf(RingBuf &&other);
        ~RingBuf();
        RingBuf& operator=(RingBuf rhs);
        void write(char c);
        void write(string s);
        char read();
        string read(int count);
        string peek();
        friend void testRingBuf();
};

RingBuf::RingBuf(int capacity) //constr.
    : buf{new char[capacity]}, capacity{capacity}, start{0}, size{0} {}

RingBuf::RingBuf(const RingBuf & other) : buf{ new char[other.capacity]}, capacity{other.capacity},
        start{other.start}, size{other.size} { //copy-constr.
            for(int i=0;i<capacity;++i){
                buf[i] = other.buf[i];
            }
        }


RingBuf::~RingBuf(){ //destr.
    delete[] buf;
}
RingBuf::RingBuf(RingBuf &&other) : buf{other.buf}, capacity{other.capacity}, start{other.size}, size{other.size} {
    other.buf = nullptr; //move constr.
    other.size = 0;
    other.start = 0;
    other.capacity = 0;
}

//copy assignment
RingBuf& RingBuf::operator=(RingBuf rhs){
    char* b = new char[rhs.capacity]; //allkoerer ny buffer
    for(int i=0;i<rhs.capacity;++i){
        b[i] = rhs.buf[i]; //legger inn rhs-verdier i nye buffer
    }
    delete[] buf; //sletter gamle buffer (lhs)
    capacity = rhs.capacity; //overfører buffer-metadata fra rhs til ny buffer
    start = rhs.start;
    size = rhs.size;
    buf = b;
    return *this; //returnerer lhs?
}

void RingBuf::write(char c){
    if(size == capacity){ //increment startindex if overwrite
        start++;
        if(start>=capacity){
            start = 0;
            buf[0] = c;
        }
        else{
            buf[start-1] = c;
        }
    }
    else{
        buf[size]=c;
        size++;
    }
}

char RingBuf::read(){
    if(size==0){
        throw "Unable to read ringbuffer of size " + size;   
    }
    char c = buf[start];
    start++;
    if(start==capacity) start = 0;
    size--;
    return c;
}
void RingBuf::write(string s){
    for(auto c : s){
        write(c);
    }
}
string RingBuf::read(int count){
    if(count ==-1) count = size;
    string s;
    for(int i=0;i<count;++i){
        s+=read();
    }
    return s;
}
string RingBuf::peek(){
    string peekaboo;
    int peekInd = start;
    for(int count=0;count<size;++count){
        peekaboo += buf[peekInd];
        peekInd++;
        if(peekInd == capacity) peekInd = 0;
    }
    return peekaboo;
}