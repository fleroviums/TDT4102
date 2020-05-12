#pragma once
#include <FL/Fl_Widget.H>
#include <tuple>
#include <vector>
#include <FL/Fl_JPEG_Image.H>

enum class Obstacle { Spill, Peel, Boost, None };

class Track :
	public Fl_Widget
{
private:
	std::vector<std::pair<double, double>> goals;
	std::vector<std::tuple<double, double, Obstacle>> obstacles;

	Fl_JPEG_Image spill, boost, peel;

public:
	Track();

	void draw() override;

	auto getGoals() const { return goals; }
	auto getObstacles() const { return obstacles; }

};

