#include "std_lib_facilities.h"
#include "Blackjack.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Blackjack bj;
	bj.playGame();

	keep_window_open();
}

