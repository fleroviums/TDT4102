#include "std_lib_facilities.h"
#include "task2.h"

int main()
{
	cout << "Hello, World!\n";
	vector<double> x;
	vector<double> y;
	read_csv("data.csv", x, y);
	for(int i=0;i<x.size();++i){
		cout << "x: " << x[i] << ", y: " << y[i] << endl;
	}
	cout << "\nDone w loop";
	keep_window_open();
}
