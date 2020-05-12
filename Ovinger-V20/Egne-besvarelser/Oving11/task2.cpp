#include "task2.h"

ostream& operator<<(ostream& os, Person p){
    os << p.firstName << " " << p.lastName;
    return os;
}
bool operator<( Person& p1, Person& p2){
    return p1.lastName < p2.lastName; //That is, we sort by last name and not case sensitive
}
void insertOrdered(list<Person> &l, const Person& p){
    l.push_back(p);
    l.sort();
}