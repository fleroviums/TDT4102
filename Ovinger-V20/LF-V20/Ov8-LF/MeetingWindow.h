#pragma once

#include "Window.h"
#include "GUI.h"
#include "Meeting.h"
#include "Person.h"

using namespace Graph_lib;

// Meeting GUI
// This implementation handles program state in the Window class
struct MeetingWindow : Graph_lib::Window
{
	static constexpr int btnW = 100;  
	static constexpr int btnH = 20;
	static constexpr int btnMarginY = 4;
	static constexpr int btnOffsetY = btnH + btnMarginY;
	static constexpr int txtW = 200;
	static constexpr int padX = 20;
	static constexpr int padY = 40;
	static constexpr int headerFontSize = 20;
	static constexpr int newY = 30;
	static constexpr int newX = 80;

	MeetingWindow(Point xy, int w, int h, const string& title);
	~MeetingWindow();

private:
	// Program state
	vector<Meeting*> meetings;
	vector<Person*> persons;
	vector<Car*> cars;

	Text headerText;
	Button quitBtn;

	// Meeting
	In_box meetingDay;
	In_box meetingStart;
	In_box meetingEnd;
	Choice meetingLocation;
	In_box meetingSubject;
	Choice meetingLeader;
	Button meetingNewBtn;
	vector<Widget*> meetingWidgets;

	// Meeting List
	Multiline_out_box meetingList;

	// Person
	In_box personName;
	In_box personEmail;
	In_box personCar;
	Button personNewBtn;
	vector<Widget*> personWidgets;

	// Person List
	Multiline_out_box personList;

	Menu layoutMenu;

	void newMeeting();
	void newPerson();
	void showMeetings();
	void showPersons();
	void hideWidgets(vector<Widget*>& widgets);
	void quit();

	// Helper functions
	void attachMeetingWidget(Widget& mw);
	void attachPersonWidget(Widget& pw);
	void clearWidgetInput(vector<Widget*>& widgets);
	void updateMeetingList();
	void updatePersonList();
	
	static void cb_quit(Address, Address pw);
	static void cb_new_meeting(Address, Address pw);
	static void cb_new_person(Address, Address pw);
	static void cb_meetings(Address, Address pw);
	static void cb_persons(Address, Address pw);
};
