
#include "std_lib_facilities.h"

//a Største av to tall 
int maxOfTwo(int a, int b){
	if(a>b){
		cout << "A is greater than B";
		return a;
	}
	else{
		cout << "B is greater than or equal to A";
		return b;
	}
}
int fibonacci(int n){
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for(int x=1; x<n+1; x++){
		cout << x << "  " << b << '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "---- \n";
	return b;
}
int squareNumberSum(int n){
	int totalSum = 0;
	for (int i = 0; i < n; i++){
		totalSum += i*i;
		cout << i*i << ' ';
	}
	cout << totalSum;
	return totalSum;
}
int triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":\n";
	while(acc < n){
		cout << acc << ", ";
		acc += num;
		num += 1;
	}
	cout << "\n";
	return 0;
}
bool isPrime(int n){
	for(int j=2; j<n;j++){
		if(n%j == 0){
			return false;
		}
	}
	return true;
}
int naivePrimeNumberSearch(int n){
	for (int number=2;number<n;number++){
		if(isPrime(number)){
			cout << number << " is a prime \n";
		}
	}
	return 0;
}
int findGreatestDivisor(int n){
	for(int divisor = n-1; divisor > 0; divisor-=1){
		if(n%divisor == 0){
			return divisor;
		}
	}
	return -1;
}


int main()
{
	cout << "Oppgave a)\n";
	maxOfTwo(5,6); 
	cout << '\n';
	cout << "Oppgave c)\n";
	cout << fibonacci(20) << '\n';
	cout << "Oppgave d)\n";
	squareNumberSum(3);
	cout << '\n';
	cout << "Oppgave e)\n";
	triangleNumbersBelow(20);
	cout << '\n';
	cout << "Oppgave f)\n (0 er false og 1 er true)";
	cout << isPrime(21) << " " << isPrime(13) << '\n';
	cout << "Oppgave g)\n";
	naivePrimeNumberSearch(13);
	cout << '\n';
	cout << "Oppgave h)\n";
	cout << findGreatestDivisor(40) << '\n';

	keep_window_open();
}



