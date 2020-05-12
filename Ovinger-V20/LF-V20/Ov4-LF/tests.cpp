#include "std_lib_facilities.h"
#include "tests.h"

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesRef(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << '\n';
}

void testVectorSorting()
{
	vector<int> percentages;
	randomizeVector(percentages, 24);
	cout << "Random sequence of percentage values:\n";
	for (int n : percentages)
		cout << n << " ";
	cout << '\n';

	// swapNumbers(percentages[0], percentages[1]); // 2d)

	// for 3b
	cout << "The median of the vector is: " << fixed << setprecision(2)
		 << medianOfVector(percentages) << '\n';

	sortVector(percentages);
	cout << "Sorted sequence:\n";
	for (int n : percentages)
		cout << n << " ";
	cout << '\n';

	cout << "The median of the vector is: " << fixed << setprecision(2)
		 << medianOfVector(percentages) << '\n';
}

void testString()
{
	static constexpr int numGrades = 8;
	string grades{randomizeString(numGrades, 'A', 'F')};
	cout << "Random grades: " << grades << '\n';

	// h)
	vector<int> gradeCount(6);
	int score = 0;
	for (int i = 0; i < 6; ++i) {
		gradeCount[i] = countChar(grades, 'A' + i);
		score += (5 - i) * gradeCount[i];
	}

	double gpa = score / double{numGrades}; // gpa = grade point average
	cout << "Grade point average = " << fixed << setprecision(1) << gpa << '\n';
}
