#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title) :
	Window{ xy, w, h, title },
	quitBtn{ Point{x_max() - pad - btnW, pad }, btnW, btnH, "Quit", cb_quit },
	newPersBtn{ newPersPos, btnW, btnH, "New Person", cb_newPers },
	personName{nameInPos, fieldW, fieldH, "Name"},
	personEmail{mailInPos, fieldW, fieldH, "E-Mail"}
{
	attach(quitBtn);
	attach(newPersBtn);
	attach(personName);
	attach(personEmail);

	ti = title;
}

void MeetingWindow::cb_quit(Address, Address pw){
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_newPers(Address, Address pw){ reference_to<MeetingWindow>(pw).newPers(); }

void MeetingWindow::newPers()
{
	if(personName.get_string()!="" && personEmail.get_string()!=""){
		cout << personName.get_string() << " --- " << personEmail.get_string() << endl;
		people.push_back(new Person{ personName.get_string(), personEmail.get_string() });
	}
}
Vector_ref<Person> MeetingWindow::getPeople()
{
	return people;
}
