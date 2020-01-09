//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	using namespace Graph_lib;
	cout << "The New \"Hello, Graphical World!\" message \n";
	Point tl{100, 100};
	Simple_window win{ tl, 600, 400, "Canvas"};

	Polygon poly;
	poly.add(Point{ 30, 200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);

	win.attach(poly);
	win.wait_for_button();

}

//------------------------------------------------------------------------------
