#include "std_lib_facilities.h"
#include "task2.h"

//1 - Kodeforståelse
/*
1a)		33
1b)		20 21 0 (X)
1c)		191-12 (X)
1d)		14 Gull14 Sull11Bull
1e)		71 
1f)		2 1 3 4 7 
1g)		

*/

// C++ programs start by executing the function main
int main()
{
	cout << "Hello, World!\n";
	Date d1;
	d1.d = 31;
	d1.m = 1;
	d1.y = 2020;
	Event ev1;
	ev1.id = 1; ev1.name = "meeting 1"; ev1.when = d1;
	vector<Event *> events; events.push_back(&ev1);
	printEvents(events); 
	keep_window_open();
}

//------------------------------------------------------------------------------
