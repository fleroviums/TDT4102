#include "std_lib_facilities.h"
#include "cannon.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if(abs(compareOperand-toOperand) <= maxError){
		cout << name <<": avviket er neglisjerbart \n";
	}
	else{
		cout << name <<": avvik for stort \n";
	}
}

int main()
{
	// FUNKSJONSTESTING
	constexpr double maxError = 0.0001;
	testDeviation(posX(0.0,50.0,5.0),250.0,maxError, "posX(0.0,50.0,5.0)");
	testDeviation(posX(0.0,50.0,2.5),125.0,maxError, "posX(0.0,50.0,2.5)");
	testDeviation(posX(0.0,50.0,0),0.0,maxError, "posX(0.0,50.0,0.0)");
	testDeviation(posY(0,0,2.5),125.0,maxError,"posY(0,25.0,2.5)");
	cout << endl;
	// END FUNKSJONSTESTING
	keep_window_open();



	/*
	cout << " " << setw(15) << "T=0" << setw(15) << "T=2.5" << setw(15) << "T=5.0\n";
	cout << "acclX" << setw(15) << "0" << setw(15) << "0" << setw(15) << "0\n";
	cout << "acclY" << setw(15) << acclY() << setw(15) << acclY() << setw(15) << acclY() <<'\n';
	cout << "velX" << setw(15) << 50.0 << setw(15) << 50.0 << setw(15) << 50.0 << '\n';
	cout << "velY" << setw(15) << velY(25, 0) << setw(15) << velY(25,2.5) << setw(15) << velY(25,5) << '\n';
	*/
}
