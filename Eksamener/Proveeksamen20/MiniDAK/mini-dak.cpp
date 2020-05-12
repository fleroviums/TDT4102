#include <map>
#include "Graph.h"
#include "GUI.h" // for Simple_window only (doesn't really belong in Window.h)
#include "Simple_window.h"

using namespace std;
using namespace Graph_lib;

// Forklart i oppgaven
map<string, Color> colors = {
	{"red", Color::red},
	{"blue", Color::blue},
	{"green", Color::green},
	{"yellow", Color::yellow},
	{"white", Color::white},
	{"black", Color::black},
	{"magenta", Color::magenta},
	{"cyan", Color::cyan},
	{"dark_red", Color::dark_red},
	{"dark_green", Color::dark_green},
	{"dark_yellow", Color::dark_yellow},
	{"dark_blue", Color::dark_blue},
	{"dark_magenta", Color::dark_magenta},
	{"dark_cyan", Color::dark_cyan},
	{"gray", Color::gray},
	{"mid_gray", Color::mid_gray},
	{"dark_gray", Color::dark_gray},
	{"light_gray", Color::light_gray},
};

/*
Oppgave: Mini-DAK

DataAssistert Konstruksjon (DAK), eller Computer Aided Design (CAD), brukes til
å lage tekniske tegninger på en datamaskin.

I denne oppgaven skal du skrive kode for et enkelt DAK-program kalt "Mini-DAK".
Vi skal benytte oss av grafikkrammeverket fra læreboka som du har blitt kjent
med i øvingsopplegget.

Visuelt ser Mini-DAK ut som i Figur (se på pdf eller Inspera): et vindu med en tekstboks der brukeren kan skrive inn kommandoer.

Gyldige kommandoer er:
rect <color> <x> <y> <w> <h>
	Tegn et rektangel med bredde w og høyde h på angitt posisjon (<x>, <y>).
	Posisjonen (<x>, <y>) angir øverste venstre hjørne av rektangelet.
	Rektangelet får fargen <color>.
circle <color> <x> <y> <r>
	Tegn en sirkel med radius r på angitt posisjon (<x>, <y>).
	Posisjonen (<x>, <y>) angir senter av sirkelen.
	Sirkelen får fargen <color>.
save <filename>
	Lagre tegningen til filen <filename>
load <filename>
	Last inn tegning fra filen <filename>

I tillegg til kommandoene skal brukeren kunne flytte på elementer i tegningen
med musa. Når brukeren trykker et sted i vinduet vil programmet få inn et
koordinat (x, y) som angir posisjonen til musepekeren. Det blir da opp oss å
finne ut om noen av tegneelementene er under musepekeren.
*/

/*
Oppgave 2a:

Implementer funksjonen

bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height)

som returnerer true hvis punktet (x, y) er inni et rektangel angitt av
posisjonen (r_x, r_y), bredde r_width og høyde r_height.
*/






/*
Oppgave 2b:

Implementer funksjonen

bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad)

som returnerer true hvis punktet (x, y) er inni sirkel med senter (c_x, c_y)
og radius c_rad. Fra matematikken vet vi at et punkt er innenfor en sirkel hvis
(x - c_x)^2 + (y - c_y)^2 < c_rad^2
*/


bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height){
    if(x > r_x && x < r_x+r_width){ //if valid x
        return (y > r_y && y < r_y + r_height); //true for valid y
    }
    return false;
}
bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad){
    return ((x-c_x)*(x-c_x)+(y-c_y)*(y-c_y)) < c_rad*c_rad;   
}






/*
Oppgave 2c:

I tegnekommandoene er fargen en tekststreng, f.eks. "red", mens
tegnefunksjonene i rammeverket tar som argument et Color-objekt. Vi trenger
dermed å oversette fra tekststreng til Color-objekt.

Anta det finnes en global variabel colors, definert som:

map<string, Color> colors = {
	{"red", Color::red},
	// osv
};

Implementer funksjonen string_to_color(), som tar som argument en farge som
tekststreng og returnerer et Color-objekt etter oppslag i colors. Om ikke
tekststrengen finnes i colors skal det kastes et unntak.
*/

Color string_to_color(string clr){
    return colors.at(clr); //tryggere enn operator[], kaster exception av seg selv:)
}

string color_to_string(Color color){
    for (auto it = colors.begin(); it != colors.end(); ++it){
        if (it->second == color){return it->first;}
    }
    return "unknown color";
}





