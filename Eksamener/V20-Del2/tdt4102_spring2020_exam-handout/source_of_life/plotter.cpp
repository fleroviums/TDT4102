/** plotter.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file are required for assignments P1, P2, P3, P4,
   P5, and P6

   This file implements the visualization functionality of the
   simulator.
**/

#include <cassert>

#include "Graph.h"
#include "Window.h"
#include "csv.h"
#include "std_lib_facilities.h"

#include "plotter.h"

// Assignment P1:
/** Assignment: Implement the function next_color such that
 * each call to the function returns the sequentially next color
 * from the vector colors defined in the Color class (plotter.h). When there are
 * no more colors in the list, the function should throw an error with a
 * descriptive message. Use the value private class member variable cur_color,
 * defined in plotter.h, to keep track of the current location in the colors
 * vector.
 *
 * For example:
 * The first call to next_color returns Color::red as it is first in
 * the colors vector. The second call returns Color::blue as it is
 * second in the list and so on.
 *
 */
Color::Color_type GraphColor::next_color()
{
  // BEGIN: P1

  if(cur_color==colors.size()){ throw "Error: Reached end of colors, no next color exists";}
  return colors[cur_color++]; //if cur_color==0, should return colors[0], then increment to 1 hopefully
  // END: P1
}

/** Assignment P2:
  The class GraphColorRandom, defined in plotter.h, extends the
  GraphColor class and modifies its functionality such that its
  text_color member function returns colors in a random order.  Note that each
  color should only be returned once. Implement the constructor of the
  GraphColorRandom class so that it suffles the colors vector when the
  class is instantiated.

  To test your implementation, change the instantiation of GraphColor in the
  class definition of Plotter in plotter.h as indicated in the file.

  Hint:
  A common algorithm for shuffling a list is Fisher-Yates shuffle[1] given below

  for i from 0 to n−2 do
     j ← random integer such that i ≤ j < n
    exchange a[i] and a[j]

  [1] https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
GraphColorRandom::GraphColorRandom()
{
  // BEGIN: P2
  //shuffle colors vector with Fisher-Yates:
  int n = colors.size()-1;
  for(int i=0;i<n-2;++i){
  int j = rand() %(n-i+1) + i; //random in range [i,n)
  auto tmp = colors[i];
  colors[i] = colors[j];
  colors[j] = tmp;
  }
  // END: P2
}

int Plotter::calc_x(double x) const
{
  assert(x < timesteps);
  if (verbose) {
    cout << "Got calc_x " << x << " " << timesteps << endl;
  }
  return origin.x + ((x / timesteps) * x_len);
}

int Plotter::calc_y(double y) const
{
  return origin.y - ((y / y_range) * y_len);
}

/* Assignment P3

  Implement the function get_color which takes the name of a dam as am
  argument and returns the plot color assigned to the dam.
  The method should look up the color in the class member map dam_colors defined
  in plotter.h. If a dam does not exist in the map, the function
  should create an entry for it and assign a color using the
  colors.next_color() function. colors is the GraphColor instance
  is defined in the Plotter class in plotter.h
 */
Color::Color_type Plotter::get_color(const string dam)
{
  // BEGIN P3
  auto it = dam_colors.find(dam);
  if(it==dam_colors.end()){
    //didnt find in map
    dam_colors[dam] = colors.next_color();
  }
  return dam_colors.at(dam);
  // END P3
}

/** Assignment P4
    The plots of the water levels of the dams are composed of a series of
    line segments. For each timestep, we only get the current value of the
    given dam. Therefore, we need to keep track of where the line segment
    for the previous timestep ended in order to know where to start the
    line segment for the current timestep. This is the purpose of the
    get_last_point  function.


    Implement the function get_last_point which returns the point
    corresponding to the end of the previous line plotted for the dam. The
   function takes two arguments; the name of the dam and the next point to be
   plotted. The last points should be stored in the class member map last_points
   defined in plotter.h which maps the name of a dam to the previous point
   plotted for that dam. If no entry in the map exists for the dam, the function
   should create a new entry for it and return the point {0,0}. If an entry is
   found, the function should return the previous point and update the map with
   the next point.
*/

Point Plotter::get_last_point(const string dam, Point current_point)
{
  // BEGIN: P4
  Point returnval = {0,0};
  if(last_points.find(dam) != last_points.end()){ //if is in map
    returnval = last_points[dam];
  }
  last_points[dam] = current_point; //update map with next
  return returnval;
  // END: P4
}

