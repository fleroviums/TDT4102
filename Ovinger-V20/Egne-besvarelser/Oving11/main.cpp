#include "task1.h"
#include "task2.h"
#include "task4.h"
void keep_window_open(){ int x; cout << "Press any key to exit...\n"; cin >> x; }
/*
Oppgave 1: All implementasjon i ./task1.cpp
Oppgave 2: Klasse i ./task2.h
*/

void testTask2(){
	list<Person> pList;
	Person p1 = Person("Jonas", "Myklebust");
	Person p2 = Person("Anne", "Nilsen");
	Person p3 = Person("Wenche", "Myhre");
	Person p4 = Person("jegSorteres", "mfeil"); //Illustrerer at sortingen er case-sensitive. Prøvde å bruke tolower() men måtte styre med locale
	insertOrdered(pList, p1);
	insertOrdered(pList, p2);
	insertOrdered(pList, p3);
	insertOrdered(pList, p4);
	for(auto it : pList){
		cout << it << endl;
	}
}
void testTask4(){
	int a = 4; int b = 5;
	cout << "Maks av " << a << " og " << b << " er " << maximum(a, b) << endl;
	double c = 3.14; double d = 9.81;
	cout << "Fungerer også på doubles, ex " << c << " og " << d << " => maks er " << maximum(c,d) << endl;

	vector<int> e{1, 2, 3, 4, 5, 6, 7};
	vector<double> f{1.2, 2.2, 3.2, 4.2};
	vector<string> g{"one", "two", "three", "four"};
	cout << "Før shuffle er vectorene \n";
	printVec(e); printVec(f); printVec(g);
	shuffle(e); shuffle(f); shuffle(g);
	cout << "Etter shuffle er vectorene \n";
	printVec(e); printVec(f); printVec(g);


}

int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i;
	do{
		cout << "\nØving 11 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) Oppgave 1\n"
		<< "2) Oppgave 2\n"
		<< "3) Template-test\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1: task1();
				break;
		case 2: testTask2();
				break;
		case 3: testTask4();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	while (i!=0);
	keep_window_open();
}