/*
Oppgave 2d:

Det vil også være behov for å oversette fra et Color-objekt til en tekststreng.
Implementer funksjonen string color_to_string(Color color) som returnerer
navnet til fargen color basert på colors‐mappet nevnt i forrige deloppgave. Om fargen ikke eksisterer skal funksjonen returnere "unknown color". Du kan anta at likhetsoperatoren (==) er implementert på Color objekter.
*/








/*
Vi deklarerer en felles klasse DAKShape for alle tegneelementer i Mini-DAK:
*/

class DAKShape {
protected:
	Shape &shape; // The underlying Shape to draw
	DAKShape(Shape &s) : shape(s) { }
public:
	virtual bool is_inside(Point xy) = 0;
	virtual string to_string() = 0;
	virtual ~DAKShape() { }
	void attach_to(Graph_lib::Window & win) { win.attach(shape); }
	void move(int dx, int dy) { shape.move(dx, dy); }
	void set_color(Color c) { shape.set_fill_color(c); }
	Color get_color() { return shape.fill_color(); }
};

/*
Oppgave 2e:

Deklarer klassen DAKRectangle som er en spesialisering av DAKShape.
Klassen må opprette et Rectangle-objekt.
Sørg for at DAKShape vet om dette objektet.
Konstruktøren til DAKRectangle skal ta samme argumenter som konstruktøren
til Rectangle (se vedlegg/appendix).
Implementer konstruktøren inline.
*/

class DAKRectangle : public DAKShape{
	public: //public så DAKShape kan se det
		Rectangle DAKr;
	public:
		DAKRectangle(Point xy, int ww, int hh) : DAKr(xy, ww, hh), DAKShape(DAKr) {}
		string to_string();
		bool is_inside(Point p);
};

/*
Oppgave 2f:
Implementer medlemsfunksjonen som returnerer en string som beskriver et rektangel‐objekt som en tekststreng med samme format som beskrevet innledningsvis i denne oppgaven. Med andre ord på formen:

rect color x y w h

der color, x, y , w og h skal være tekstlig beskrivelse av verdiene til disse 5 medlemsvariablene.
Hint: Husk at du kan kalle Rectangle::point(0) for å få returnert et objekt av type Point som angir posisjonen til øverste venstre hjørne til rektangelet.
*/
	
string DAKRectangle::to_string(){
	string rString = "rect ";
	rString += color_to_string(this->get_color);
	Point upperL = DAKr.point(0);
	rString += ' ' + std::to_string(upperL.x) + ' ' + std::to_string(upperL.y);
	//brukte en evighet på å skjønne hvorfor to_string ikke funka som vanlig
	//teit å overkjøre std::to_string i klassen når man må bruke den i medlemsfunksjon!!! Fy
	rString += ' ' + DAKr.width() + ' ' + DAKr.height();
	return rString;
}


/*
Oppgave 2g:

Implementer medlemsfunksjonen DAKRectangle::is_inside(Point p) som returnerer true hvis
punktet p er inni rektangelet, og ellers false. Du har bruk for samme hint som i forrige deloppgave.
*/
bool DAKRectangle::is_inside(Point p){ //la også til funkdekl. i klassedekl.
	Point rp = DAKr.point(0);
	return is_inside_rectangle(p.x, p.y, rp.x, rp.y, DAKr.width(), DAKr.height());
}





/*
Oppgave 2h:
Deklarer klassen DAKCircle som er en spesialisering av DAKShape. DAKCircle har akkurat
samme oppbygging og funksjonalitet som DAKRectangle .

*/

class DAKCircle : public DAKShape{
	public: //public så DAKShape kan se det
		Circle DAKc;
	public:
		DAKCircle(Point xy, int rr) : DAKc(xy, rr), DAKShape(DAKc) {}
		string to_string();
		bool is_inside(Point p);
};

string DAKCircle::to_string(){
	string rString = "circle ";
	rString += color_to_string(this->get_color);
	Point middle = DAKc.center();
	rString += ' ' + std::to_string(middle.x) + ' ' + std::to_string(middle.y);
	rString += ' ' + DAKc.radius();
	return rString;
}
bool DAKCircle::is_inside(Point p){
	Point cr = DAKc.center();
	return is_inside_circle(p.x, p.y, cr.x, cr.y, DAKc.radius());
}



