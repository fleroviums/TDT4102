#pragma once

/* Basert på PPP 15.6 Graphing data. */
#include "Graph.h"
#include "Simple_window.h"
#include "Temps.h"

constexpr int xmax = 1200;
constexpr int ymax = 650;
constexpr int xoffset = 80;
constexpr int yoffset = 40;
constexpr int xspace = 40;
constexpr int yspace = 40;
constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;
constexpr int n_months = 12;
constexpr int degrees = 60;

// Skalering se PPP side 543.
class Scale
// Data value to coordinate conversion
{
	int cbase; // Coordinate base
	int vbase; // Value base
	double scale;

public:
	Scale(int b, int vb, double s) : cbase(b), vbase(vb), scale(s)
	{}
	constexpr int operator()(int v) const
	{
		return static_cast<int>(cbase + (v - vbase) * scale);
	}
	constexpr int operator()(double v) const
	{
		return static_cast<int>(cbase + (v - vbase) * scale);
	}
};

void drawMaxMin(vector<Temps> temps);
