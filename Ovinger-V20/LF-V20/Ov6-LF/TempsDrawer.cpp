#include "TempsDrawer.h"

void drawMaxMin(vector<Temps> temps)
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Daglige maks- og minimumstemperaturer fra 3. februar 2018 "
						   "til og med 3. februar 2019."};
	Simple_window win{tl, xmax, ymax, win_label};

	// Axes
	Axis x{Axis::x,
		   {xoffset, ymax / 2},
		   xlength,
		   n_months,
		   "Feb                Mar                Apr                 "
		   "May                Jun                 Jul                "
		   "Aug                 Sep               Oct                 "
		   "Nov                 Dec                Jan"};
	x.label.move(-240, 0);
	Text zero{Point{xoffset - 15, ymax / 2 + 5}, "0"};
	Text ten{Point{xoffset - 20, ymax / 2 - 90}, "10"};
	Text twenty{Point{xoffset - 20, ymax / 2 - 185}, "20"};
	Text nten{Point{xoffset - 25, ymax / 2 + 100}, "-10"};
	Text ntwenty{Point{xoffset - 25, ymax / 2 + 195}, "-20"};
	Axis y{Axis::y,
		   {xoffset, ymax - yoffset},
		   ylength,
		   degrees / 10,
		   "degrees [°C]"};

	x.set_color(Color::black);
	y.set_color(Color::black);
	zero.set_color(Color::black);
	ten.set_color(Color::black);
	twenty.set_color(Color::black);
	nten.set_color(Color::black);
	ntwenty.set_color(Color::black);

	win.attach(x);
	win.attach(y);
	win.attach(zero);
	win.attach(ten);
	win.attach(twenty);
	win.attach(nten);
	win.attach(ntwenty);

	// Scaling
	int days = temps.size();
	double xscale = static_cast<double>(xlength) / days;
	double yscale = static_cast<double>(ylength) / degrees;
	Scale xs{xoffset, 0, xscale};
	Scale ys{ymax / 2, 0, -yscale};

	Open_polyline max_temps;
	Open_polyline min_temps;

	{
		// Introduce anonymous scope to not pollute the rest of the outer scope
		// with variable i after the for loop is complete.
		int i = 0;
		for (Temps& t : temps) {
			max_temps.add(Point{xs(i), ys(t.max)});
			min_temps.add(Point{xs(i), ys(t.min)});
			++i;
		}
	}

	Text max_label{Point{20, max_temps.point(0).y}, "Max"};
	Text min_label{Point{20, min_temps.point(0).y}, "Min"};

	max_temps.set_color(Color::red);
	max_label.set_color(Color::red);
	min_temps.set_color(Color::blue);
	min_label.set_color(Color::blue);

	win.attach(max_temps);
	win.attach(min_temps);
	win.attach(max_label);
	win.attach(min_label);

	win.wait_for_button();
}
