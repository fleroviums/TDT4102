#include "std_lib_facilities.h"
#include "cannon.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if(abs(compareOperand-toOperand) <= maxError){
		cout << name <<": avviket er neglisjerbart \n";
	}
	else{
		cout << name <<": avvik for stort \n";
	}
}
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
	cout << "Game over :(( \n Du har brukt opp alle forsøkene dine."
}


int main()
{
	srand(static_cast<unsigned int>(time(nullptr))); //Seeding randoms
	setlocale(LC_ALL, "no_NB.UTF-8"); // Norwegian letters patch
	playTargetPractise();
	/*
	for (int i=0;i<20;++i){
		cout << randomWithLimits(70, 100) << '\n';
	}
	int x;
	cout << "Dumb sleep function, enter a number to continue";
	cin >> x;
	for (int i=0;i<20;++i){
		cout << randomWithLimits(70, 100) << '\n';
	}
	
	// FUNKSJONSTESTING
	constexpr double maxError = 0.0001;
	testDeviation(posX(0.0,50.0,5.0),250.0,maxError, "posX(0.0,50.0,5.0)");
	testDeviation(posX(0.0,50.0,2.5),125.0,maxError, "posX(0.0,50.0,2.5)");
	testDeviation(posX(0.0,50.0,0),0.0,maxError, "posX(0.0,50.0,0.0)");
	testDeviation(posY(0,0,2.5),125.0,maxError,"posY(0,25.0,2.5)");
	cout << '\n';
	// END FUNKSJONSTESTING

	cout << targetPractice(250.0,50.0,25.0) << '\n';*/
	keep_window_open();

}
