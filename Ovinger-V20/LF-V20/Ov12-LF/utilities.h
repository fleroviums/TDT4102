#pragma once
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr int screenWidth = 1000;
constexpr int screenHeight = 600;

constexpr double vehicleRadius = 15;

constexpr double goalRadius = 30;

constexpr double spillRadius = 20;
constexpr double boostRadius = 10;
constexpr double peelRadius = 5;


class PhysicsState{
public:
	double x, y, angle, speed = 0, grip = 1;
	void update(double translationAcceleration, double angularAcceleration);
	void slide(double slideAngle);
};

double angleBetween(std::pair<double, double> vec1,std::pair<double, double> vec2);