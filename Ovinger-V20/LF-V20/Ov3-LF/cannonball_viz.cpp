// Utdelt kode, visualisering av cannonball-spillet i øving 3.

#include "Simple_window.h"

#include "cannonball_viz.h"
#include "cannonball.h"
// Pass på sirkulaer headerinkludering.

void cannonBallViz(double targetPosition, int fieldLength, double velocityX, double velocityY,
				   int timeSteps)
{
	Point tl{100, 100}; // hjornet overst til i hoyre i vinduet
	constexpr int w_width = 800;
	constexpr int w_height = 500;
	Simple_window window{tl, w_width, w_height, "Cannonball Visualizer"};
	window.resizable(nullptr);
	window.size_range(w_width, w_height, w_width, w_height);

	// Plot target. targetPosition er [100, 1000] i main programmet
	// denne funksjonen mapper 0 til 0, og fieldLength til w_width
	int target_x = static_cast<int>((targetPosition * w_width) / fieldLength);
	Rectangle target{Point{target_x - 10, w_height - 20}, 20, 20};
	target.set_fill_color(Color::dark_green);
	window.attach(target);

	// forste tidssteg er 0
	Vector_ref<Circle> trajectory;
	for (int i = 0; i <= timeSteps; ++i) {
		double time = i * (flightTime(velocityY) / timeSteps);

		// maa skalere x til w_width, som beskrevet over
		int xPos = static_cast<int>(posX(0, velocityX, time) * w_width) / fieldLength;
		trajectory.push_back(
			new Circle{Point{xPos, static_cast<int>(w_height - posY(0, velocityY, time))}, 8});
		trajectory[trajectory.size() - 1].set_color(Color::red);
		trajectory[trajectory.size() - 1].set_fill_color(Color::black);
		window.attach(trajectory[trajectory.size() - 1]);

		window.wait_for_button();
	}
}
