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
    return initPosition+initVelocity*time+0.5*acclY()*pow(time,2);
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