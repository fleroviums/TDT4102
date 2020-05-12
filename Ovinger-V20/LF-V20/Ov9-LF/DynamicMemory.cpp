#include <iostream>
#include "DynamicMemory.h"

using namespace std;

void fillInFibonacciNumbers(int result[], int length) {
	result[0] = 0;

	if (length == 1) {
		return;
	}

	result[1] = 1;

	if (length <= 2) {
		return;
	}

	for (int i = 2; i < length; i++) {
		result[i] = result[i - 1] + result[i - 2];
	}
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void createFibonacci() {
	cout << "How many Fibonacci numbers should be generated?" << endl;
	int length;
	cin >> length;

	int *result = new int[length]; // Allokerer plass til length antall heltall
	fillInFibonacciNumbers(result, length);

	std::cout << "The Fibonacci numbers:" << std::endl;
	printArray(result, length);

	delete[] result; // Frigjør minnet når vi ikke trenger det lenger
}