/*
MiniDAK er en spesialisering av Window og er deklarert som:
*/
class MiniDAK : public Graph_lib::Window {
private:
	In_box cmd_box; // input box for commands
	Vector_ref<DAKShape> shapes; // vector of shapes in the drawing
	int selected_shape; // selected shape (index into shapes) or -1 if none are selected
	Point mouse; // mouse position

public:
	MiniDAK(int w, int h);
	void add_shape(DAKShape *shape);
	int handle(int event); // handle events, calls on_* functions depending on event
	void on_enter_pressed();
	void on_mouse_click(int x, int y);
	void on_mouse_drag(int x, int y);
	void save(string filename);
	void load(string filename);
	void do_command(string command);
};



/*
Ikke oppgave
*/
MiniDAK::MiniDAK(int w, int h)
		: Graph_lib::Window({0, 0}, w, h, "MiniDAK"),
		  cmd_box({100, 0}, 200, 25, "Command:"),
		  selected_shape(-1)
{
	attach(cmd_box);

	/*
	Rectangle *bg = new Rectangle({-10, 30}, 10000, 10000);
	bg->set_fill_color(Color::white);
	attach(*bg);
	*/

	/*
	DAKRectangle *rect = new DAKRectangle({x_max()/2, y_max()/2}, 100, 200);
	add_shape(rect);

	DAKCircle *circle = new DAKCircle({x_max()/2, y_max()/2}, 100);
	add_shape(circle);
	*/
}

/*
Ikke oppgave
*/
void MiniDAK::add_shape(DAKShape *shape) {
	shape->attach_to(*this);
	shapes.push_back(shape);
	cout << shape->to_string() << endl;
	redraw();
}

