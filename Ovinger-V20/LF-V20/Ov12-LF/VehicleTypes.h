#pragma once
#include "Vehicle.h"
#include "CustomAlgorithms.h"

class PlayerVehicle : public Vehicle{
private:
	std::pair<double, double> steer() const override;
	void drawBody() const override;

public:
	PlayerVehicle(double x, double y, double angle, const Track& t) : Vehicle(x, y, angle,t) {}
};

class Coyota : public Vehicle {
private:
	Fl_Color myColor;

	drivingAlgorithm* myDrive; // Funksjonspeikar for styring

	double offset;

	std::pair<double, double> steer() const override;
	void drawBody() const override;

public:
	Coyota(double x, double y, double angle, const Track& t, Fl_Color setColor, drivingAlgorithm driveFunc)
	 : Vehicle(x, y, angle, t), myColor(setColor), myDrive(driveFunc) {
		static double nextOffset = 3.0;
		offset = nextOffset;
		nextOffset += 3;
	}
};