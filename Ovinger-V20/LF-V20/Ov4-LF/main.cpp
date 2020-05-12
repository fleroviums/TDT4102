
#include "std_lib_facilities.h"
#include "mastermind.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	playMastermind();
	return gui_main();
}

