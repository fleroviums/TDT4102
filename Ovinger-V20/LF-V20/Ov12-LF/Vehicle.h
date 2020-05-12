#pragma once
#include <FL/Fl_Widget.H>
#include <tuple>

#include "utilities.h"

// God praksis som gjer at ein berre treng aa inkludere "Track.h" i .cpp fila.
class Track;
enum class Obstacle;

class Vehicle :
	public Fl_Widget
{
public:
	Vehicle(double x, double y, double angle, const Track& t);

	void draw() final;

protected:
	PhysicsState physics;
	const Track& track;

	int currentGoal = 0;

	Obstacle status;
	double slideAngle = 0;

private:
	virtual std::pair<double, double> steer() const = 0;
	virtual void drawBody() const = 0;

};

bool circleCollision(double delX, double delY, double sumR);