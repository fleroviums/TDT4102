#include "Track.h"
#include "utilities.h"
#include <FL/fl_draw.H>

Track::Track() : Fl_Widget(10, 10, 10, 10),
	spill{ "Sprites/spillSprite.jpeg" },
	boost{ "Sprites/boostSprite.jpeg" },
	peel{ "Sprites/peelSprite.jpeg" } 
{
	constexpr int nCircles = 30;

	for (size_t i = 0; i < nCircles; i++)	// Eksempelbane.
	{
		Obstacle toAdd = Obstacle::None;
		if (i % (nCircles / 4) == 0)
		{
			toAdd = Obstacle::Spill;
		}
		else if (i % (nCircles / 2) == 0)
		{
			toAdd = Obstacle::Peel;
		}
		else if (i % (nCircles / 3) == 0)
		{
			toAdd = Obstacle::Boost;
		}
		else
		{
			goals.push_back({
			screenWidth / 2 + screenWidth / 3.0 * cos(i * 2.0 / nCircles * 3.14),
			screenHeight / 2 - screenHeight / 3.0 * sin(i * 4.0 / nCircles * 3.14)
				});
			continue;
		}

		obstacles.push_back({
				  int(screenWidth / 2 + screenWidth / 3.0 * cos(i * 2.0 / nCircles * 3.14)),
				  int(screenHeight / 2 - screenHeight / 3.0 * sin(i * 4.0 / nCircles * 3.14)),
				  toAdd
			});
	}
}

void Track::draw()
{
	for (auto& o : obstacles) // Teikner hindringar
	{
		switch (std::get<2>(o))
		{
		case Obstacle::Spill:
			spill.draw(std::get<0>(o) - 25, std::get<1>(o) - 25);
			break;
		case Obstacle::Peel:
			peel.draw(std::get<0>(o) - 15, std::get<1>(o) - 15);
			break;
		case Obstacle::Boost:
			boost.draw(std::get<0>(o) - 10, std::get<1>(o) - 10);
			break;
		default:
			break;
		}
	}

	fl_color(FL_BLACK);

	for (auto& i : goals) // Teikner maal
	{
		fl_begin_line();
		fl_circle(i.first, i.second, goalRadius);
		fl_end_line();
	}
}
