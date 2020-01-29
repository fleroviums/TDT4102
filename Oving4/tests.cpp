#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

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
    swapNumbers(num1, num2);
    cout << "num1: " << num1
    << " num2: " << num2;
}

void testVectorSorting(){
    vector<int> percentages;
    cout << "percentages innhold: ";
    printIntVec(percentages);
    vector<int> newVec = randomizeVector(percentages, 10);
    cout << "percentages innhold nå: ";
    printIntVec(percentages);
    cout << "\'Medianen\' (før sort) til percentages er " << medianOfVector(percentages) << '\n';
    cout << "Prøver sortvector(): \n";
    sortVector(percentages);
    printIntVec(percentages);

    cout << "Medianen (etter sort) til percentages er " << medianOfVector(percentages) << '\n';

    swapNumbers(percentages[0], percentages[1]);
    cout << "percentages etter swap: ";
    printIntVec(percentages);
}
void testPrintStruct(){
    try{
    Student Student1{"Jonas", "Indøk", -22};
    printStudent(Student1);
    }
    catch (exception& e) {
        cerr << e.what();   
    }

}

void testString(){

}