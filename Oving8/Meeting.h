#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

enum class Campus{trondheim, alesund, gjovik};
ostream& operator<<(ostream& os, const Campus& c);


class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const Person* leader;
        set<const Person*> participants;
        static set<const Meeting*> meetings;
    public:
        int getDay() const;
        int getStartTime() const;
        int getEndTime() const;
        Campus getLocation() const;
        string getSubject() const;
        const Person* getLeader() const; // Føler det er for mye const her
        void addParticipant(Person* persPtr);
        vector<string> getParticipantList();
        vector<const Person*> findPotentialCoDriving();
        Meeting(int d, int sT, int eT, Campus loc, string s, const Person* l) :
        day{d}, startTime{sT}, endTime{eT}, location{loc}, subject{s}, leader{l} {
           meetings.insert(this);
           participants.insert(l);
        }
        ~Meeting(); 

};
ostream& operator<<(ostream& os, const Meeting& m);