#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

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
string randomizeString(int charLen, char lowerLim, char upperLim){
    int lLim{(int)lowerLim}; //Fant på nettet, er dette tilsvarende static cast?
    int uLim{(int)upperLim};
    string randS = "";
    char c = 'A'; //Trivial value:)
    for (int i=0;i<charLen;++i){
        c = rand()%(uLim+1-lLim) + lLim; // Generates rand char between lLim and uLim.
        randS += c;
    }
    return randS;
}

string readInputToString(int n, char lowerCh, char upperCh){
    string usrString;
    lowerCh = toupper(lowerCh);
    upperCh = toupper(upperCh); //In case user inputs lowercase in function
    for (int i=0;i<n;++i){
        char usrInp;
        cout << "Skriv inn char: ";
        cin >> usrInp;
        //usrInp = toupper(usrInp);
        while (toupper(usrInp) < lowerCh || toupper(usrInp) > upperCh){
            cout << "Ugyldig char.\nSkriv inn char: ";
            cin >> usrInp;
        }
        usrString += toupper(usrInp);
    }
    return usrString;
}

int countChar(string data, char ch){ //Case-sensitive, no mentions of it though..
    int freq=0;
    for (auto c : data){
        if(c==ch){
            freq+=1;
        }
    }
    return freq;
}