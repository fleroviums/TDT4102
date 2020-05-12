#include "Person.h"
#include "std_lib_facilities.h"

Person::Person(string name, string email)
    : Person(name, email, nullptr)
{}

Person::Person(string name, string email, Car* car)
    : name(name), email(email), car(car)
{}

string Person::getEmail() const {
    return email;
}

string Person::getName() const {
    return name;
}

void Person::setEmail(string email) {
    this->email = email;
}

bool Person::hasAvailableSeats() const {
    if (car /* != nullptr */) {
        return car->hasFreeSeats();
    }
    return false;
    // alternatively
    // return car && car->hasFreeSeats();
}

ostream& operator<<(ostream& os, const Person& p) {
	return os << p.name << " (" << p.email << ")";
}

bool Person::operator<(const Person& other) const {
    return name < other.name;
}

bool Person::operator==(const Person& other) const {
    return name == other.name;
}

bool Person::operator!=(const Person& other) const {
	return !(*this == other);
    // return !operator==(other);
}
