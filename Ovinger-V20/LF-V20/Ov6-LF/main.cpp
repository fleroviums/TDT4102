#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "FileUtils.h"
#include "Temps.h"

void testCourseCatalog();

int main()
{
	// Skriv bruker input til fil
	//writeUserInputToFile();
	
	//leser fra fil og skriver innholdet til ny fil,<filename>.linum med linjenummer 

	//addLineNumbers("outputfile.txt");

	characterStatistics("grunnlov.txt");
	cout << "\n\n";


	/** Korrekt output for tegnstatistikk
		a: 1923	b: 353	c: 131	
		d: 1768	e: 4569	f: 709	
		g: 1355	h: 523	i: 1658	
		j: 149	k: 538	l: 1433	
		m: 867	n: 2198	o: 1264	
		p: 225	q: 2	r: 2230	
		s: 1863	t: 2145	u: 320	
		v: 522	w: 13	x: 9	
		y: 108	z: 6
	 **/



	// Leser tempraturer fra fil, og vise graf 

	string tempsFile = "temperatures.txt";
	graphTemps(tempsFile);
	keep_window_open();
}

void testCourseCatalog() {
	CourseCatalog cc;
	string filename = "coursecatalog.txt";

	// CourseCatalog::loadFromFile() vil kaste et unntak hvis filen ikke eksiterer
	try {
		cc.loadFromFile(filename);
		cout << "These courses are already in the catalog loaded from " << filename << ":\n";
		cout << cc;
	}
	
	 catch (exception& e) {
		std::cout << e.what() << '\n';
	}


	cout << "\nAdding/updating the catalog.\n";
	cc.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	cc.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	cc.addCourse("TMA4100", "Matematikk 1");
	cout << cc;

	cout << "\nUpdating course name for TDT4102:\n";
	cc.addCourse("TDT4102", "C++");
	cout << cc;

	cc.saveToFile(filename);
	cout << "\nCourse catalog is stored in " << filename << '\n';
}

