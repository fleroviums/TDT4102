#include "std_lib_facilities.h"
#include "cannon.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if(compareOperand-toOperand <= maxError){
		cout << "Gutta, den funker";
	}
}

int main()
{
	cout << " " << setw(15) << "T=0" << setw(15) << "T=2.5" << setw(15) << "T=5.0\n";
	cout << "acclX" << setw(15) << "0" << setw(15) << "0" << setw(15) << "0\n";
	cout << "acclY" << setw(15) << acclY() << setw(15) << acclY() << setw(15) << acclY() <<'\n';
	cout << "velX" << setw(15) << 50.0 << setw(15) << 50.0 << setw(15) << 50.0 << '\n';
	cout << "velY" << setw(15) << velY(25, 0) << setw(15) << velY(25,2.5) << setw(15) << velY(25,5) << '\n';
	keep_window_open();
}
