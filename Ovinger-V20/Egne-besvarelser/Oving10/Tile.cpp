#include "Tile.h"
#include "MinesweeperWindow.h"


// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };

void Tile::open()
{
	if(this->getState()==Cell::closed){ //Ignorerer trykk på flagget/åpne tiles
		static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket paa, tilsvarer aapnet rute
		this->state = Cell::open;
		if(this->getMineBool()){this->set_label("X"); this->set_label_color(Color::red);} //Red X if tile has mine
	}

}

void Tile::flag()
{
	if(this->getState()==Cell::flagged){
		this->state = Cell::closed;
		this->set_label(cellToSymbol.at(this->getState()));
		//MinesweeperWindow::placedFlags-=1; //Didn't work, have to check on Minesw.Window.cpp >:/
	}
	else if(this->getState==Cell::closed){ //Sjekker eksplisitt for closed sånn at antall flagg plassert ikke øker hvis du høyreklikker åpen tile
		this->state = Cell::flagged;
		this->set_label(cellToSymbol.at(this->getState())); //cellToSymbol virker kronglete imo
		this->set_label_color(Color::blue);
		//MinesweeperWindow::placedFlags+=1; // See comment above
	}
}
void Tile::setAdjMines(int n){
	this->set_label(to_string(n)); //Function displays number of adjacent mines
	this->set_label_color(minesToColor.at(n));
}

