#pragma once

#include "Car.h"
#include "std_lib_facilities.h"

class Person
{
public:
	Person(string name, string email);
	Person(string name, string, Car* car);

	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;

	string getEmail() const;
	string getName() const;

	void setEmail(string email);

	bool hasAvailableSeats() const;

	friend ostream& operator<<(ostream& os, const Person& person);

	bool operator<(const Person& other) const;
	bool operator==(const Person& other) const;
	bool operator!=(const Person& other) const;

private:
	string name;
	string email;

	Car* car;
};
