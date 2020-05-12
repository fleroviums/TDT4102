#include "cannonball.h"
#include "cannonball_viz.h"

double acclY()
{
	return -gravity; // definert som en konstant i cannonball.h
}
double velY(double initVelocityY, double time)
{
	return initVelocityY + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time)
{
	return initPosition + initVelocity * time;
}
double posY(double initPosition, double initVelocity, double time)
{
	return initPosition + initVelocity * time + 0.5 * pow(time, 2.0) * acclY();
}

void printTime(double time)
{
	int hours = static_cast<int>(time) / 3600;
	int minutes = (static_cast<int>(time) - 3600 * hours) / 60;
	double seconds = time - hours * 3600 - minutes * 60;
	cout << hours << " hours, " << minutes << " minutes and " << seconds << " seconds\n";
}

double flightTime(double initVelocityY)
{
	return (-2.0 * initVelocityY) / acclY();
}

double getUserInputTheta()
{
	cout << "Please enter an angle for the cannon: ";
    double theta;
	cin >> theta;
	while (theta < 0.1) {
		cout << "The angle you chose was too small, please select a larger one.\n";
		cin >> theta;
	}
    return theta;
}

double getUserInputAbsVelocity()
{
    cout << "Please enter a velocity for the cannon projectile: ";
    double absVelocity;
	cin >> absVelocity;
	while (absVelocity < 0.1) {
		cout << "The velocity you chose is to small, try again.\n";
		cin >> (absVelocity);
	}
    return absVelocity;
}
double degToRad(double deg)
{
	return (deg / 180) * pi;
}

double getVelocityX(double theta, double absVelocity)
{
	return cos(degToRad(theta)) * absVelocity;
}
double getVelocityY(double theta, double absVelocity)
{
	return sin(degToRad(theta)) * absVelocity;
}

vector<double> getVelocityVector(double theta, double absVelocity)
{
    vector<double> velocityVector;

	velocityVector.push_back(getVelocityX(theta, absVelocity));
	velocityVector.push_back(getVelocityY(theta, absVelocity));
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY)
{
	double fTime = flightTime(velocityY);
	double distanceTraveled = posX(0, velocityX, fTime);
	return distanceTraveled;
	// kort: return posX(0, velocityX, flightTime(velocityY))
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
	double error = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
	return abs(error);
}

void playTargetPractice()
{
	cout << "*******Playing target practice!******\n"
			"The goal of this game is to hit the target, you will be presented\n"
			"with a target at some random distance (between 100 and 1000m)\n"
			"from you. In order to hit a target you must specify an angle and\n"
			"an initial velocity for the cannonball.\n\n";
	constexpr int minTarget = 100;
	constexpr int maxTarget = 1000;
	constexpr int timeSteps = 20;
	constexpr int maxTries = 10;
	double distanceToTarget = randomWithLimits(minTarget, maxTarget);
	double maxError = 5.0;
	bool win = false;

	cout << "Target is placed at " << distanceToTarget << " m range\nGood luck!\n\n";

	cout << fixed << setprecision(2);
	for (int round = 0; round < maxTries; ++round) {
		cout << "Round " << round + 1 << ":\n\n";
		double angle, absVelocity, velocityX, velocityY;
		angle = getUserInputTheta();
        absVelocity = getUserInputAbsVelocity();
        velocityX = getVelocityX(angle,absVelocity);
        velocityY =getVelocityY(angle,absVelocity);

		double error = targetPractice(distanceToTarget, velocityX, velocityY);
		double distanceTraveled = getDistanceTraveled(velocityX, velocityY);

		cout << "\nYour shot went: " << distanceTraveled << " m\nDistance from target: " << error
			 << " m\n";

		cannonBallViz(distanceToTarget, maxTarget, velocityX, velocityY, timeSteps);

		if (error < maxError) {
			win = true;
			break;
		}

		if (distanceTraveled > distanceToTarget) {
			cout << "You overshot the target.\n\n";
		} else {
			cout << "You didn't reach the target.\n\n";
		}
	}

	if (win) {
		cout << "Congratulations you won!\n";
	} else {
		cout << "Too bad, you lost.\n";
	}
}