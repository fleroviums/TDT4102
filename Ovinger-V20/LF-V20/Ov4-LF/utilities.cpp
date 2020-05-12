#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;
}

void swapNumbers(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void randomizeVector(vector<int>& vec, int n)
{
	for (int i = 0; i < n; ++i)
		vec.push_back(rand() % 101);
}

void sortVector(vector<int>& vec)
{
	// Insertion sort, implementasjon fra wikipedia pseudocode
	for (unsigned int i = 1; i < vec.size(); ++i) {
		for (int j = i; 0 < j && vec[j - 1] > vec[j]; --j) {
			swapNumbers(vec[j], vec[j - 1]);
		}
	}
}

double medianOfVector(const vector<int>& vec)
// Precondition: vec er sortert.
// Postcondition: partall n: gjennomsnittsverdi av de to midterste elementene i vectoren
//odde n: midterste element.
{
	if (vec.size() % 2 == 0) {
		// Partall antall elementer i vectoren
		int m = static_cast<int>(vec.size() / 2 - 1);
		int n = static_cast<int>(vec.size() / 2);
		return static_cast<double>((vec[m] + vec[n]) / 2.0);
	}

	return static_cast<double>(vec[static_cast<int>(vec.size() / 2)]);
}

string randomizeString(int n, char lower, char upper)
{
	string str;
	for (int i = 0; i < n; ++i)
		str += lower + (rand() % (upper - lower));

	return str;
}

string readInputToString(unsigned int n, char lower, char upper)
{
	string str;
	//Variabelen ch er introdusert i for-lokkens scope. Generelt er et mindre scope bedre,
	// saa lenge er mulig.
	// I hver iterasjon, sjekk at n ikke er lik 0, og les tegne til ch

	// Grensene konverteres også til store bokstaver for avgrensingen
	lower = toupper(lower);
	upper = toupper(upper);
	
	for (char ch; str.size() < n && cin >> ch; ) {
		// hopp over tegn som ikke er alfanumerisk
		if (isalnum(ch)) {
			ch = toupper(ch); // endre til stor bokstav
			if (lower <= ch && ch <= upper) {
				str += ch;
			}
		}
	}

	// forkast overflowing input paa samme linje
	cin.clear();
	cin.ignore(255, '\n');

	return str;
}

int countChar(string str, char ch)
{
	int n = 0;
	for (char c : str) {
		if (c == ch) {
			++n;
		}
	}

	return n;

	// STL algorithm
	// return count(str.begin(), str.end(), ch);
}

void printStudent(Student student){
	cout<< "Name: " <<student.name << ", age: " << student.age <<", studyprogram: " 
	<< student.studyProgram <<'\n'; 
}
