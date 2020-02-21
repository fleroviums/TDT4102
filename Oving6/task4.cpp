#include "std_lib_facilities.h"
#include "task4.h"
#include "Graph.h"
#include "Simple_window.h" // Do i have to include these in task4 and main.cpp?

istream& operator>>(istream& is, Temps& t){
    is >> t.max >> t.min;
    return is;
}
ostream & operator<<(ostream & os, vector<Temps>& temps)
{
	for (const auto t : temps)
	{
		os << t.max << '\t' << t.min << '\n';
	}
	return os;
}


vector<Temps> readTemps(string inFile){ // Mainly debug purposes
    ifstream ist{inFile};
    vector<Temps> tempVec;
    if(!ist){error("Unable to load file ", inFile);}
    string l;
    while(getline(ist,l)){
        Temps tTemp;
        ist >> tTemp.max >> tTemp.min;
        tempVec.push_back(tTemp);
    }
    return tempVec;
}



/* BEGIN TASK 5
    NOTE,  INSPIRED BY GRAPH3.CPP FROM NATVIG
*/

float getMaximaTemp(vector<Temps> tempsVec, bool checkMax){ // max=true, min=false
    float returnVal = 0;
    for (auto tempObj : tempsVec){
        if(checkMax && tempObj.max > returnVal){
            returnVal = tempObj.max;
        }
        else if (!checkMax && tempObj.min < returnVal)
        {
            returnVal = tempObj.min;
        }
    }
    return returnVal;
}

vector<double> distinguishMaxima(vector<Temps> allTemps, bool checkMax){
    vector<double> returnVec;
    if(checkMax){
        for (auto el : allTemps){
            returnVec.push_back(el.max);
        }
        return returnVec;
    }
    else{
        for (auto el : allTemps){
            returnVec.push_back(el.min);
        }
        return returnVec;
    }
}

constexpr int xAxisSize = 800;
constexpr int yAxisSize = 400;
constexpr int maxMonthNo = 365;

int xCoord(Point origo, int i) {
	return(origo.x + ((i * xAxisSize) / maxMonthNo));
}
int yCoord(Point origo, int temp, int totalMin, int ySpan) {
	return(origo.y - (yAxisSize * (temp - totalMin)) / ySpan);
}

void drawTemp() {
	Point tl{ 100, 100 }; // tl is Top-Left corner of our window
	Point origo{ 40, 450 };
	Simple_window win{tl, 1000, 500, " Temperature graph "};
	Axis xa{Axis::x, origo, xAxisSize, maxMonthNo, ""};
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya{Axis::y, origo, yAxisSize, 7, ""};
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

    vector<Temps> allTemps;
    allTemps = readTemps("temperatures.txt"); // Gets all temps from txt-file
    vector<double> minTemp = distinguishMaxima(allTemps,false); //Stores all min values in minTemp-vector
    vector<double> maxTemp = distinguishMaxima(allTemps,true); // Store all max values [...]
	int totalMax = getMaximaTemp(allTemps,true); // maxtemp>=mintemp always
	int totalMin = getMaximaTemp(allTemps,false);
	int ySpan = totalMax - totalMin;

	Open_polyline oplMax;
	for (unsigned int i = 0; i < maxTemp.size(); i++) {
		//cout << "added point in " << i;
		oplMax.add(Point{ xCoord(origo,i), yCoord(origo, maxTemp[i], totalMin, ySpan) });
	}
	oplMax.set_color(Color::red);
	win.attach(oplMax);

	Open_polyline oplMin;
	for (unsigned int i = 0; i < minTemp.size(); i++) {
		oplMin.add(Point{ xCoord(origo,i), yCoord(origo, minTemp[i], totalMin, ySpan) });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	vector<string> yxTxt = {"-20", "-10", "0", "10", "20"};
	Text thisTxt1{Point{origo.x-15, 50}, "20"};
	Text thisTxt2{Point{origo.x-15, 150}, "10"};
	Text thisTxt3{Point{origo.x-15, 250}, "0"};
	Text thisTxt4{Point{origo.x-15, 350}, "-10"};
	Text thisTxt5{Point{origo.x-15, 450}, "-20"};
	thisTxt1.set_color(Color::black);
	thisTxt2.set_color(Color::black);
	thisTxt3.set_color(Color::black);
	thisTxt4.set_color(Color::black);
	thisTxt5.set_color(Color::black);
	win.attach(thisTxt1);
	win.attach(thisTxt2);
	win.attach(thisTxt3);
	win.attach(thisTxt4);
	win.attach(thisTxt5);

	Text maxTxt{ Point{200,100}, "Max" };
	Text minTxt{ Point{200,400}, "Min" };
	maxTxt.set_color(Color::red);
	minTxt.set_color(Color::blue);
	win.attach(maxTxt);
	win.attach(minTxt);



	win.wait_for_button();
};