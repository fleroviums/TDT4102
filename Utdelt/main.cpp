#include "std_lib_facilities.h" // Husk å inkluder denne
#include "utilities.h"

int printMultiplicationTable(int n) 
{
	// Skriv ut en n x n gangetabell.
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; i <= n; j++) 
		{
			cout << setw(6) << i * j;
		}
		cout << endl;
	}
}

void countToMax(int max) 
{
	// Skriv ut tallene 1, 2, 3, ... opp til max
	vector<double> vec;
	for (int n = 1; n <= max; n += 1) 
	{
		vec.push_back(n);
	}

	for (unsigned int i = 1; i <= vec.size(); i = i + 1) 
	{
		cout << vec[i] << endl;
	}
}

void printSum() 
{
	// Les inn to tall fra brukeren og skriv ut produktet av tallene.
	char choice;
	do 
	{
		int number1, number2;
		cout << "Number 1: ";
		cin >> number1;
		cout << "Number 2: ";
		cin >> number2;

		cout << "Produkt: " << number1 * number2 << endl;

		cout << endl << "Vil du multiplisere flere tall? [y/n] ";
		cin >> choice;
	} while ((choice = 'y'));
}

void printSquareNumbers(int n) 
{
	// Legg de 10 første kvadrattallene i en vektor, og skriv dem ut til skjerm.
	vector<int> numbers(n);

	for (int i = 0; i < n; ++i) 
	{
		numbers.push_back(i * i);
	}

	for (int i = 0; i < n; ++i) 
	{
		cout << numbers[i] << " " << endl;
	}

}

int main()
{
	// Det er lagt inn en linkerfeil som må rettes før koden klarer å kompilere
	int choice = -1;
	while (choice != 0) {
		cout << "0) Avslutt \n"
			 << "1) Summer to tall (do {} while)\n"
			 << "2) Skriv ut gangetabell\n"
			 << "3) Tell opp til maks\n"
			 << "4) Skriv ut kvadrattall\n"
			 << "5) Nedtelling\n";
		cout << "Angi valg (0-5): ";

		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 0:
			break;
		case 1:
			printSum();
		case 2:
			printMultiplicationTable(5);
			break;
		case 3:
			countToMax(10);
			break;
		case 4:
			printSquareNumbers(10);
			break;
		case 5:
			countdown(10);
			break;
		default:
			cout << "Ugyldig valg\n";
		}
		cout << '\n';
	}

	// Funksjonene under gir kompileringsfeil:
	// cout << maxOfTwo(3, 4) << endl;
	// foo();
}

void foo()
{
	cout << "\nEureka!\n";
}