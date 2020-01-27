// Utdelt kode, visualisering av cannonball-spillet i øving 3.

#include "Simple_window.h"

#include "cannonball_viz.h"
#include "cannon.h"
// Pass på sirkulær headerinkludering.

void cannonBallViz(double targetPosition, int fieldLength, double velocityX, double velocityY,
				   int timeSteps)
{
	Point tl{100, 100}; // top-left corner of our window
	constexpr int w_width = 800;
	constexpr int w_height = 500;
	Simple_window window{tl, w_width, w_height, "Cannonball Visualizer"};
	window.resizable(nullptr);
	window.size_range(w_width, w_height, w_width, w_height);

	// Plot target. targetPosition is in [100, 1000] in main program
	// this function handles target in range 0 to fieldLength, map 0 to 0, and fieldLength to
	// w_width
	int target_x = static_cast<int>((targetPosition * w_width) / fieldLength);
	Rectangle target{Point{target_x - 10, w_height - 20}, 20, 20};
	target.set_fill_color(Color::dark_green);
	window.attach(target);

	// first timestep at time 0
	Vector_ref<Circle> trajectory;
	for (int i = 0; i <= timeSteps; ++i) {
		double time = i * (flightTime(velocityY) / timeSteps);

		// must scale x to window-width, as described above
		int xPos = static_cast<int>(posX(0, velocityX, time) * w_width) / fieldLength;
		trajectory.push_back(
			new Circle{Point{xPos, static_cast<int>(w_height - posY(0, velocityY, time))}, 8});
		trajectory[trajectory.size() - 1].set_color(Color::red);
		trajectory[trajectory.size() - 1].set_fill_color(Color::black);
		window.attach(trajectory[trajectory.size() - 1]);

		window.wait_for_button();
	}
}