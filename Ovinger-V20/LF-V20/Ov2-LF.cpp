#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

void inputAndPrintInteger()
{
	int number = 0;
	cout << "Skriv inn et tall: ";
	cin >> number;
	cout << "Du skrev: " << number << '\n';
}

int inputInteger()
{
	int number = 0;
	cout << "Skriv inn et tall: ";
	cin >> number;
	return number;
}

void inputIntegersAndPrintSum()
{
	int firstNumber = inputInteger();
	int secondNumber = inputInteger();
	cout << "Summen av tallene: " << firstNumber + secondNumber << '\n';
}

bool isOdd(int n)
{
	return n % 2;
}

void testIsOdd()
{
	for (int i = 0; i <= 15; ++i) {
		if (isOdd(i)) {
			cout << i << " er et oddetall.\n";
		} else {
			cout << i << " er et partall.\n";
		}
	}
}

void printHumanReadableTime(int seconds)
{
	int hours = seconds / 3600;
	seconds = seconds % 3600; // Antall sekunder over hele timer
	int minutes = seconds / 60;
	seconds = seconds % 60; // Antall sekunder over hele minutter

	cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder.\n";
}
void printHumanReadableTime_V2(int seconds)
{
	// Versjon 2 av denne funksjonen, som skriver ut grammatisk korrekt
	// Kreves ikke for godkjent oving

	int hours = seconds / 3600;
	seconds = seconds % 3600; // Antall sekunder over hele timer
	int minutes = seconds / 60;
	seconds = seconds % 60; // Antall sekunder over hele minutter
	string multiHour;
	string multiMinutes;
	string multiSeconds;
	if (hours != 1)
		multiHour = "r";
	if (minutes != 1)
		multiMinutes = "er";
	if (seconds != 1)
		multiSeconds = "er";

	if (hours > 0)
		cout << hours << " time" << multiHour << ", ";
	if (minutes > 0)
		cout << minutes << " minutt" << multiMinutes << " og ";
	cout << seconds << " sekund" << multiSeconds << ".\n";
}


void testPrintHumanReadableTime()
{
	int nSeconds = inputInteger();
	printHumanReadableTime(nSeconds);
}

void testPrintHumanReadableTime_V2()
{
	int nSeconds = inputInteger();
	printHumanReadableTime_V2(nSeconds);
}



// 2a - for, beste egnet naar antall tall er kjent i forkant av lokken
void inputIntegersUsingForLoopAndPrintSum()
{
	int nTerms = 0;
	cout << "Hvor mange tall vil du summere? ";
	cin >> nTerms;

	int sum = 0;
	int term = 0;
	for (int i = 0; i < nTerms; i++) {
		term = inputInteger();
		sum += term;
	}
	cout << "Summen av tallene: " << sum << '\n';
}

// 2b - While, best egnet naar en avslutter med aa angi tallet 0
void inputIntegersUsingWhileLoopAndPrintSum()
{
	cout << "Skriv inn de tallene du vil summere.\n"
			"Skriver du inn 0 avsluttes lokken og summen skrives ut.\n";

	int sum = 0;
	int term = inputInteger();
	while (term != 0) {
		sum += term;
		term = inputInteger();
	}

	cout << "Summen av tallene: " << sum << '\n';
}

// 2b - Do-While, alternativ losning
// Merk at do-while lokken er ganske lite brukt og i PPP-boka er den ikke dekket, saa den er ikke
// pensum
void inputIntegersUsingDoWhileLoopAndPrintSum()
{
	cout << "Skriv inn tall du vil summere.\n"
			"Skriver du inn 0 avsluttes lokken og summen skrives ut.\n";

	int sum = 0;
	int term = 0;
	do {
		term = inputInteger();
		sum += term;
	} while (term != 0);

	cout << "Summen av tallene: " << sum << '\n';
}

double inputDouble()
{
	double number = 0;
	cout << "Skriv inn et tall: ";
	cin >> number;
	return number;
}

void convertNOKtoEUR()
{
	double nok = -1.0;
	while (nok < 0.0)
		nok = inputDouble();

	double eur = nok / 9.75; // Vekslingskurs bestemmer studentene selv
	cout << setprecision(2) << fixed << nok << " NOK er " << eur << " EUR\n";
}

void printMultiplicationTable()
{
	int height = 0;
	int width = 0;
	cout << "Hoyde: ";
	cin >> height;
	cout << "Bredde: ";
	cin >> width;
	for (int x = 1; x <= width; x++) {
		for (int y = 1; y <= height; y++) {
			cout << setw(8) << x * y;
		}
		cout << '\n';
	}
}

double discriminant(double a, double b, double c)
{
	return pow(b, 2.0) - 4.0 * a * c;
}

void printRealRoots(double a, double b, double c)
{
	double d = discriminant(a, b, c);
	if (d > 0.0) {
		double firstSolution = (-b + sqrt(d)) / (2.0 * a);
		double secondSolution = (-b - sqrt(d)) / (2.0 * a);
		cout << "Losning 1: " << firstSolution << '\n';
		cout << "Losning 2: " << secondSolution << '\n';
	} else if (d == 0.0) {
		double solution = -b / (2.0 * a);
		cout << "Losning: " << solution << '\n';
	} else /* (d < 0.0) */ {
		cout << "Ingen reelle losinger.\n";
	}
}

void solveQuadraticEquations()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "C: ";
	cin >> c;
	printRealRoots(a, b, c);
}

