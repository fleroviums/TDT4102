#include "Meeting.h"

int Meeting::getDay() const {return day;}
int Meeting::getStartTime() const {return startTime;}
int Meeting::getEndTime() const {return endTime;}
Campus Meeting::getLocation() const {return location;}
string Meeting::getSubject() const {return subject;}
const Person* Meeting::getLeader() const {return leader;}

void Meeting::addParticipant(Person* persPtr){
    participants.insert(persPtr);
}
set<const Meeting*> Meeting::meetings;

vector<string> Meeting::getParticipantList(){
    vector<string> pplList;
    for (const Person* p : participants){
        pplList.push_back(p->getName());
    }
    return pplList;
}

ostream& operator<<(ostream& os, const Meeting& m){
    os << "Møte: " << m.getSubject()
    << "\nMøtested: " << m.getLocation()
    << "\nMøtetid: " << m.getStartTime() << " til " << m.getEndTime()
    << "\nMøteleder: " << *(m.getLeader());
    return os;
}
Meeting::~Meeting(){ 
    meetings.erase(this);
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