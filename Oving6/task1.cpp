#include "std_lib_facilities.h"

/*
Spørsmål sal:
- Hva er forskjellen mellom error("wrong") og cerr("wrong")?? 
*/

void printToFile(string filename){
    string line;
    ofstream ost{ filename };
    if(!ost){
        cerr << "Could not open file " << filename;
    }
    cout << "Enter setence to write to file: ";
    string usrText = "";
    do{
        cin >> usrText;
        if (usrText!="quit"){ost << usrText << '\n';} 
    }
    while(usrText != "quit");
}

void lineNumber(string infile){
    ifstream in{infile};
    if(!in){cerr << "Could not open file " << infile;}
    int lineNum = 1;
    string noExtension = infile.substr(0, infile.size()-4); // Assume .txt extension
    ofstream ost{noExtension + "-copy.txt"};
    string thisLine;
    while (getline(in, thisLine)) {
        ost << lineNum << " " << thisLine << '\n';
        lineNum += 1;
    }
}