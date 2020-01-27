#include "cannon.h"
#include "std_lib_facilities.h"
double acclY(){
    return -9.81; //ms^-2 
}
double velY(double initVelocityY, double time){
    return initVelocityY+(acclY()*time);
}
double posX(double initPosition, double initVelocity, double time){
    return initPosition+initVelocity*time;
}
double posY(double initPosition, double initVelocity, double time){
    return initPosition+initVelocity*time+0.5*acclY()*time*time;
}

void printTime(double time){
    if (time >= 3600){
	    cout << time/3600 << " timer, ";
	}
	if (time >= 60){
		cout << (static_cast<int>(time)%3600)/60 << " minutter og ";
	}
	cout << static_cast<int>(time)%60 << " sekunder.\n";
}

double flightTime(double initVelocityY){
    return -2*initVelocityY/acclY();
}
double getUserInputTheta(){
    double theta = 0;
    cout << "Skriv inn vinkel: ";
    cin >> theta;
    return theta;
}
double getUserInputAbsVelocity(){
    double AbsVel = 0;
    cout << "Skriv fart i absoluttverdi: ";
    cin >> AbsVel;
    return AbsVel;
}
double degToRad(double deg){
    return deg/360.0*2*3.141592;
}
double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(theta);
}
double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(theta);
}
vector<double> getVelocityVector(double theta, double absVelocity){
    double degs = degToRad(theta);
    double velX = getVelocityX(degs, absVelocity);
    double velY = getVelocityY(degs, absVelocity);
    vector<double> returnvec {velX, velY};
    return returnvec;
}

double getDistanceTraveled(double velocityX, double velocityY){
	double time = flightTime(velocityY);
	return time * velocityX;
    }

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double diff = getDistanceTraveled(velocityX, velocityY) - distanceToTarget;
    return diff;
}