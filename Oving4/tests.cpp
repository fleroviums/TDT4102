#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

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
    string grades = randomizeString(8,'A','F');
    cout << "Tilfeldige karakterer: " << grades <<'\n';

    string fineString = readInputToString(5,'B','E');
    cout << "\nDu er ferdig: " << fineString;
    cout << "\nAntall 'C' i strengen du ga meg: " << countChar(fineString, 'C') << '\n';

    vector<int> gradeCount;
    for (int i=0;i<6;++i){
        gradeCount.push_back(countChar(grades,'A'+i));
    }

    double avgSum = 0.0;
    double freqSum = 0.0;
    for (int i=5;i>=0;--i){
        avgSum += i*gradeCount[abs(i-5)]; //tre A gir 5*3 fex
        cout << avgSum << " er avgsum";
        freqSum += gradeCount[abs(i-5)];
        cout << avgSum << " er freqsum";
    }
    cout << "avg =" << avgSum << "/" << freqSum;
    double average = avgSum/freqSum;
    cout << "Gjennomsnittet av karakterene: " << average << '\n';
}