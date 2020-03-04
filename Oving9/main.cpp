#include "std_lib_facilities.h"


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i;
	do{
		cout << "\nØving X - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) ----\n"
		<< "2) ----\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1:
				break;
		case 2:
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	while (i!=0);
	keep_window_open();
}

