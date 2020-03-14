#include "std_lib_facilities.h"
#include "Car.h"
#include "Meeting.h"
#include "MeetingWindow.h"

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
	Person pers3 = Person("Bertha", "mail1");
	Person pers4 = Person("Mary", "mail2");
	
	haustmote.addParticipant(&pers3);
	haustmote.addParticipant(&pers4);
	cout << haustmote;

	Car subaru = Car(5);
	Person pers1 = Person("Marianne", "marianne@gmail.com", &subaru);
	Person pers2 = Person("pers2", "pers2mail");
	Meeting NVmote = Meeting(25,14,19, Campus::trondheim, "Fakultetsmøte om kansellering av turer", &pers1);
	NVmote.addParticipant(&pers2);

	vector<const Person*> potDrivers = haustmote.findPotentialCoDriving();
	for (const auto& d : potDrivers){
		cout << "Potential driver:\n";
		cout << *d;
	}
}
void testBlankWindow(){
	MeetingWindow winTest = MeetingWindow(Point{200,200}, 400,400,"Test window");
	keep_window_open();
}
void testGUI(){}


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i;
	do{
		cout << "\nØving 8 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) testPerson()\n"
		<< "2) testMeeting()\n"
		<< "3) testBlankWindow()\n"
		<< "4) testGUI()\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1: testPerson();
				break;
		case 2: testMeeting();
				break;
		case 3: testBlankWindow();
				break;
		case 4: testGUI();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	while (i!=0);
	
	MeetingWindow win{Point{100, 100}, 600, 400, "Meetings" };
	gui_main();
	for (const auto p : win.getPeople()){
		cout << p->getName() << endl;
	}
	keep_window_open();
}

