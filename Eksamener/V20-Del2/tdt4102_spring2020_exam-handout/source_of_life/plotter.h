/** plotter.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file are required to test the functionality
   implemented by assignments P1 and P2.

   This is the header file for plotter.h
**/

#ifndef _PLOTTER_H
#define _PLOTTER_H

#include <map>
#include <memory>

#include "Graph.h"
#include "Window.h"

#include "dam.h"

using namespace Graph_lib;

// Colors which are available for the plotter
// Used in assignment P1
class GraphColor
{
  unsigned int cur_color = 0;

protected:
  vector<Color::Color_type> colors = {
      Color::red,          Color::blue,        Color::green,
      Color::yellow,       Color::white,       Color::black,
      Color::magenta,      Color::cyan,        Color::dark_red,
      Color::dark_green,   Color::dark_yellow, Color::dark_blue,
      Color::dark_magenta, Color::dark_cyan,   Color::gray,
      Color::mid_gray,     Color::dark_gray,   Color::light_gray};

public:
  Color::Color_type next_color();
};

// Used in assignment P2
class GraphColorRandom : public GraphColor
{
public:
  GraphColorRandom();
};

class Plotter : public Graph_lib::Window
{
private:
  const int x_len;
  const int y_len;
  const Point origin;
  Axis x_axis;
  Axis y_axis;

  const unsigned int timesteps;
  const unsigned int y_range;

  const bool verbose;

  // Assignment P2: You have to change GraphColor to GraphColorRandom
  // below to test your implementation
  // BEGIN: P2
  GraphColorRandom colors;
  // END: P2

  vector<Graph_lib::Shape *> shapes;

  // Map for keeping track of the last points for a dam
  map<string, Point> last_points;

  // Map for keeping track of colors assigned to a dam.
  map<string, Color::Color_type> dam_colors;

public:
  Plotter(int w, int h, unsigned int timesteps, unsigned int y_range,
          bool verbose);
  ~Plotter();
  void plot_point(const string dam, unsigned int timestep, double value);
  void plot_alarm(const string dam, unsigned int timestep,
                  Dam::WaterAlarm alarm);

  Color::Color_type get_color(string dam);
  Point get_last_point(string dam, Point next_point);
  void plot_limit(const string dam, unsigned int limit);
  void add_legend(const string dam);

private:
  int calc_y(double y) const;
  int calc_x(double x) const;
};

#endif // _PLOTTER_H
