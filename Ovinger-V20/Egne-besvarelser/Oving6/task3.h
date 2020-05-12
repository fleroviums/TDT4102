#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
    private:
        map<string, string> courses{};//{courseCode, courseName},
    public:
        friend ostream& operator<<(ostream&, const CourseCatalog&);
        void addCourse(string coCode, string coName);
        void removeCourse(string coCode);
        string getCourse(string coCode);
        void loadCatalog(string inFile);
        void saveCatalog(string outFile, CourseCatalog cc);
};