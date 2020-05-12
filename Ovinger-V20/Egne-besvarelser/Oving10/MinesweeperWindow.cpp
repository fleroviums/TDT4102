#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click }); //Place all tiles first without placing mines
			attach(tiles.back());
		}
	}
	status = gameStatus::playing;
	int minesLeft=mines;//Assuming non-negative number of mines
	while(minesLeft>0){ //Using while since it may loop without placing new mine (eg when chosen tile already has mine)
		int randIndex = rand() % (tiles.size()-1); //Get random index from vector for all tiles, -1 since zero indexing
		if(!(tiles[randIndex].getMineBool())){ //If tile does not have mine already
			tiles[randIndex].setMineBool(true); //Sets a mine
			minesLeft-=1;
			/*
			Nå endrer jeg direkte egenskapen til allerede-konstruerte Tile-objekter, i stedet for å gjøre det i konstrutøren til tile
			Usikker på om det er en veldig dum ting, men dette var metoden jeg klarte å komme på først slik at minene er fordelt jevnt over brettet
			*/
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	Vector_ref<const Tile> deezTiles;
	for(auto p : points){
		//Could probably do  if at(p)->getMineBool() here
		deezTiles.push_back(at(p));
		//Usikker på hvordan at funker, men lager forhåpentligvis vector med alle tiles vi er interessert i
	}
	int numMines = 0;
	for(auto t : deezTiles){
		if(t->getMineBool()){
			numMines+=1;
		}
	}
	return numMines;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile* t = &at(xy);
	if(t->getState()==Cell::closed){ //"continue" if flagged or open
		t->open();
	}
	
	if(!(t->getMineBool())){ //If tile isn't a mine
		vector<Point> neighborPoints = adjacentPoints(xy); //Points to neighbor tiles
		int neighborMines = countMines(neighborPoints); //Finds neighbor mines
		if(neighborMines==0){ //No neighboring mines
			for(auto p : neighborPoints){
				if ((p.x == xy.x && p.y == xy.y) || at(p).getState() == Cell::open) {continue;} //Skips already called tiles
				openTile(p); //Opens all neighbor-tiles with no adjacent mines
			}
		}
		else{
			t->setAdjMines(neighborMines); //updates current tile status
		}
	}
	else{ //If pressed tile contains mine
		status = gameStatus::lost;
	}

	checkStatus();
	// Check game status every time openTile is called, since the last thing you do before loss or victory is open a closed tile
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile* t = &at(xy); //Finds tile
	if(t->getState() == Cell::closed){
		placedFlags++;
		t->flag();
	}
	else if(t->getState()==Cell::flagged){
		placedFlags--;
		t->flag();
	}
}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}

void MinesweeperWindow::checkStatus(){ //Something seems to not work with this, I'm unsure what's wrong.
	//Check for a valid win: All tiles not containing mines must be opened
	int checkWin=0;
	for(auto t : tiles){ //checkWin==1 as long as not all mine-free tiles are uncovered
		if(!(t->getMineBool()) && t->getState()==Cell::closed){checkWin = 1;}
		//If tile is mine-free and closed
	}
	if(!checkWin){status=gameStatus::won;}
	// This is clunky, I tried find_if to check if all closed tiles were mine-free, but I had no way of distinguishing closed and non-closed cells in Vector_ref...


	switch(status){
		case gameStatus::playing:{
			txtString = "Mines left: " + to_string(mines-placedFlags);
		}
		case gameStatus::lost:{
			txtString = "Game over rip";
		}
		case gameStatus::won:{
			txtString = "You won!";
		}
	}
	detach(*statusTxt);
	statusTxt =  new Text(Point{0, height * cellSize + cellSize / 2}, txtString);
	attach(*statusTxt); //Skjønner ikke hvorfor det her ikke funker >:/
	this->redraw(); //This causes blinking for every click
}