// Oversettelse fra Python eller Matlab til C++
#include "std_lib_facilities.h"

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

int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for (int x = 1; x <= n; ++x) {
		cout << x << ' ' << b << '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}

int squareNumberSum(int number)
{
	int totalSum = 0;
	for (int index = 0; index < number; ++index) {
		totalSum += index * index; // pow(index, 2)

		cout << index * index << '\n';
	}
	cout << totalSum << '\n';
	return totalSum;
}

void triangleNumbersBelow(int number)
{
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << number << ":\n";
	while (acc < number) {
		cout << acc << '\n';
		acc += num;
		++num;
	}
	cout << '\n';
}

bool isPrime(int number)
{
	for (int divisor = 2; divisor < number; ++divisor) {
		if (number % divisor == 0) {
			return false;
		}
	}
	return true;
}

void naivePrimeNumberSearch(int maxNumber)
{
	for (int number = 2; number < maxNumber; ++number) {
		if (isPrime(number)) {
			cout << number << " is a prime\n";
		}
	}
}

int findGreatestDivisor(int number)
{
	for (int divisor = number - 1; divisor > 0; --divisor) {
		if (number % divisor == 0) {
			return divisor;
		}
	}
	return 1;
}

int main()
{

	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << "\n\n";

	cout << "Oppgave c)\n";
	cout << fibonacci(20) << "\n\n";

	cout << "Oppgave d)\n";
	cout << squareNumberSum(9) << "\n\n";

	cout << "Oppgave e)\n";
	triangleNumbersBelow(33);

	cout << "Oppgave f)\n7 is a prime: " << isPrime(7)
	     << ", 33 is a prime: " << isPrime(33) << "\n\n";

	cout << "Oppgave g)\n";
	naivePrimeNumberSearch(33);

	cout << "\nOppgave h)\nGreatest Divisor of 84: " << findGreatestDivisor(84)
	     << ", Greatest Divisor of 983: " << findGreatestDivisor(983) << '\n';
	
	keep_window_open();
}
