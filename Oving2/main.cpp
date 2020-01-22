#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"


const char oe = char(148); //ascii hater ø men ok


// ======= BEGIN OPPGAVE 1 FUNCTIONS ======= 
void inputAndPrintInteger(){
	cout << "Skriv inn et tall: ";
	int x = 0;
	cin >> x;
	cout << "Du skrev: " << x << '\n';
}
int inputInteger(){
	int x;
	cout << "Skriv inn et tall: ";
	cin >> x;
	return x;
}
void inputIntegersAndPrintSum(){
	int x = inputInteger(), y = inputInteger();
	cout << "Summen av tallene: " << x+y << '\n';
}
bool isOdd(int num){
	if (num % 2 != 0){
		return true;
	}
	else{
		return false;
	}
	
}
void printHumanReadableTime(int secs){
	if (secs >= 3600){
		cout << secs/3600 << " timer, ";
	}
	if (secs >= 60){
		cout << (secs%3600)/60 << " minutter og ";
	}
	cout << secs%60 << " sekunder.\n";
}
// ======= ..END OPPGAVE 1 FUNCTIONS ======= 
// ======= BEGIN OPPGAVE 2 FUNCTIONS ======= 
void printSumOfNums(){ // 2A
	int antall = 0;
	int tallsum = 0;
	cout << "Velg antall tall: ";
	cin >> antall;
	for (int i=0; i< antall; i++){
		int tmpnum = 0;
		cout << "Skriv inn et tall: ";
		cin >> tmpnum;
		tallsum += tmpnum;
	}
	cout << "Summen av tallene ble " << tallsum << '\n';
}
void printSumCloseZero(){
	bool fortsett = true;
	int tallsum = 0;
	while (fortsett){
		int inputTall;
		cout << "Skriv et tall, avslutt med 0: ";
		cin >> inputTall;
		tallsum += inputTall;
		if (inputTall == 0){
			fortsett = false;
		}
	}
	cout << "Summen av tallene ble " << tallsum << '\n';
}
/*
2C) Bruker for loop i 2A, da vi har et fiksert
	antall iterasjoner. 
2D)	Bruker en while, siden den skal avslutte dersom en
	conditional er tilfresstilt, ellers fortsette.
*/

double inputDouble(){
	double x;
	cout << "Skriv inn et desimaltall: ";
	cin >> x;
	return x;
}

void CrownToEur(){
	double NOK = inputDouble();
	while (NOK < 0){
		NOK = inputDouble();
	}
	cout << "Prisen i EUR blir " << setprecision(3) << fixed << NOK/9.75  << '\n';
}
/*
Valgte inputDouble siden int 10/9.5=1 men double 10/9.5=1,05
*/

// ======= ..END OPPGAVE 2 FUNCTIONS ======= 
// ======= BEGIN OPPGAVE 3 FUNCTIONS ======= 
void multTable(){
	int tableH = 0;
	int tableW = 0;
	cout << "Enter height: ";
	cin >>tableH;
	cout << "Enter width: ";
	cin >> tableW;
	for (int i=1; i<=tableH;i++){
		for (int j=1; j<=tableW;j++){
			cout << setw(5) << j*i;
		}
		cout << '\n';
	}
}
// ======= ..END OPPGAVE 3 FUNCTIONS ======= 
// ======= BEGIN OPPGAVE 4 FUNCTIONS ======= 
double discriminant(double a, double b, double c){
	return pow(b,2)-4*a*c;
}
void printRealRoots(double a, double b, double c){
	double disc = discriminant(a,b,c);
	if (disc< 0){
		cout << "Ingen reelle l" << oe << "sninger\n";
	}
	else if (disc==0){
		cout << "Én l" << oe <<"sning, x=" << (-b)/(2*a) <<'\n';
	}
	else{
		double x1 = (-b+sqrt(disc))/(2*a);
		double x2 = (-b-sqrt(disc))/(2*a);
		cout << "L" << oe << "sninger, x=" << x1 << " og x=" << x2 << '\n';
	}

}
void solveQuadraticEquation(){
	cout << "Skriv inn andregradsuttrykk: \nForan x^2: ";
	double a;
	double b;
	double c;
	cin >> a;
	cout << "foran x: ";
	cin >> b;
	cout << "konst: ";
	cin >> c;
	printRealRoots(a,b,c);
}
// ======= ..END OPPGAVE 4 FUNCTIONS ======= 
// ======= BEGIN OPPGAVE 5 FUNCTIONS ======= 
void pythagoras(){
	using namespace Graph_lib;
	Simple_window win{Point{100,100},400,400,"Pythagoras"};
	Polygon rightTriangle;
	rightTriangle.add(Point{128,267});
	rightTriangle.add(Point{225,267}); // Tegner trekant
	rightTriangle.add(Point{128,150});
	rightTriangle.set_fill_color(Color::red);
	win.attach(rightTriangle);

	Polygon leftSquare; //Tegner firkant til venstre
	leftSquare.add(Point{128,267});
	leftSquare.add(Point{128,150});
	leftSquare.add(Point{11,150});
	leftSquare.add(Point{11,267});
	leftSquare.set_fill_color(Color::green);
	win.attach(leftSquare);

	Polygon btmSquare; //Tegner firkant nederst
	btmSquare.add(Point{128,267});
	btmSquare.add(Point{225,267});
	btmSquare.add(Point{225,364});
	btmSquare.add(Point{128,364});
	btmSquare.set_fill_color(Color::yellow);
	win.attach(btmSquare);

	Polygon hypSquare; //Tegner firkant til hypotenus
	hypSquare.add(Point{225,267});
	hypSquare.add(Point{128,150}); //lengde 152
	hypSquare.add(Point{245,53});
	hypSquare.add(Point{342,170});
	hypSquare.set_fill_color(Color::blue);
	win.attach(hypSquare);

	win.wait_for_button();

}
// ======= ..END OPPGAVE 5 FUNCTIONS ======= 
// ======= BEGIN OPPGAVE 6 FUNCTIONS ======= 
vector<double> calculateSeries(double amount, double interest, double yrs){
	double remaining = amount;
	vector<double> betalingsplan;
	for (int i=0; i<yrs;i++){
		betalingsplan.push_back(amount/yrs+interest/100*remaining);
		remaining -= amount/yrs;
	} 
	cout << '\n';
	return betalingsplan;
}

