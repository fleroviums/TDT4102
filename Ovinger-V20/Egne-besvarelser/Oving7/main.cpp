#include "std_lib_facilities.h"
#include "task1.h"
#include "Graph.h"
#include "Emoji.h"
#include "Simple_window.h"
using namespace Graph_lib;
/*
TEORI
1A	public kan aksesseres av alle funksjoner
	private kan kun aksesseres av medlemsfunksjoner (og friend-funksjoner)
	protected er en måte å lage en abstrakt funksjon på, som kun subklasser og superklassen kan aksessere
1D	Uten virtual vil superklassen kjøre sin kodegg
5B	Valgte å lage ny klasse basert på tomt ansikt, da det er mange emojis basert på SadFace sin grunnleggende struktur.
	Likevel er implementasjonen veldig lik SmilingFace, så vet ikke om cpp har en alias aktig funksjon som kunne funket??
5E	Brukte SmilingFace her. Et mulig problem er hvis man skal klassifisere alle smilende emojis, så kan man ikke gjøre dette nå med SmilingFace.
*/

void testAnimal(){
	Cat pusekatt = Cat("Turid",2);
	Dog voff = Dog("Spark",3);
	Vector_ref<Animal> myDyr;
	myDyr.push_back(pusekatt);
	myDyr.push_back(voff);
	for(int i=0;i<myDyr.size();++i){ // Funker ikke med for auto el : myDyr!!
		cout << myDyr[i].toString();
	}
}
void testFaces(){
	constexpr int xmax = 1000;
	constexpr int ymax = 600;
	constexpr int emojiRadius = 50;

	const Point tl{100,100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};
	Point emojiCenter = {200,200};

	EmptyFace alaska(emojiCenter, emojiRadius);
	alaska.attach_to(win);

	SmilingFace gladGut({305,200},emojiRadius,360);
	gladGut.attach_to(win);

	SadFace tristGut({410,200}, emojiRadius, 180);
	tristGut.attach_to(win);

	AngryFace angery({200,320}, emojiRadius);
	angery.attach_to(win);

	WinkingFace lurifax({305,320}, emojiRadius);
	lurifax.attach_to(win);

	SurprisedFace overraska({410,320}, emojiRadius);
	overraska.attach_to(win);

	win.wait_for_button();
}


int main()
{
	setlocale(LC_ALL, "no_NB.UTF-8");
	//srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;

	while (i!=0){
		cout << "\nØving 7 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) testAnimal()\n"
		<< "2) Vis emojis\n";
		cin >> i;
		switch(i){
		case 0: break;
		case 1: testAnimal();
				break;
		case 2: testFaces();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}
	keep_window_open();
}

