#include <std_lib_facilities.h>
#include "cannonball.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	// srand(100);
	constexpr double maxError = 0.01;

	cout << "Deviation tests:\n";
	testDeviation(acclY(), -9.81, maxError, "AcclY()");

	testDeviation(velY(25.0, 0.0), 25.0, maxError, "velY(0.0, 0.0)");
	testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0, 2.5)");
	testDeviation(velY(25.0, 5.0), -24.05, maxError, "velY(25.0, 5.0)");

	testDeviation(posX(0.0, 50.0, 0.0), 0.0, maxError, "posX(0.0, 50.0, 0.0)");
	testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0, 50.0, 2.5)");
	testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0, 50.0, 5.0)");

	testDeviation(posY(0.0, 25.0, 0.0), 0.0, maxError, "posY(0.0, 25.0, 0.0)");
	testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
	testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0, 25.0, 5.0)");

	testDeviation(flightTime(30.0), 6.116, maxError, "flightTime(30.0)");

	testDeviation(getVelocityX(0.0, 1.0), 1.0, maxError, "getVelocityX(0.0, 1.0)");
	testDeviation(getVelocityY(0.0, 1.0), 0.0, maxError, "getVelocityY(0.0, 1.0)");

	vector<double> velocityVector;
	velocityVector = getVelocityVector(0.0, 1.0);
	testDeviation(velocityVector.at(0), 1.0, maxError, "vX from getVelocityVector(0,0, 1.0)");
	testDeviation(velocityVector.at(1), 0.0, maxError, "vY from getVelocityY(0,0, 1.0)");

	cout << '\n';

	printTime(3665.5);
	printTime(3565.5);
	printTime(7065.5);

	cout << "\n\n";

	playTargetPractice();
	keep_window_open();
	return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name)
{
	if (abs(compareOperand - toOperand) <= maxError) {
		cout << name << " is valid.\n";
	} else {
		cout << name << " is invalid. Expected: " << toOperand << ", got " << compareOperand
			 << ".\n";
	}
}
