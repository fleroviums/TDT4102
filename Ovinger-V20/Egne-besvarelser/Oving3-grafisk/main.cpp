#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

#include "cannonball_viz.h"
#include "cannon.h"
#include "utilities.h"

void playTargetPractise(){
	constexpr int winTolerance = 5;
	constexpr int allowedAttempts = 10;

	int attempts = 1;
	double TargetPos = randomWithLimits(100,1000);
	while (attempts <= allowedAttempts){
		double theta = getUserInputTheta();
		double absVel = getUserInputAbsVelocity();
		vector<double> PosVec {getVelocityVector(theta, absVel)}; //Note: Using point class is optimal, but exercise asked for vector<double>

		double targetDistance { targetPractice(TargetPos,PosVec[0], PosVec[1]) };
		cannonBallViz(TargetPos,1000,PosVec[0],PosVec[1],10);
		if (abs(targetDistance) < winTolerance){ //Checks if landed cannon is close enough to target
			cout << "Gratulerer, du vant! \nDu brukte " << attempts << " forsøk.\n";
			break;
		}
		attempts += 1;
		cout << "Godt forsøk, du landet " << abs(targetDistance);
		if (targetDistance < 0){
			cout << " for kort.\n";
		}
		else{
			cout << " for langt.\n";
		}
		cout << "Kulens reisetid: ";
		printTime(flightTime(PosVec[1]));
		cout << "Trykk tast+enter for å prøve igjen. Velg 0 for å avslutte.\n";
		char x;
		cin >> x;
		if(x == '0'){break;}
	}
	cout << "Game over :(( \n Du har brukt opp alle forsøkene dine.";
}


// This is cool, but am I supposed to implement it? Nah
int main()
{
	srand(static_cast<unsigned int>(time(nullptr))); //Seeding randoms
	setlocale(LC_ALL, "no_NB.UTF-8"); // Norwegian patch 
	playTargetPractise();
	keep_window_open();	
}

