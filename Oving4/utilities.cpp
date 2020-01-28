#include "std_lib_facilities.h"

void printIntVec(vector<int> toPrint){
    for (auto elem : toPrint){
        cout << elem << ", ";
    }
    cout << '\n';
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}
int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}
vector<int> swapNumbers(int& num1, int& num2){
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
    return {num1, num2};
}
vector<int> randomizeVector(vector<int>& initVec,int n){
    for (int i=0;i<n;++i){
        int rNum = rand()%(101);
        initVec.push_back(rNum);
    }
    return initVec;
}

