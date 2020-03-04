#include "std_lib_facilities.h"
#include "Car.h"
#include "Meeting.h"

/*
	TEORI
1D	Må deklareres med const siden getName() og getEmail() tar inn const Person
	Bør bruke konst når man ikke skal endre objektet og f.eks bare skrive til ostream.
*/

void testPerson(){
	Car toyota = Car(3);
	Person pers2 = Person("Marie", "marie.abs@hotmail.no", &toyota);
	Person pers1 = Person("Jonas", "jboi73@gmail.com");
	
	cout << pers1 << "har";
	if(! pers1.hasAvailableSeats()){cout << " ikke";}
	cout << " ledige seter\n";

	cout << pers2 << "har";
	if(! pers2.hasAvailableSeats()){cout << " ikke";}
	cout << " ledige seter\n";
}

void testMeeting(){
	const Person mellomLeder = Person("Håvard", "havard.fin@ntnu.no");
	Meeting haustmote = Meeting(25, 15, 18, Campus::trondheim, to_string("Forventningsavklaringer"), &mellomLeder);
	
	haustmote.addParticipant(&(Person("Bertha", "mail1")));
	haustmote.addParticipant(&(Person("Margaret", "mail2")));
	cout << haustmote;

	Meeting NVmote = Meeting(25,14,19, Campus::trondheim, to_string("Fakultetsmøte om kansellering av turer"), &(Person(to_string("Marianne G"), to_string("marianne.g@ntnu.no"), &(Car(5)))));
}


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i;
	do{
		cout << "\nØving 8 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) testPerson()\n"
		<< "2) testMeeting()\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1: testPerson();
				break;
		case 2: testMeeting();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	while (i!=0);
	keep_window_open();
}

