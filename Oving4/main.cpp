#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
/*
Oppgave 1A:
	Funksjonen bruker pass by value, så v0 forblir det samme
	Hadde vi brukt pass by reference, ville v0 økt med 2, 10 ganger => v0-> 25
Oppgave 1E:
	Bruker pass by reference, og swapNumbres som void funksjon. På denne måten kan vi bare kalle funksjonen
	i en loop og bytte rekkefølgen på to tall helt uproblematisk
*/


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;
	while (i!=0){
		cout << "\nØVING 4 \n"
		<< "0) Avslutt\n"
		<< "1) testCallByValue()\n"
		<< "2) testCallByReference()\n"
		<< "3) testSwapNumbers()\n"
		<< "4) testVectorSorting()\n"
		<< "5) testPrintStruct()\n";
		cin >> i;

		switch(i){
		case 0: break;
		case 1: testCallByValue();
				break;
		case 2: testCallByReference();
				break;
		case 3: testSwapNumbers();
				break;
		case 4: testVectorSorting();
				break;
		case 5: testPrintStruct();
				break;
		default: cout << "Ugyldig valg\n";
		}
	}
	
	keep_window_open();
}
