// Hei:)) Har forsøkt å kommentere så mye som mulig, siden vi er i en veldig spesiell situasjon med denne koronasmitten.
#include "task1.h"
#include "Matrix.h"
#include "Dummy.h"

void keep_window_open(){
	int i;
	cout << "Press any key to exit "; //Tilsvarende cin.get() men med tekst:))
	cin >> i;
}
void testFibonacci(){
	createFibonacci();
}
void matrixTests(){
	Matrix nullMa = Matrix();
	Matrix idMa = Matrix(4);
	Matrix rMa = Matrix(4,3);
	cout << "Denne bør være nullptr\n" << nullMa;
	cout << "\n Denne bør være en identitetsmatrise\n" << idMa;
	cout << "\nDenne bør være nullmatrise 4x3\n" << rMa;
	for (int i=0;i<rMa.getRows();++i){
		rMa.set(i,1,3.14);
	}
	cout << "\nNå skal andre elem i hver rad være 3.14, ellers 0\n" << rMa <<'\n';
}
void matrixAdd(){
	Matrix A = Matrix(2,2);
	Matrix B = Matrix(2,2);
	Matrix C = Matrix(2,2);
	A.set(0,0,1.0); // Finnes det en mindre kronglete måte å gjøre dette?
	A.set(0,1,2.0); // Kanskje en form for loop, ville det i så fall forverret kjøretid?
	A.set(1,0,3.0);
	A.set(1,1,4.0);
	B.set(0,0,4.0);
	B.set(0,1,3.0);
	B.set(1,0,2.0);
	B.set(1,1,1.0);
	C.set(0,0,1.0);
	C.set(0,1,3.0);
	C.set(1,0,1.5);
	C.set(1,1,2.0);
	cout << "Opprinnelige matriser:\n" << A << '\n' << B << '\n' << C << '\n';
	Matrix Test = B+C; //Kan ikke ta A+=B+C >:(
	A += Test;
	cout << "Etter operasjon A+=B+C er \n" << A << '\n' << B << '\n' << C << '\n';

}


/*
  _       _                                        
 (_)     | |                                       
  _ _ __ | |_ ___ _ __ _ __ ___   ___ ___________  
 | | '_ \| __/ _ \ '__| '_ ` _ \ / _ \_  /_  / _ \ 
 | | | | | ||  __/ |  | | | | | |  __// / / / (_) |
 |_|_| |_|\__\___|_|  |_| |_| |_|\___/___/___\___/ 
Plusspoeng for copy-paste ascii art?

a) Skulle printet ut
a: 4
b: 4
c: 4
a: 4
b: 3
c: 5 
Ved kjøring får man derimot 4, 4, 4, 5, 5, 5 og exception:)
Det virker som problemet er at b == a, så både a, b og c peker til samme adressen
Når man da setter c=5 (siste linje før neste cout), blir det samme for alle.
Mulig kræsjen er at destruktøren for b og c ikke finner det den skal slette, siden a allerede gjorde det

Etter kopi konstruktøren får vi 4, 4, 4, 5, 3, 5. Altså funker b{a}, men vi må overlaste = for at c skal funke
Etter å ha overlastet = får vi det vi forventet i utgangspunktet, og ingen feilmelding:)
*/

int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	//srand(static_cast<unsigned int>(time(nullptr))); //Brukes ikke i denne øvingen men kommer fra create from project:)
	int i;
	do{
		cout << "\nØving 9 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) testFibonacci()\n"
		<< "2) matrixTests()\n"
		<< "3) dummyTest()\n"
		<< "4) matrixAdd()\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1: cout << "---\n";
				testFibonacci();
				break;
		case 2: matrixTests();
				break;
		case 3: dummyTest();
				break;
		case 4: matrixAdd();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	while (i!=0);
	keep_window_open();
}

