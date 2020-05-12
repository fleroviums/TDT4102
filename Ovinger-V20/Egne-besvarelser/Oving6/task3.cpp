#include "std_lib_facilities.h"
#include "task3.h"

ostream& operator<<(ostream& os, const CourseCatalog& cc){
    for (auto elem : cc.courses){
        os << elem.first << ": " << elem.second << '\n';
    }
    return os;
}

void CourseCatalog::addCourse(string coCode, string coName){
    courses[coCode] = coName;
    //pair<string, string> newElem {coCode, coName}; //Old insert() method, unable to update
    //courses.insert(newElem);
}
void CourseCatalog::removeCourse(string coCode){
    courses.erase(coCode);
}
string CourseCatalog::getCourse(string coCode){
    try{
        return courses.at(coCode);
    }
    catch(exception e){
        cerr << e.what();
        return "Error";
    }
}
void CourseCatalog::saveCatalog(string outFile, CourseCatalog cc){
    ofstream ost{outFile};
    ost.open(outFile);
    if(!ost){
        error("Unable to load file ", outFile);
    }
    ost << cc;
}
void CourseCatalog::loadCatalog(string inFile){ //Just print function in general, not limited to CourseCatalog in principle
    ifstream in{inFile};
    if(!in){error("Unable to load file ", inFile);}
    string thisLine;
    while (getline(in, thisLine)) {
        cout << thisLine << '\n';
    }
}