/** Assignment P5

    If a dam encounters a critical condition, i.e., its water level
    goes beyond the critical maximum and minimum limits, we want to
    visualize this in the graph.

    Implement the function plot_alarm which plots a vertical line
    intersecting the y-axis of the graph indicating that a water level
    alarm occured.

    The function takes three arguments: The name of the dam the alarm
    was triggered for, the timestep during which the
    alarm occured and the type of alarm. The timestep value is used to
    calculate the x-coordinate placement of the line. Note that the
    function calc_x maps a timestep to a value along the x-axis of the
    coordinate system. The alarm is given as a parameter of the type
    Dam::WaterAlarm, an enum defined in dam.h. The private member
    variable y_len contains the height of the y-axis. You can use this
    to determine the height of the line.

    This function is called on every timestep, and the value of the
    alarm parameter is the return value of the  function Dam::get_alarm,
    assignment D2, dam.cpp. You should only draw something if the
    value of the alarm parameter indicates that an alarm occured. Note that the
    default implementation of the get_alarm function simply produces some random
    alarms. Therefore, even if you have not solved assignment D2, you can still
    attempt this.

    Hint: To get a line placement intersecting the y-axis draw lines
    with the start- and end points
    {calc_x(timestep), y_len + 40} and {calc_x(timestep), y_len + 60},
    respectively.

 */
void Plotter::plot_alarm(const string dam, unsigned int timestep,
                         Dam::WaterAlarm alarm)
{
  // BEGIN: P5
  if(alarm==Dam::WaterAlarm::WaterLevelHigh || alarm==Dam::WaterAlarm::WaterLevelLow){
    Line* warning = new Line({calc_x(timestep), y_len+40}, {calc_x(timestep), y_len+60});
    warning->set_color(get_color(dam));
    attach(*warning);
    shapes.push_back(warning);

  }

  // END: P5
}

/** Assignment P6

  To make it easier to tell when the water level of a dam is
  exceeding its maximum or minimum boundaries, we want to visualize
  these in the graph.

  Implement the function plotlimit which draws dashed horizontal lines
  on the graph. The function takes the name of the dam and the limit
  as arguments and is called when the dams are initialized. Recall
  that you can map a value to a y-coordinate using the calc_y function and the
  calc_x function called with values between 0 and timesteps will generate the
  entire possible range of x-coordinates. Draw the lines in the color returned
  by the get_color function. Finally, remember to add the shapes you draw to the
  shapes vector so that they are deallocated when the Plotter class is
  destroyed.


 */

void Plotter::plot_limit(const string dam, unsigned int limit)
{
  // BEGIN: P6 
  int startX = calc_x(0); int stopX = calc_x(timesteps);
  int y = calc_y(limit); //aborts on this snippet somewhere, dont know why
  Line* limLine = new Line({startX, y}, {stopX, y});
  limLine->set_color(get_color(dam));
  limLine->set_style(Line_style::dash);
  attach(*limLine);
  shapes.push_back(limLine);

  // END: P6
}

/**
   Plots a new point with value belonging to the specified dam and
   timestep.
 */
void Plotter::plot_point(const string dam, unsigned int timestep, double value)
{
  if (verbose) {
    cout << "Plotted point " << dam << " " << timestep << " " << value << " "
         << calc_x(timestep) << " " << calc_y(value) << endl;
  }

  Point p = {calc_x(timestep), calc_y(value)};
  Point last = get_last_point(dam, p);
  if (last.x == 0 && last.y == 0) {
    return;
  }

  if (verbose) {
    cout << "last next point " << last.x << " " << last.y << "   " << p.x << " "
         << p.y << endl;
  }

  auto s = new Line(last, p);
  s->set_color(get_color(dam));
  shapes.push_back(s);
  this->attach(*s);
  redraw();
}

/**
 * Adds a legend for a plot in the plot window.
 */
void Plotter::add_legend(const string dam)
{
  const int start_x = 50;
  const int start_y = 490;
  static Point last = {start_x, start_y};

  auto r = new Rectangle({last.x, last.y}, {last.x + 10, last.y + 10});
  auto c = get_color(dam);
  r->set_fill_color(c);
  r->set_color(c);
  shapes.push_back(r);
  attach(*r);

  auto t = new Text({last.x + 15, last.y + 10}, dam);
  t->set_color(Color::black);
  shapes.push_back(t);
  attach(*t);

  last.x = last.x + 100;
  if (last.x > (x_len + start_x - 50)) {
    last.x = start_x;
    last.y = last.y + 30;
  }
}

// Assignment
Plotter::Plotter(int w, int h, unsigned int timesteps, unsigned int yrange,
                 bool verbose)
    : Graph_lib::Window({0, 0}, w, h, "PlotWindow"), x_len(w - 100),
      y_len(h - 150), origin{50, h - 100},
      x_axis(Axis::x, {50, 450}, x_len, 40, "Time"),
      y_axis(Axis::y, {50, 450}, y_len, 10, "Volume"), timesteps(timesteps),
      y_range(yrange), verbose(verbose)

{
  if (verbose) {
    cout << "Created new plotter instance with y_range " << yrange
         << " timesteps " << timesteps << endl;
  }
  x_axis.set_color(Color::black);
  attach(x_axis);
  y_axis.set_color(Color::black);
  attach(y_axis);
}

Plotter::~Plotter()
{
  for (const auto shape : shapes) {
    delete shape;
  }
}
