#include "Car.h"

#include "std_lib_facilities.h"
#include <cassert>

Car::Car(int freeSeats) : freeSeats(freeSeats)
{}

bool Car::hasFreeSeats() const
{
	return freeSeats > 0;
}

void Car::reserveFreeSeat()
{
	assert(hasFreeSeats());
	--freeSeats;
}
