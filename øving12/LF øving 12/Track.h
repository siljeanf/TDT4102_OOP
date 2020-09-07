#pragma once
#include <FL/Fl_Widget.H>
#include <vector>
#include <FL/Fl_JPEG_Image.H>
#include "utilities.h"
//Klasse som arver fra widget
class Track : public Fl_Widget
{
private:
	std::vector<std::pair<double, double>> goals;
	std::vector<std::tuple<double, double, Obstacle>> obstacles;
	void draw() override;
public:
	Track();
	const auto& getGoals() const { return goals; } //Returnerer konst referanse til goals vektoren 
	const auto& getObstacles() const { return obstacles; }

	Fl_JPEG_Image spill, boost, peel;
};

