#include <chrono>
#include <thread>
#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include "utilities.h"

#include "Vehicle.h"
#include "VehicleTypes.h"
#include "Track.h"

int main() {
	auto win = std::make_unique<Fl_Double_Window>(screenWidth, screenHeight, "NASCAT");
	win->color(FL_WHITE);

	// Instansier nye objekt mellom dei to etterfolgjande linjene.
	// -----------------------------------------------------------------------------
	Track tra{};

	PlayerVehicle veh { PlayerVehicle(200, 200, 0, tra) }; //DEFAULT GREEN
	Coyota veh2 { Coyota(200, 200, 0, tra, FL_BLACK, dumb) };
	Coyota veh3 { Coyota(200, 200, 0, tra, FL_RED, simple) };
	Coyota veh4 { Coyota(200, 200, 0, tra, FL_BLUE, better) };
	Coyota veh5 { Coyota(200, 200, 0, tra, FL_YELLOW, another) };


	// -----------------------------------------------------------------------------

	win->end();
	win->show();

	auto nextDrawing = std::chrono::steady_clock::now();

	while (win->shown()){
		std::this_thread::sleep_until(nextDrawing);
		nextDrawing += std::chrono::microseconds(1'000'000 / 60);

		Fl::check();	// Handterar input
		Fl::redraw();	// Kallar draw
	}
}
