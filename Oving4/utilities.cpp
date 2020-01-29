#include "std_lib_facilities.h"
#include "utilities.h"

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
void swapNumbers(int& num1, int& num2){
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}
vector<int> randomizeVector(vector<int>& initVec,int n){
    for (int i=0;i<n;++i){
        int rNum = rand()%(101);
        initVec.push_back(rNum);
    }
    return initVec;
}
vector<int> sortVector(vector<int>& initVec){
    int i = 1;
    int j = 0;
    while(static_cast<unsigned long long>(i)<initVec.size()){
        j = i;
        while(j>0 && initVec[j-1] > initVec[j]){
            swapNumbers(initVec[j-1], initVec[j]);
            j-=1;
        }
        ++i;
    }
    return initVec;
}
double medianOfVector(vector<int> A){
    int vecSize = A.size();
    if (vecSize%2 != 0){
        return A[(vecSize-1)/2];
    }
    else{
        double middle = vecSize/2;
        return (A[middle]+A[middle-1])/2.0;
    }
}


Student::Student(string n, string s, int a) : name{ n }, studyProgram{ s }, age{ a } {
	if (a < 0) {
		throw exception("Invalid age passed to constructor");
	}
}

/*Student::Student(string n, string s, int a) { 
	if (a < 0) {
		throw exception("Invalid date passed to constructor");
	}
	else {
		name = n;
        studyProgram = s;
        age = a;
	}
}*/

void printStudent(Student studthing) {
	cout << "Studentens navn: " << studthing.name << "\nStudieretning: " << studthing.studyProgram << "\nAlder: " << studthing.age << endl;
}
string randomizeString(int charNum, char firstLim, char lastLim){

}