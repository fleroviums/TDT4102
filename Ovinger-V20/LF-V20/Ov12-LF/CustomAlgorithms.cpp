#include "CustomAlgorithms.h"
#include <FL/Fl.H>
#include <random>


//std::pair<double, double> control(const PhysicsState & ps, const std::vector<std::pair<double, double>>& goals, int currentGoal)
std::pair<double, double> control(const PhysicsState & , const std::vector<std::pair<double, double>>& , int ){
	return { !!Fl::event_key(FL_Up) - !!Fl::event_key(FL_Down), !!Fl::event_key(FL_Right) - !!Fl::event_key(FL_Left) };
}
std::pair<double, double> control2(const PhysicsState& , const std::vector<std::pair<double, double>>& , int ){
	return { !!Fl::event_key('W') - !!Fl::event_key('S'), !!Fl::event_key('D') - !!Fl::event_key('A') };
}


//std::pair<double, double> dumb(const PhysicsState& ps, const std::vector<std::pair<double, double>>& vec, int goal)
std::pair<double, double> dumb(const PhysicsState& ps, const std::vector<std::pair<double, double>>& , int )
	// Denne funksjonen koyrer tilfeldig. Den kan likevel fullfore eit kapplop (gjeve evig tid)
{
	// Ikkje pensum! Men dette lagar ei normalfordeling

	static std::random_device rand;
	static std::mt19937 twister{ rand() };
	static std::normal_distribution<double> norm{ 0,50 };

	static double dir = 0;

	// Dersom den treff ein vegg (x/y posisjonen ikkje har endra paa seg) svingar den fullt
	static double x = 0, y = 0;
	if (x == ps.x || y == ps.y)
	{
		dir = -1e5;
		return { 0,-1 };
	}
	x = ps.x;
	y = ps.y;

	// Dette sorgjer for at den endrer retning
	if (abs(dir) < 0.001) dir = norm(twister);

	// Gir ein maksfart. dir er redusert slik den til slutt kan faa ei ny retning
	return { ps.speed < 3 ? 1 : 0, (dir /= 1.5) };

}
std::pair<double, double> simple(
 const PhysicsState& ps,  const std::vector<std::pair<double, double>>& vec, int goal){
	// A vector describing the driving direction of the car
	auto driving_direction = std::make_pair(cos(ps.angle), sin(ps.angle));
	// A vector describing the direction to the current goal in relation to the car
	auto target_direction = std::make_pair(vec[goal].first - ps.x, vec[goal].second - ps.y);

	// Finds angle from the first vector to the second
	double angle_between = angleBetween(driving_direction, target_direction);

	// Decides speed. It reverses if angle_between is sufficiently large
	double speed = -1 + 2 / (1 + angle_between);
	double angle = 0;

	// Turn either left or right depending on the angle between the two vectors
	if (angle_between < 0) {
		angle = -1;
	} else {
		angle = 1;
	}

	return { speed, angle };
}
std::pair<double, double>
 better(const PhysicsState& ps, const std::vector<std::pair<double, double>>& vec, int goal)
{
	double tx = vec[goal].first;
	double ty = vec[goal].second;

	double retAng = 0;
	double retAcc = 0;

	// Koyrer framover dersom prikkproduktet er stort nok
	if (cos(ps.angle)*(tx - ps.x) + sin(ps.angle)*(ty - ps.y) > 0.5*sqrt((tx - ps.x)*(tx - ps.x) + (ty - ps.y)*(ty - ps.y)))
	{
		retAcc = 1;
		// Sorgjer for at den svinger i riktig retning
		if (-cos(ps.angle)*(ty - ps.y) + sin(ps.angle)*(tx - ps.x) > 0)
		{
			retAng = -1;
		}
		else retAng = 1;
	} else {
		retAng = 1;
		if (ps.speed > 0)
		{
			retAcc = -1;
		}
	}

	return { retAcc,retAng };
}

std::pair<double, double> another(const PhysicsState& ps, const std::vector<std::pair<double, double>>& vec, int goal)
{
	auto gx = vec[goal].first;
	auto gy = vec[goal].second;
	// Enkelt nok sjekker om det neste skrittet er naerar maal enn for. Er den det saa koyrar den, viss ikkje svingar den.
	if (sqrt((ps.x - gx)*(ps.x - gx) + (ps.y - gy)*(ps.y - gy)) > 0.8 + sqrt((ps.x + cos(ps.angle) - gx)*(ps.x + cos(ps.angle) - gx) + (ps.y + sin(ps.angle) - gy)*(ps.y + sin(ps.angle) - gy)))
		return { 1,0 };
	else
	{
		// Sorgjer for at den svingjer i riktig retning med aa reikne ut determinanten
		return { ps.speed > 0 ? -1 : 0, (gy - ps.y)*cos(ps.angle) - (gx - ps.x)*sin(ps.angle) > 0  ? 1 : -1 };
	}
}
