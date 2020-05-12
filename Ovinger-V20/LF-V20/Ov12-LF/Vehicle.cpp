#include "Vehicle.h"
#include <algorithm>

#include <FL/Fl.H>

#include "utilities.h"
#include "Track.h"

Vehicle::Vehicle(double x, double y, double angle, const Track& t) : 
	Fl_Widget(10, 10, 10, 10),
	physics{ x,y,angle }, // speed = 0
	track{ t },
	status{Obstacle::None}
{   }

void Vehicle::draw()
{
	// Sjekk om maal er treft
	auto current = track.getGoals()[currentGoal];
	if (circleCollision(physics.x - current.first, physics.y - current.second, vehicleRadius + goalRadius))
		currentGoal = (currentGoal+1) % track.getGoals().size();

	for (auto& obs : track.getObstacles()) // Behandle hindringar
	{
		auto type = std::get<2>(obs);
		if (circleCollision(std::get<0>(obs) - physics.x, std::get<1>(obs) - physics.y, vehicleRadius + (type == Obstacle::Boost ? boostRadius : type == Obstacle::Spill ? spillRadius : peelRadius)))
		{
			switch (type)
			{
			case Obstacle::Spill:
				physics.grip = 0.5;
				break;
			case Obstacle::Peel:
				if (status == Obstacle::Peel || physics.speed < 2.0)
					break;
				status = Obstacle::Peel;
				slideAngle = physics.angle;
				break;
			case Obstacle::Boost:
				physics.grip = 2;
				break;
			default:
				break;
			}
		}
	}

	auto acc = steer();

	if (status == Obstacle::Peel)
	{
		physics.slide(slideAngle);
		if (physics.speed < 0.3)
			status = Obstacle::None;
	}
	else
		physics.update(acc.first, acc.second);

	// Hald Vehicle innanfor vindauget
	physics.x = std::min(std::max(vehicleRadius, physics.x), screenWidth - vehicleRadius);
	physics.y = std::min(std::max(vehicleRadius, physics.y), screenHeight - vehicleRadius);

	drawBody();
}

bool circleCollision(double delX, double delY, double sumR)
{
	return delX*delX + delY*delY <= sumR*sumR;
}