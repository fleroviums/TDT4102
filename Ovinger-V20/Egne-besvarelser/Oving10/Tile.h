#pragma once
#include "GUI.h"
#include <map>


using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button
{
	Cell state = Cell::closed;

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
	bool isMine;
public:
	Tile(Point pos, int size, Graph_lib::Callback cb, bool bMi=false)
		:Button{pos, size, size, "", cb}, isMine{bMi} {};
	
	Cell getState() const {return state; };

	bool getMineBool() const{return isMine;}
	void setMineBool(bool bVal){isMine = bVal;}
	void open(); // aapner ruten
	void flag();// Flagger en rute
	void setAdjMines(int n);
};