vector<double> calculateAnnuity(double amount, double interest, double yrs){
	double innb = amount*(interest/100)/(1-pow(1+interest/100,-yrs));
	innb = static_cast<int>(innb); //Fjerner desimal forhåpentligvis
	vector<double> betalingsplan;
	for (int i=0; i<yrs; i++){
		betalingsplan.push_back(innb);
		//cout << setw(2) << i+1 << setw(15) << innb << '\n';
	}
	return betalingsplan;
}

void comparison(double amount, double interest, double yrs){
	cout << "Ar" << setw(20) << "Annuitet" << setw(20) << "Serie" << setw(20) << "Differanse\n";
	double paymentA; //Hvor mye annuitetslån er på ved termin i
	double paymentS; //Hvor mye serielån er på ved termin i
	double counterA; //Teller hvor mye du betaler totalt ved annuitetslån
	double counterS; //Teller hvro mye du betaler totalt ved serielån
	double remaining = amount;
	for (int i=0; i<yrs; i++){
		paymentA = static_cast<int>(amount*(interest/100)/(1-pow(1+interest/100,-yrs)));
		paymentS = amount/yrs+interest/100*remaining;
		counterA += paymentA;
		counterS += paymentS;
		remaining -= amount/yrs;
		cout << setw(2) << i+1 << setw(20) << paymentA << setw(20) << paymentS << setw(20) << paymentA-paymentS << '\n';
	}
	cout << "Total" << setw(17) << counterA << setw(20) << counterS << setw(20) << counterA-counterS << '\n';
}
void Veccomparison(double amount, double interest, double yrs){
	cout << "Ar" << setw(20) << "Annuitet" << setw(20) << "Serie" << setw(20) << "Differanse\n";
	vector<double> annuity = calculateAnnuity(amount,interest,yrs);
	vector<double> serielan = calculateSeries(amount,interest,yrs);
	double totalAnn = 0;
	double totalSer = 0; 
	for (int i=0; i<yrs;++i){
		cout << setw(2) << i+1 << setw(20) << annuity[i] << setw(20) << serielan[i] << setw(20) << annuity[i]-serielan[i] << '\n';
		totalAnn += annuity[i];
		totalSer += serielan[i];
	}
	cout << "Total" << setw(17) << totalAnn << setw(20) << totalSer << setw(20) << totalAnn-totalSer << '\n';

}



// ======= ..END OPPGAVE 6 FUNCTIONS ======= 

int main()
{
	int choice = 1;
	while (choice != 0){
		cout << "Velg funksjon: \n";
		cout <<"0) Avslutt \n";
		cout <<"1) Summer to tall \n";
		cout <<"2) Summer flere tall \n";
		cout <<"3) Konverter NOK til EUR \n";
		cout <<"4) Gangetabell\n"; // Tar alt på hver sin linje for det er mer oversiktlig:))
		cout <<"5) L" << oe << "s andregradslikning\n";
		cout <<"6) Pythagoras grafisk\n";
		cout <<"7) Sammenlikning serie og annuitet\n";
		cout <<"Angi valg (0-7): ";
		cin >> choice;
		if (choice == 1){
			inputIntegersAndPrintSum();
		}
		else if (choice == 2){
			printSumCloseZero();
		}
		else if (choice == 3){
			CrownToEur();
		}
		else if (choice==4){
			multTable();
		}
		else if (choice == 5){
			solveQuadraticEquation();
		}
		else if (choice ==6){
			pythagoras();
		}
		else if (choice == 7){
			Veccomparison(10000,3,10);
		}
	}
	keep_window_open();
}

/*
	OPPGAVE 1
	inputAndPrintInteger(); //a
	int number = inputInteger(); //b
	cout << "Du skrev: " << number << '\n'; //b
	inputIntegersAndPrintSum(); // c
	//d: Valgte inputInteger(), siden den returnerer tallet.
	// Det er fordelsaktig når man skal behandle input-svaret videre, som vi gjør her

		for (int i=0; i<16; i++){
		cout << i << ": ";
		if (isOdd(i)){
			cout << "Oddetall \n";
		}
		else{
			cout << "Partall \n";
		}
	}
	printHumanReadableTime(10000);
	printHumanReadableTime(5);
	printHumanReadableTime(2000); 


	//2
	printSumOfNums();
	printSumCloseZero();
	cout << inputDouble();
	CrownToEur();

*/
