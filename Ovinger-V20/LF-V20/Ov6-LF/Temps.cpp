#include "Temps.h"
#include "TempsDrawer.h"

istream& operator>>(istream& is, Temps& t)
{
	return is >> t.max >> t.min;
}

void graphTemps(string filename)
{
	ifstream ifs{filename};
	if (!ifs)
		error("Couldn't open file: ",filename);

	vector<Temps> temps;
	for (Temps t; ifs >> t;)
		temps.push_back(t);

	drawMaxMin(temps);
}
