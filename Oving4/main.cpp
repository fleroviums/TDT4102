#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
/*
Oppgave 1A:
	Funksjonen bruker pass by value, så v0 forblir det samme
	Hadde vi brukt pass by reference, ville v0 økt med 2, 10 ganger => v0-> 25
Oppgave 1E:
	Bruker pass by value her, hvis du bruker pass by reference og setter num1 = num2, mister man plutselig num2 sin verdi..
	Mye enklere å ta inn en vector med num1, num2 og returnere en ny vector med tallene i motsatt rekkefølge
*/


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;
	while (i!=0){
		cout << "ØVING 4 \n"
		<< "0) Avslutt\n"
		<< "1) testCallByValue()\n"
		<< "2) testCallByReference()\n"
		<< "3) testSwapNumbers()\n"
		<< "4) testVectorSorting()\n";
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
		default: cout << "Ugyldig valg\n";
		}
	}
	
	keep_window_open();
}
