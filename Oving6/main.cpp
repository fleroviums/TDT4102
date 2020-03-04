#include "std_lib_facilities.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
/*
Teori
3D	Endrer oppførselen til funksjonen seg? Har du en forklaring på hva som skjer?
		- Ja, insert() vil +=1 på iteratoren (som jeg ikke vet hva er) mens operator[] vil overkjøre

*/

void oppg1(){
	printToFile("test.txt");
	lineNumber("gutta.txt");
	cout << "File read sucessfully!\n";
}
void oppg2(){
	vector<int> statistikk = getCharStats("grunnlov.txt");
	char thisChar = 'a';
	for (auto num : statistikk){
		cout << thisChar << ": " << num <<'\n';
		thisChar+=1;  
	}
}

void classTest(){
	CourseCatalog minKatalog;
	minKatalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	minKatalog.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
	minKatalog.addCourse("TMA4100","Matematikk 1");
	cout << minKatalog << '\n';
	minKatalog.addCourse("TDT4102", "C++");
	cout << "Oppgave e, her lagrer jeg de andre tingene:)";
	minKatalog.saveCatalog("mycat.txt", minKatalog);
	minKatalog.loadCatalog("mycat.txt");
}

void tempTest(){
	vector<Temps> tmpVec = readTemps("temperatures.txt");
	cout << tmpVec;
}

int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;

	while (i!=0){
		cout << "\nØving 6 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) Oppgave 1\n"
		<< "2) Oppgave 2\n"
		<< "3) classTest()\n"
		<< "4) Read temperatures\n"
		<< "5) Graphical\n";
		cin >> i;

		switch(i){
		case 0: break;
		case 1: oppg1();
				break;
		case 2: oppg2();
				break;
		case 3: classTest();
				break;
		case 4: tempTest();
				break;
		case 5: drawTemp();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}

	keep_window_open();
}