#include "Track.h"
#include <FL/fl_draw.H>
#include <tuple> //For å bruke tuple greia
#include <math.h>

Track::Track() : Fl_Widget{10,10,10,10,""} //Kaller konstruktøren
	,spill{ "Sprites/spillSprite.jpg" },
	boost{ "Sprites/boostSprite.jpg" },
	peel{ "Sprites/peelSprite.jpg" }
{
	// Eksempelbane
	constexpr int nCircles = 30; //skal ha 30 baner

	for (size_t i = 0; i < nCircles; i++)	//Lag bane
	{
		Obstacle toAdd = Obstacle::None;
		if (i > 0 && (i % (nCircles / 4) == 0))
		{
			toAdd = Obstacle::Spill;
		}
		else if (i > 0 && (i % (nCircles / 2) == 0))
		{
			toAdd = Obstacle::Peel;
		}
		else if (i > 0 && (i % (nCircles / 3) == 0))
		{
			toAdd = Obstacle::Boost;
		}
		else
		{ //Legger til ett pair 
			goals.push_back({
			ScreenWidth / 2 + ScreenWidth / 3.0*cos(i*2.0 / nCircles * 3.14),
			ScreenHeight / 2 - ScreenHeight / 3.0*sin(i*4.0 / nCircles * 3.14)
				});
			continue;
		}

		obstacles.push_back({
				  int(ScreenWidth / 2 + ScreenWidth / 3.0*cos(i*2.0 / nCircles * 3.14)),
				  int(ScreenHeight / 2 - ScreenHeight / 3.0*sin(i*4.0 / nCircles * 3.14)),
				  toAdd
			});
	}
}

void Track::draw()
{
	for (auto& o : obstacles)
	{
		switch (std::get<2>(o)) //Tar det tredje elementet i tupelen obstacle. Ser hvilken type det er
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
	for (auto & p : goals)
	{
		fl_begin_line(); //Tegner linjer
		fl_circle(p.first, p.second, goalRad);
		fl_end_line();
	}
}


