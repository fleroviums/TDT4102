#pragma once

#include "Person.h"
#include "std_lib_facilities.h"

enum class Campus { trh, aal, gjo };
const map<Campus, string> campusToString {
	{Campus::trh, "Trondheim"},
	{Campus::aal, "Aalesund"},
	{Campus::gjo, "Gjovik"}
};

ostream& operator<<(ostream& os, Campus c);

class Meeting
{
public:
	Meeting(const Meeting&) = delete;
	Meeting& operator=(const Meeting&) = delete;

	Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader);
	~Meeting();

	int getDay() const {return day; } 
	int getStartTime() const {return startTime; }
	int getEndTime() const {return endTime; }
	Campus getLocation() const {return location; }
	string getSubject() const {return subject; }

	
	const Person& getLeader() const {return *leader; }

	void addParticipant(const Person* person);
	vector<string> getParticipantList() const;

	vector<const Person*> findPotentialCoDriving() const;

private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;

	static set<const Meeting*> meetings;
};

ostream& operator<<(ostream& os, const Meeting& m);
