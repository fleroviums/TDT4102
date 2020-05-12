#include "Meeting.h"
// GET FUNCTIONS
int Meeting::getDay() const {return day;}
int Meeting::getStartTime() const {return startTime;}
int Meeting::getEndTime() const {return endTime;}
Campus Meeting::getLocation() const {return location;}
string Meeting::getSubject() const {return subject;}
const Person* Meeting::getLeader() const {return leader;}

void Meeting::addParticipant(Person* persPtr){
    participants.insert(persPtr);
}

vector<string> Meeting::getParticipantList(){
    vector<string> pplList;
    for (const Person* p : participants){
        pplList.push_back(p->getName());
    }
    return pplList;
}

// DESTRUCTOR
Meeting::~Meeting(){ 
    meetings.erase(this);
}
// OPERATOR OVERLOADING
ostream& operator<<(ostream& os, const Meeting& m){
    os << "Møte: " << m.getSubject()
    << "\nMøtested: " << m.getLocation()
    << "\nMøtetid: " << m.getStartTime() << " til " << m.getEndTime()
    << "\nMøteleder: " << *(m.getLeader());
    return os;
}
ostream& operator<<(ostream& os, const Campus& c){
    switch(c){
        case Campus::trondheim :
            os << "Trondheim";
            break;
        case Campus::alesund :
            os << "Ålesund";
            break;
        case Campus::gjovik :
            os << "Gjøvik";
            break;
    }
    return os;
}

set<const Meeting*> Meeting::meetings;

vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> potentialDrivers;
    for(const auto& el : meetings){
        if(el != this){ // For all meetings except this meeting (pointer)
            if(el->getDay()==this->getDay() && el->getLocation()==this->getLocation() && abs(el->getStartTime() - this->getStartTime())<=1 && abs(el->getEndTime() - this->getEndTime()) <= 1 ){
                //Runs if a similar meeting takes place
                for (const auto& p : el->participants){ // Runs through participants of matching meeting
                    if (p->hasAvailableSeats()){
                        potentialDrivers.push_back(p);
                    } // Nested fuckery :(
                }
            }
        }
    }
    return potentialDrivers;
}