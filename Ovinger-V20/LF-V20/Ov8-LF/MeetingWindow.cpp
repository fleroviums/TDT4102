#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
	: Graph_lib::Window{xy, w, h, title},
	headerText{ Point{padX, padY - 20}, "Meetings" },

	quitBtn{ Point{x_max() - btnW, 0}, btnW, btnH, "Quit", cb_quit },

	meetingDay{ Point{newX, newY}, txtW, btnH, "Day" },
	meetingStart{ Point{newX, newY + btnH}, txtW, btnH, "Start time" },
	meetingEnd{ Point{newX, newY + btnH * 2}, txtW, btnH, "End time" },
	meetingLocation{ Point{newX, newY + btnH * 3}, txtW, btnH, "Location" },
	meetingSubject{ Point{newX, newY + btnH * 4}, txtW, btnH, "Subject" },
	meetingLeader{ Point{newX, newY + btnH * 5}, txtW, btnH, "Leader" },
	meetingNewBtn{ Point{newX, newY + btnH * 6}, btnW, btnH, "Add meeting", cb_new_meeting },
	meetingList{ Point{padX, newY + btnH * 8}, x_max() - 2 * padX, txtW * 2, "All meetings" },

	personName{ Point{newX, newY}, txtW, btnH, "Name" },
	personEmail{ Point{newX, newY + btnH}, txtW, btnH, "Email" },
	personCar{ Point{newX, newY + btnH * 2}, txtW, btnH, "Car seats" },
	personNewBtn{ Point{newX, newY + btnH * 3}, btnW, btnH, "Add person", cb_new_person },
	personList{ Point{padX, newY + btnH * 5}, x_max() - 2 * padX, txtW * 2, "All persons" },

	layoutMenu{ Point{x_max() - btnW, btnH * 2}, btnW, btnH, Menu::vertical, "Layout menu" }
{
	// Common
	attach(quitBtn);
	attach(headerText);

	// New meeting
	attachMeetingWidget(meetingDay);
	attachMeetingWidget(meetingStart);
	attachMeetingWidget(meetingEnd);
	attachMeetingWidget(meetingLocation);
	attachMeetingWidget(meetingSubject);
	attachMeetingWidget(meetingLeader);
	attachMeetingWidget(meetingNewBtn);

	for (auto c : campusToString)
		meetingLocation.add(c.second);

	// Meeting list
	attachMeetingWidget(meetingList);

	// New person
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	attachPersonWidget(personCar);
	attachPersonWidget(personNewBtn);

	// Person list
	attachPersonWidget(personList);

	// Menu
	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Meetings", cb_meetings });
	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Persons", cb_persons });
	attach(layoutMenu);

	// Initial window
	showMeetings();
	// headerText.set_label("Meetings");
	headerText.set_font_size(headerFontSize);
}

MeetingWindow::~MeetingWindow()
{
	for (auto& m : meetings)
		delete m;

	for (auto& p : persons)
		delete p;

	for (auto& c : cars)
		delete c;
}

void MeetingWindow::newMeeting()
{
	int day = meetingDay.get_int();
	int start = meetingStart.get_int();
	int end = meetingEnd.get_int();
	
	Campus campus = static_cast<Campus>(meetingLocation.value());
	const string& subject = meetingSubject.get_string();
	int leaderId = meetingLeader.value();

	meetingDay.clear_value();
	meetingStart.clear_value();
	meetingEnd.clear_value();
	meetingSubject.clear_value();
	meetingLeader.clear_value();

	if (day < 1 || 31 < day || start < 0 || 23 < start || end < start || subject.empty()
		|| leaderId < 0) {
		cerr << "Not enough information to add meeting.\n";
		return;
	}

	const Person* leader = persons[leaderId];
	meetings.push_back(new Meeting{ day, start, end, campus, subject, leader });

	// clearWidgetInput(meetingWidgets);
	updateMeetingList();
}

void MeetingWindow::newPerson()
{
	Car* car = nullptr;
	if (personCar.get_int() != 0) {
		car = new Car{ personCar.get_int() };
		cars.push_back(car);
	}
	
	const string& name = personName.get_string();
	const string& email = personEmail.get_string();

	personCar.clear_value();
	personName.clear_value();
	personEmail.clear_value();
	
	if (name.empty() || email.empty()) {
		cerr << "Not enough information to add person.\n";
		return;
	}

	

	persons.push_back(new Person{ name, email, car });
	meetingLeader.add(persons.back()->getName());
	// clearWidgetInput(personWidgets);
	updatePersonList();
}

void MeetingWindow::showMeetings()
{
	hideWidgets(personWidgets);
	headerText.set_label("Meetings");

	for (auto mw : meetingWidgets)
		mw->show();
}

void MeetingWindow::showPersons()
{
	hideWidgets(meetingWidgets);
	headerText.set_label("Persons");

	for (auto pw : personWidgets)
		pw->show();
}

void MeetingWindow::hideWidgets(vector<Widget*>& widgets)
{
	for (auto w : widgets)
		w->hide();
}



void MeetingWindow::updateMeetingList()
{
	stringstream ss;
	for (auto m : meetings) {
		ss << *m << '\n';
	}
	meetingList.put(ss.str());
}

void MeetingWindow::updatePersonList()
{
	stringstream ss;
	for (auto p : persons) {
		ss << *p << '\n';
	}
	personList.put(ss.str());
}

void MeetingWindow::attachMeetingWidget(Widget& mw)
{
	attach(mw);
	meetingWidgets.push_back(&mw);
}

void MeetingWindow::attachPersonWidget(Widget& pw)
{
	attach(pw);
	personWidgets.push_back(&pw);
}


void MeetingWindow::quit()
{
	hide();
}

// Callback functions
void MeetingWindow::cb_quit(Address, Address pw)
{
	// static_cast<MeetingWindow*>(pw)->quit();
	reference_to<MeetingWindow>(pw).quit();
}
void MeetingWindow::cb_new_meeting(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).newMeeting();
}
void MeetingWindow::cb_new_person(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).newPerson();
}
void MeetingWindow::cb_meetings(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).showMeetings();
}
void MeetingWindow::cb_persons(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).showPersons();
}
