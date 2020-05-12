#include "VehicleTypes.h"
#include <FL/fl_draw.H>
#include "utilities.h"

#include "Track.h"

constexpr double Pi = 3.1415'9265'3589'7932;

std::pair<double, double> PlayerVehicle::steer() const{
	double angAcc = 0, velAcc = 0;

	if (Fl::event_key(FL_Left))
		angAcc = -1;
	else if (Fl::event_key(FL_Right))
		angAcc = 1;

	if (Fl::event_key(FL_Down))
		velAcc = -1;
	else if (Fl::event_key(FL_Up))
		velAcc = 1;

	return { velAcc, angAcc };
}

void PlayerVehicle::drawBody() const{
	fl_color(FL_GREEN);
	fl_pie(physics.x-vehicleRadius, physics.y-vehicleRadius, vehicleRadius*2, vehicleRadius*2, -(physics.angle * 180 / 3.14 + 330), -(physics.angle * 180 / 3.14 + 30));

	// Teiknar gjeldande maal
	auto current = track.getGoals()[currentGoal];
	fl_color(FL_GREEN);
	fl_begin_polygon();
	fl_circle(current.first, current.second, goalRadius);
	fl_end_polygon();
}

std::pair<double,double> Coyota::steer() const{
	// Kallar styrefunksjon som vart gjeven i konstruktoeren
	return myDrive(physics, track.getGoals(), currentGoal);
}

// Teiknar katt
void Coyota::drawBody() const {
	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_circle(physics.x, physics.y, vehicleRadius);
	fl_end_polygon();

	fl_color(FL_BLACK);
	fl_begin_line();
	fl_circle(physics.x, physics.y, vehicleRadius);
	fl_end_line();


	for (int i = 1; i < 4; i++)	{
		double start = physics.angle + Pi / 2;
		double off = (i + 2) * Pi / 8;
		fl_line(physics.x + vehicleRadius * cos(start + off), physics.y + vehicleRadius * sin(start + off), physics.x + vehicleRadius * cos(start - off), physics.y + vehicleRadius * sin(start - off));
	}

	fl_color(myColor);
	fl_begin_polygon();
	fl_arc(physics.x, physics.y, vehicleRadius, -physics.angle * 180 / Pi + 65, -physics.angle * 180 / Pi + 305);
	fl_end_polygon();

	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_arc(physics.x, physics.y, vehicleRadius, -physics.angle * 180 / Pi + 115, -physics.angle * 180 / Pi + 255);
	fl_end_polygon();

	fl_color(myColor);
	fl_begin_polygon();
	fl_arc(physics.x, physics.y, vehicleRadius, -physics.angle * 180 / Pi + 140, -physics.angle * 180 / Pi + 230);
	fl_end_polygon();

	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_circle(physics.x + vehicleRadius / 2.0 * cos(physics.angle + Pi / 3), physics.y + vehicleRadius / 2.0 * sin(physics.angle + Pi / 3), vehicleRadius / 5.0);
	fl_end_polygon();

	fl_begin_polygon();
	fl_circle(physics.x + vehicleRadius / 2.0 * cos(physics.angle - Pi / 3), physics.y + vehicleRadius / 2.0 * sin(physics.angle - Pi / 3), vehicleRadius / 5.0);
	fl_end_polygon();

	fl_color(FL_BLACK);
	fl_begin_polygon();
	fl_circle(physics.x + (vehicleRadius / 2.0 + 2) * cos(physics.angle + Pi / 3), physics.y + (vehicleRadius / 2.0 - 2) * sin(physics.angle + Pi / 3), vehicleRadius / 5.0 - 1);
	fl_end_polygon();

	fl_begin_polygon();
	fl_circle(physics.x + (vehicleRadius / 2.0 + 2) * cos(physics.angle - Pi / 3), physics.y + (vehicleRadius / 2.0 - 2) * sin(physics.angle - Pi / 3), vehicleRadius / 5.0 - 1);
	fl_end_polygon();

	for (int i : {0, 1, 2, 6, 7, 8} ) {
		double off = Pi / 3 + i * Pi * 3.0 / 18;

		fl_line(physics.x + vehicleRadius * 4.0 / 5 * cos(physics.angle + off), physics.y + vehicleRadius * 4.0 / 5 * sin(physics.angle + off),
			physics.x + vehicleRadius * 5.0 / 4 * cos(physics.angle + off), physics.y + vehicleRadius * 5.0 / 4 * sin(physics.angle + off));
	}

	double off = Pi / 3 + 4 * Pi * 3.0 / 2 / 9;
	fl_color(myColor);
	fl_line_style(0, 3);
	fl_line(physics.x + vehicleRadius * 4.0 / 5 * cos(physics.angle + off), physics.y + vehicleRadius * 4.0 / 5 * sin(physics.angle + off),
		physics.x + vehicleRadius * 6.0 / 4 * cos(physics.angle + off), physics.y + vehicleRadius * 6.0 / 4 * sin(physics.angle + off));
	fl_line_style(0);

	auto current = track.getGoals()[currentGoal];
	fl_color(myColor);
	fl_begin_polygon();
	fl_circle(current.first, current.second, goalRadius-offset);
	fl_end_polygon();
}
