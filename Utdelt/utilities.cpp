#include "utilities.h"
#include <thread> // For sleep_for, IKKE pensum
#include <chrono> // For seconds, IKKE pensum

int maxOfTwo(int a, int b)  
{
	if (a > b) {
		cout << "A is greater than B\n";
		return a;
	} else {
		cout << "B is greater than or equal to A\n";
		return b;  
	}
}

void countdown(unsigned int start)
{
    while (start >= 0)
    {
        cout << start-- << endl;
        this_thread::sleep_for(chrono::seconds(1)); 
        // Linjen ovenfor er korrekt og nyttig, men IKKE pensum :)
    }
    cout << "Lift off!\n";
}











int main() 
{
    // Unnyttlig main() gjemt i en fil
    return 0;
}