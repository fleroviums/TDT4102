#include "Car.h"

bool Car::hasFreeSeats() const{
    if(!freeSeats){
       return false; 
    }
    return true;
}

string Person::getName() const{
    return name;
}
string Person::getEmail() const{
    return email;
}
void Person::setEmail(string newMail){
    email = newMail;
}
bool Person::hasAvailableSeats() const{
    if(car == nullptr){
        return false;
    }
    return car->hasFreeSeats();
}

ostream& operator<<(ostream& os, const Person& p){
    os << p.getName() <<", " << p.getEmail() <<'\n';
    return os;
}