void pythagoras(){
	using namespace Graph_lib;
	
	Simple_window win{ Point{100, 100}, 600, 600, "Pythagoras" };

	Point init{ 225, 400 };
	int a = 150;
	int b = 200;
	//int c = sqrt(pow(a, 2) + pow(b, 2));

	Polygon poly; //Trekant
	poly.add(Point{ init.x, init.y });
	poly.add(Point{ init.x, init.y - b });
	poly.add(Point{ init.x + a, init.y });
	poly.set_fill_color(Color::black);
	win.attach(poly);

	Polygon poly2; //Firkant a
	poly2.add(init);
	poly2.add(Point{ init.x + a, init.y });
	poly2.add(Point{ init.x + a, init.y + a });
	poly2.add(Point{ init.x, init.y + a });
	poly2.set_fill_color(Color::red);
	win.attach(poly2);

	Polygon poly3; //Firkant b
	poly3.add(Point{ init.x, init.y });
	poly3.add(Point{ init.x, init.y - b });
	poly3.add(Point{ init.x - b, init.y - b });
	poly3.add(Point{ init.x - b, init.y });
	poly3.set_fill_color(Color::green);
	win.attach(poly3);

	Polygon poly4; //Firkant c
	poly4.add(Point{ init.x, init.y - b });
	poly4.add(Point{ init.x + b, init.y - b - a });
	poly4.add(Point{ init.x + a + b, init.y - a});
	poly4.add(Point{ init.x + a, init.y});
	poly4.set_fill_color(Color::blue);
	win.attach(poly4);

	win.wait_for_button();
}
vector<int> calculateAnnuity(int loan, int rate, int periods)
/* Annuitetslaan: variabel nedbetaling, variabel rente, konstant innbetaling
 * precondition:
 *  loan = positiv verdi av totalt laanebelop
 *  rate = rente i prosent, [0.0, 100.0] %
 *  periods = antall terminer
 */
{

	// Formel:
	//  loan = paymentn * (1 - (1+rate)^-periods) / rate , rate = [0, 1]
	//  => paymentn = loan * rate/(1-(1+rate)^-periods)

	vector<int> payments;
	int payment_n = static_cast<int>(loan * rate / 100 / (1 - pow(1 + rate / 100.0, -periods))); // innbetaling n

	for (int n = 0; n < periods; ++n) {
		payments.push_back(payment_n);
	}

	/* Alternativt
	int paymentn = loan * rate / 100 / (1 - pow(1 + rate / 100, -10)); // innbetaling n
	vector<int> payments(periods, paymentn);
	*/

	return payments;
}

vector<int> calculateSeries(int loan, int rate, int periods)
/* serielaan: konstant nedbetaling, variabel rentekostnad, variabel innbetaling
 * precondition:
 *  loan = positiv verdi av totalt laanebelop
 *  rate = rente i prosent, [0.0, 100.0] %
 *  periods = antall terminer
 */
{
	vector<int> payments;
	int rest{loan};					// gjenstaaende belop
	int repayment = loan / periods; // fast nedbetalingsbelop per termin
	int payment_n;					// innbetaling n

	for (int n = 0; n < periods; ++n) {
		payment_n = static_cast<int>(repayment + rate / 100.0 * rest);
		rest -= repayment;
		payments.push_back(payment_n);
	}

	return payments;
}

void comparePlans(int loan, int rate, int periods)
{
	vector<int> annuity = calculateAnnuity(loan, rate, periods);
	vector<int> series = calculateSeries(loan, rate, periods);

	cout << right; // padding til venstre, utskrift til hoyre, se appendix B.7.6 i PPP

	cout << setw(3) << "Aar" << setw(15) << "Annuitet" << setw(15) << "Serie" << setw(15)
		 << "Differanse\n";

	int diff = 0;
	int totalDiff = 0;
	for (int i = 0; i < periods; ++i) {
		diff = annuity[i] - series[i];
		totalDiff += diff;
		cout << setw(3) << i + 1 << setw(15) << annuity[i] << setw(15) << series[i] << setw(15)
			 << diff << '\n';
	}

	int totalAnnuity = 0;
	for (int a : annuity) { // range-for loop
		totalAnnuity += a;
	}

	int totalSeries = 0;
	for (int s : series) {
		totalSeries += s;
	}

	cout << "Total" << setw(13) << totalAnnuity << setw(15) << totalSeries << setw(15) << totalDiff
		 << '\n';
}



int main()
{

	int choice = -1;
	while (choice != 0) {
		cout << "0) Avslutt \n"
			 << "1) Summer to tall\n"
			 << "2) Test oddetallsfunksjonen\n"
			 << "3) Konverter sekunder\n"
			 << "4) Summer flere tall (for)\n"
			 << "5) Summer flere tall (while)\n"
			 << "6) Summer flere tall (do-while)\n"
			 << "7) Konverter NOK til EURO\n"
			 << "8) Skriv ut gangetabell\n"
			 << "9) Los kvadratiske ligninger\n"
			 <<	"10) Pythagoras\n"
			 << "11) Sammenlign nedbetalingsplaner\n";
		cout << "Angi valg (0-11): ";

		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 0:
			break;
		case 1:
			inputIntegersAndPrintSum();
			break;
		case 2:
			testIsOdd();
			break;
		case 3:
			testPrintHumanReadableTime();
			testPrintHumanReadableTime_V2();
			break;
		case 4:
			inputIntegersUsingForLoopAndPrintSum();
			break;
		case 5:
			inputIntegersUsingWhileLoopAndPrintSum();
			break;
		case 6:
			inputIntegersUsingDoWhileLoopAndPrintSum();
			break;
		case 7:
			convertNOKtoEUR();
			break;
		case 8:
			printMultiplicationTable();
			break;
		case 9:
			solveQuadraticEquations();
			break;
		case 10:
			pythagoras();
			break;
		case 11:
			comparePlans(10000, 3, 10);
			break;
		default:
			cout << "Ugyldig valg\n";
		}
		cout << '\n';
	}
}