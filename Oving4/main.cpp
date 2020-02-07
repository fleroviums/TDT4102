#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"


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
	using namespace Graph_lib;
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;
	while (i!=0){
		cout<<"            _                 ___ \n"
		<<"           (_)               /   |\n"
		<<"  _____   ___ _ __   __ _   / /| |\n"
		<<" / _ \\ \\ / / | '_ \\ / _` | / /_| |\n"
		<<"| (_) \\ V /| | | | | (_| | \\___  |\n"
		<<" \\___/ \\_/ |_|_| |_|\\__, |     |_/\n"
		<<"                     __/ |        \n"
		<<"                    |___/         \n";

		cout << "0) Avslutt\n"
		<< "1) testCallByValue()\n"
		<< "2) testCallByReference()\n"
		<< "3) testSwapNumbers()\n"
		<< "4) testVectorSorting()\n"
		<< "5) testPrintStruct()\n"
		<< "6) testString()\n"
		<< "7) playMastermind()\n";
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
		case 6: testString();
				break;
		case 7: playMastermind();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	
	keep_window_open();
	return gui_main();
}