/*
Ikke oppgave
*/
int MiniDAK::handle(int event) {
	//cout << "event" << event << endl;
	//
	if (event == FL_KEYUP) {
		int key = Fl::event_key();
		if (key == FL_Enter) {
			on_enter_pressed();
		}
	}

	if (event == FL_PUSH) {
		on_mouse_click(Fl::event_x(), Fl::event_y());
		redraw();
		//return 1;
	}
	
	if (event == FL_DRAG) {
		on_mouse_drag(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	}

	return Graph_lib::Window::handle(event);
}



/*
Oppgave 2i:

Når brukeren er ferdig med å skrive inn en kommando i tekstboksen og trykker Enter‐ knappen på tastaturet, skal kommandoen tolkes og utføres av programmet. Vi har programmert medlemsfunksjonen handle () slik at medlemsfunksjonen on_enter_pressed () blir kalt når brukeren trykker Enter‐knappen. 

Implementer on_enter_pressed () som skal hente ut innholdet i tekstboksen cmd_box og gi tekststrengen videre som parameter i et kall på funksjonen do_command (). Om kommandoen var vellykket ( do_command kastet ikke et unntak) skal innholdet i cmd_box tømmes. Om do_command kastet et unntak, skal on_enter_pressed skrive ut en informativ feilmelding til konsollet.
(Funksjonen do_command() skal ikke implementeres før i deloppgave 2n)
*/

void MiniDAK::on_enter_pressed(){
	string params = cmd_box.get_string();
	try
	{
		do_command(params);
		cmd_box.clear_value();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}




/*
Oppgave 2j:

Når brukeren trykker et sted i vinduet med musen, kalles funksjonen on_mouse_click().
Funksjonen får inn koordinatet til musepekeren. Dette koordinatet må lagres til
senere bruk.

Her ønsker vi å sjekke om brukeren trykket på noen av DAKShape-objektene.
Om et DAKShape befinner seg under musepekeren, skal indeksen til gjeldende
objekt lagres i selected_shape. Om det er mer enn ett DAKShape under
musepekeren, skal det siste objektet i shapes-vektoren bli valgt.
Om ingen DAKShape befinner seg under musepekeren, settes selected_shape til -1.

Implementer on_mouse_click()
*/

void MiniDAK::on_mouse_click(int x, int y){
	Point pt = Point({x,y}); //kunne brukt reverse iterator hvis det var STL container kanskje
	for(int i=0; i<shapes.size(); ++i){
		if(shapes[i].is_inside(pt)){
			selected_shape = i;
		}
	}
	selected_shape = -1;
}









/*
Oppgave 2k:

Funksjonen on_mouse_drag() blir kalt når brukeren flytter på musa mens han
holder inne museknappen, dvs etter on_mouse_click().

Hvis brukeren har valgt et DAKShape, skal on_mouse_drag() flytte det til den
nye posisjonen.

Implementer on_mouse_drag()
*/

void MiniDAK::on_mouse_drag(int x, int y){
	if(selected_shape!=-1){
		shapes[selected_shape].move(x-mouse.x, y-mouse.y); //??
	}
	mouse.x = x;
	mouse.y = y;
}








/*
Oppgave 2l:

Implementer funksjonen save() som lagrer tegningen til filen filename.
Filformatet er en liste med kommandoer som spesifisert i introduksjonen, en
kommando per linje.
Om filen ikke kunne åpnes skal det kastes et unntak.
*/

void MiniDAK::save(string filename){
	ofstream ost{filename};
	ost.open(filename);
    if(!ost){
        error("Unable to load file ", filename);
    }
	for(auto sh : shapes){
		ost << sh->to_string() << endl;
	}
}

/*
Oppgave 2m:

Implementer funksjonen load() som laster inn en tegning fra fil.
Om filen ikke kunne åpnes skal det kastes et unntak.
Om do_command kaster et unntak, skal en feilmelding skrives ut til konsollet
med informasjon om feilen og hvilket linjenummer i filen feilen oppsto.
*/

void MiniDAK::load(string filename){
	ifstream in{filename};
	if(!in){ error("Unable to load file", filename); }
	string currCmd;
	int lineNum = 1;
	while(getline(in, currCmd)){
		try{
			do_command(currCmd);
			lineNum++;
		}
		catch(const std::exception& e){
			std::cerr << "Error on line " << lineNum << '\n' << e.what() << '\n';
		}	
	}
}









/*
Oppgave 2n:

Funksjonen do_command() tar inn en kommandostreng forsøker å tolke denne i
henhold til formatet spesifiser i innledningen av oppgaven.

Brukere gjør ofte feil, og kommandoer kan inneholde feil.
Funksjonen må derfor sjekke at kommandoen er på korrekt format og kaste et
unntak hvis det oppstår en feil.

Du kan anta at angitt filnavn i kommandoen load ikke vil inneholde blanke
tegn.
*/

void MiniDAK::do_command(string command){
	//first lets split string foreach whitespace into vectors:)
	vector<string> cmdParams; // ie ["rect", "color", "x", "y", "w", "h"]
	string currParam =""; // ie "rec"
	for(int i=0; i<command.size(); ++i){ //for entire command call
		while(command[i]!=' '){ //for every word
			currParam.push_back(command[i]);
		}
		cmdParams.push_back(currParam); //add word to vec
		currParam = ""; //Reset string for next command
	}
	
	//check validity:
	if(cmdParams[0] == "rect"){
		if(cmdParams.size()!=6){throw "Too many or few arguments called, " + std::to_string(cmdParams.size());}
		try{
			new DAKRectangle({stoi(cmdParams[2]),stoi(cmdParams[3])}, stoi(cmdParams[4]), stoi(cmdParams[5]));
			//Usikker men riktig å bruke new her?
		}
		catch(...){
			cerr << "Unable to draw rectangle\n";
		}
	}
	else if(cmdParams[0] == "circle"){
		if(cmdParams.size()!=5){throw "Too many or few arguments called, " + std::to_string(cmdParams.size());}
		try{
			new DAKCircle({stoi(cmdParams[2]), stoi(cmdParams[3])},stoi(cmdParams[4]));
		}
		catch(...){
			cerr << "Unable to draw circle\n";
		}
	}
	else if(cmdParams[0] == "save"){
		if(cmdParams.size()!=2){throw "Too many or few arguments called, " + std::to_string(cmdParams.size());}
		try{
			save(cmdParams[1]);
		}
		catch(...){
			cerr << "Unable to save file\n";
		}
	}
	else if(cmdParams[0]=="load"){
		if(cmdParams.size()!=2){throw "Too many or few arguments called, " + std::to_string(cmdParams.size());}
		try{
			load(cmdParams[1]);
		}
		catch(...){
			cerr << "Unable to load file\n";
		}
	}
	else{
		throw "Initial argument " + cmdParams[0] + " is not a valid argument\n";
	}
}













int main(int argc, char **argv)
{
	MiniDAK dak{600, 400};
	return gui_main();
}
