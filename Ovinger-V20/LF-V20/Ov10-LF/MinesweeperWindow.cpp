#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) : 
	Graph_lib::Window(xy, width * cellSize, (height+1)* cellSize, title), 
	width{width}, height{height}, mines{mines}, minesLeftUser{mines},
	remainingTiles{ height*width - mines }, 
	minesLeftText{ Point{cellSize / 5, (cellSize * 4) / 5 }, "Mines left: " + to_string(mines) },
	minesLeftBackground{ Point{ 0, 0 }, Point{ width*cellSize, cellSize } },
	gameEndMenu{ Point{ Width() / 2 - 60, Height() / 2}, 60, 40, Menu::horizontal, "Game End" },
	gameEndBackGround{ Point{ Width() / 2 - 60, Height() / 2 - 40 }, Point{ Width() / 2 + 60 ,Height() / 2} },
	gameEndText{ Point{ Width() / 2 - 60 + 3, Height() / 2 - 40 * 3 / 10 }, " " }
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = (i+1) * cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click});
			attach(tiles.back());
		}
	}
	//Legg til miner paa tilfeldige posisjoner
	int i = 0;
	while (i < mines) {
		int pos = rand() % tiles.size();
		if (!tiles[pos].getIsMine()) {
			tiles[pos].setIsMine(true);
			++i;
		}
	}

	//Legg til felt overst i vinduet for aa markere antall miner som gjenstaar
	minesLeftBackground.set_fill_color(Color::black);
	attach(minesLeftBackground);
	minesLeftText.set_font_size(20);
	minesLeftText.set_color(Color::mid_gray);
	
	attach(minesLeftText);

	//Legg til buttons i spillsluttmenyen
	gameEndMenu.attach(new Button{ Point{ 0,0 }, 0, 0, "Restart", cb_restart });
	gameEndMenu.attach(new Button{ Point{ 0,0 }, 0, 0, "Quit", cb_quit });
	attach(gameEndMenu);
	gameEndMenu.hide();

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int adjacentMines = 0;
	for (Point p : points) {
		if (at(p).getIsMine()) {
			++adjacentMines;
		}
	}
	return adjacentMines;
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
	Tile& tile = at(xy);

	// Reagerer kun hvis Tile er lukket
	if (tile.getState() != Cell::closed) {
		return;
	}

	// Hvis ruten er en mine er spillet over
	if (tile.getIsMine()) {
		gameLost();
		return;
	}

	tile.open();
	remainingTiles--;

	vector<Point> adjPoints = adjacentPoints(xy);
	int adjMines = countMines(adjPoints);

	if (adjMines > 0) { 
		// Hvis det er miner i naerheten setter vi label til det og gjor ikke mer
		tile.setAdjMines(adjMines);
	}
	else {
		// Hvis det ikke er noen miner i naerheten vil vi aapne rekursivt rutene rundt
		for (Point p : adjPoints) {
			openTile(p);
		}
	}

	// gameWon() setter gameIsWon til true. Vi kaller gameWon() kun om den ikke allerede
	// er kalt
	if (remainingTiles == 0 && !gameIsWon) {
		gameWon();
		return;
	}
}

void MinesweeperWindow::flagTile(Point xy) {

	Tile& tile = at(xy);

	tile.flag();
	if (tile.getState() == Cell::flagged) {
		//Hvis den ble flagget markerer vi at brukeren har en mindre mine igjen aa flagge
		minesLeftUser--;
	}
	else if(tile.getState() == Cell::closed) {
		//Hvis ikke markerer vi at brukeren har en mer mine igjen aa flagge
		minesLeftUser++;
	}

	//Oppdater teksten overst
	minesLeftText.set_label("Mines left: " + to_string(minesLeftUser));
}


void MinesweeperWindow::cb_click(Address, Address pw)
{  
	Point xy{ Fl::event_x(),Fl::event_y() };

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy) || win.gameIsLost || win.gameIsWon) {
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

void MinesweeperWindow::restart() {

	for (Tile* tile : tiles) {
		tile->reset();
	}

	//Fjern spillsluttmenyen
	gameEndMenu.hide();
	detach(gameEndText);
	detach(gameEndBackGround);

	//Plasser ut nye miner
	int mineCount = 0;
	while (mineCount < mines) {
		int pos = rand() % tiles.size();
		if (!tiles[pos].getIsMine()) {
			tiles[pos].setIsMine(true);
			++mineCount;
		}
	}

	//Nullstill variabler igjen
	remainingTiles = width * height - mines;
	gameIsLost = false;
	gameIsWon = false;
	minesLeftUser = mines;
	minesLeftText.set_label("Mines left: " + to_string(minesLeftUser));

};

void MinesweeperWindow::gameLost() {
	gameIsLost = true;
	for (Tile* tile : tiles) {
		if (tile->getIsMine()) {
			tile->open();
		}
	}

	//Legg til meny for at spillet er tapt
	addGameEndMenu("Game Over", Color::red);
};

void MinesweeperWindow::gameWon() { 
	gameIsWon = true;

	for (Tile* tile : tiles) {
		if (tile->getState() == Cell::closed) {
			tile->flag();
		}
	}

	//Legg til meny for at spillet er vunnet
	addGameEndMenu("Game Won", Color::green);
};

void MinesweeperWindow::addGameEndMenu(string s, Color c) {
	//sett riktig font og farger til vinn eller tap
	gameEndBackGround.set_color(c);
	gameEndBackGround.set_fill_color(c);
	gameEndText.set_label(s);
	gameEndText.set_color(Color::black);
	gameEndText.set_font_size(20);

	//Legg til menyen paa vinduet
	attach(gameEndBackGround);
	attach(gameEndText);
	gameEndMenu.show();

	//refresh vinduet og tegn alle objekter paa nytt
	flush();
}

