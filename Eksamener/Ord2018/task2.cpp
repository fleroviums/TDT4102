#include "task2.h"

bool isLeapYear(int year){
    if(year%100 == 0){ //delelig med 100
        if(year%400 == 0) return true; //delelig på 400
        return false;
    }
    if(year%4 ==0){
        return true;
    }
    return false;
}
int daysInMonth(int m, int y){
    if(m==2){
        if(isLeapYear(y)) return 29;
    }
    return months[m-1]; //nullindeksert
}

int dayNo(Date day){
    int dayNos = 0;
    for(int i=1;i<day.m;++i){
        dayNos += daysInMonth(i, day.y); //add days from prev. months
    }
    dayNos += day.d; //add days passed in curr. month
    return dayNos;
}

Date stringToDate(string dateStr){
    Date day;
    string yyyy = dateStr.substr(0,4);
    string mm = dateStr.substr(5,2);
    string dd = dateStr.substr(8,2);
    day.y = stoi(yyyy);
    day.m = stoi(mm);
    day.d = stoi(dd);
    return day;
}

bool checkDate(Date day){
    if (day.m >= 1 && day.m <= 12){ //valid month
        if(day.d >= 1 && day.d <= daysInMonth(day.m, day.y)){
            return true;
        }
    }
    return false;
}
string dateToString(const Date& day){
    if(!checkDate(day)) return "INVALID DATE";
    string yyyy = to_string(day.y);
    while(yyyy.size()>4){
        yyyy.insert(yyyy.begin(),'0');
    }
    string mm = "";
    string dd = "";
    if(day.m<10) mm += '0';
    mm += to_string(day.m);
    if(day.d<10) dd += '0';
    dd += to_string(day.d); 
    return yyyy + '-' + mm + '-' + dd;
}
string dateToString_improved(const Date& day){
    if(!checkDate(day)) return "INVALID DATE";
    stringstream sout;
    sout << setfill('0') << setw(4) << day.y << '-' << setw(2) << day.m << '-' << setw(2) << day.d;
    return sout.str();
}


ostream & operator<<(ostream&out, const Event&rhs){
    out << rhs.id << " : " << rhs.name << " @ " << dateToString(rhs.when);
    return out;
}

void printEvents(vector<Event *> &events){
    for (auto it : events){
        cout << *it << endl;
    }
    cout << events.size() << " events";
}

void Calendar::addEvent(int id, string name, int year, int month, int day){
    Date* today = new Date;
    today->d = day; today->m = month; today->y = year;    
    if(!checkDate(*today)){delete today; throw "Invalid date";} 
    for(auto e : events){
        if(e.first == id){delete today; throw "Event ID already exists";}
    }
    Event* ev = new Event;
    ev->id = id;
    ev->name = name;
    ev->when = *today;
    events.insert(pair<int, Event*>(id,ev));
    delete today;
}

Calendar::~Calendar(){
    for(auto ev : events){
        delete &ev;
    }
}

vector<Event *> Calendar::getEvents(int year, int month, int day){
    vector<Event*> theseEvents;
    for(auto ev : events){
        if(ev.second->when.y == year && ev.second->when.m == month && ev.second->when.d == day){
            theseEvents.push_back(ev.second);
        }
    }
    return theseEvents;
}

vector<Date> Calendar::busyDates(int threshold){
    map<Date, int> dateFreq;
    vector<Date> bussy;
    for(auto ev : events){
        Date curr = ev.second->when;
        if(dateFreq.find(curr) == dateFreq.end())
            dateFreq[curr] = 1; //maybe ugly but eh
        else
            dateFreq[curr] += 1;
    }
    for(auto m : dateFreq){
        if(m.second >= threshold)
            bussy.push_back(m.first);
    }
    return bussy;
}

bool operator<(const Date& lhs, const Date&rhs){
    if(lhs.y < rhs.y){return true;}
    else if(lhs.y == rhs.y){
        if(lhs.m < rhs.m){return true;}
        else if(lhs.m == rhs.m){
            if(lhs.d < rhs.d){return true;}
        }
    }
    return false;
}