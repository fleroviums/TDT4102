#pragma once
#include "std_lib_facilities.h"

bool isLeapYear(int year);
const int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int daysInMonth(int m, int y);

struct Date{
    int d;
    int m;
    int y;
};
Date stringToDate(string dateStr);
bool checkDate(Date day);
string dateToString(const Date& day);

struct Event{
    string name;
    int id;
    Date when;
};
ostream & operator<<(ostream & out, const Event&rhs);

void printEvents(vector<Event *> &events);

class Calendar {
    private:
        string name; // name of calendar
        map<int, Event *> events; // map of events indexed by id
    public:
        Calendar(string name) : name(name) {}
        ~Calendar();
        void addEvent(int id, string name, int year, int month, int day);
        vector<Event *> getEvents(int year, int month, int day);
        vector<Date> busyDates(int threshold);
};

