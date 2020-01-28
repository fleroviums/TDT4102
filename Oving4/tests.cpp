#include "std_lib_facilities.h"
#include "utilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << '\n';
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << '\n';
}

void testSwapNumbers(){
    int num1 = 4;
    int num2 = 5;
    vector<int> result {swapNumbers(num1, num2)};
    cout << "num1: " << num1
    << " num2: " << num2
    << " result: " << result[0] << ", " << result[1] << '\n';
}
void testVectorSorting(){
    vector<int> percentages;
    cout << "percentages innhold: ";
    printIntVec(percentages);
    vector<int> newVec = randomizeVector(percentages, 10);
    cout << "percentages innhold nå: ";
    printIntVec(percentages);


    // Easy swapping
    swapNumbers(percentages[0], percentages[1]);
    cout << "percentages etter swap: ";
    printIntVec(percentages);
}