#include "CourseCatalog.h"

void CourseCatalog::addCourse(const string& code, const string& name)
{
	// courses.insert({code, name}); // overskriver ikke
	courses[code] = name; // kan oppdatere navn
}

void CourseCatalog::removeCourse(const string& code)
{
	// PPP chapter B.4.7. alle beholdere har disse operasjonen
	courses.erase(code);
}

string CourseCatalog::getCourse(const string& code) const
{
	return courses.at(code);
}

ostream& operator<<(ostream& os, const CourseCatalog& cc)
{
	for (const auto& c : cc.courses)
		os << c.first << ", " << c.second << '\n';

	return os;
}

void CourseCatalog::saveToFile(const string& filename) const
{
	ofstream out{filename};

	if (!out)
		error("Couldn't open file: ",filename);

	for (const auto& c : courses)
		out << c.first << ", " << c.second << '\n';
	// for-lokken over er akkurat den samme som i operator<<().
	// For aa unngaa aa duplisere denne koden folgende metode brukes:
	// Det vil bli forelest litt senere i kurset og er relevant til eksamen.
	// Utskriftsoperatoren kan gjenbrukes, istedetfor aa duplisere for-lokken.
	// Vi skriver ut "objektet selv":
	// this: en peker til objektet som saveToFile() kalles paa.
	// *this: dereferering av this-pekeren. Det vil si: vi folger pekeren og velger "dette" objektet.
	// Du kan tenke paa det som at *this er objektet du befinner deg i. Det gir kodelinjen:
	// out << *this; // betyr derfor at du kaller utskriftsoperatoren til _dette_ objektet.
}

void CourseCatalog::loadFromFile(const string& filename)
{
	ifstream in{filename};
	
	if (!in)
		error("Couldn't open file: ",filename);
	
	// Tommer courses for man leser data fra fil
	courses.clear();

	string line;
	while (getline(in, line)) {
		stringstream ss{line};

		string emneKode;
		string emneNavn;

		// Fetch the two parts of the line separated by comma ','
		getline(ss, emneKode, ',');
		getline(ss, emneNavn, ',');

		// fjerner whitespace (1 tegn paa begynnelsen av string)
		emneNavn = emneNavn.substr(1);

		courses[emneKode] = emneNavn;
	}
}
