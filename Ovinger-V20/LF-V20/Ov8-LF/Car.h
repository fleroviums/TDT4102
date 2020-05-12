#pragma once

class Car
{
	int freeSeats;

public:
	Car(int freeSeats);

	bool hasFreeSeats() const;
	void reserveFreeSeat();
};
