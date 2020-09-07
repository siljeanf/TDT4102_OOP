#include "CustomAlgorithms.h"
#include <FL/Fl.H>
#include <random>

constexpr double Pi = 3.1415'9265'3589'7932;

double angleBetween(std::pair<double, double> vec1,
	std::pair<double, double> vec2)
	// Returnerer vinkel mellom to vektorar i radianar.
{
	double dot = vec1.first * vec2.first + vec1.second * vec2.second;
	double det = vec1.first * vec2.second - vec1.second * vec2.first;
	return atan2(det, dot);
}

#include <iostream>
std::pair<double, double> control(PhysicsState ps, const std::vector<std::pair<double, double>>& goals, int currentGoal)
{

	return { Fl::event_key('s') - Fl::event_key('w'), Fl::event_key('a') - Fl::event_key('d') };
}
//OPPGAVE 2 e)
std::pair<double, double> control2(PhysicsState ps, const std::vector<std::pair<double, double>>& goals, int currentGoal)
{// Returnerer velAcc, angAcc
	return { Fl::event_key(FL_Down) - Fl::event_key(FL_Up), Fl::event_key(FL_Left) - Fl::event_key(FL_Right) };
}

void full(PhysicsState ps)
{
	fl_color(FL_BLUE);
	fl_begin_polygon();
	fl_pie(ps.x - vehRad, ps.y - vehRad, 2 * vehRad, 2 * vehRad, -ps.angle * 180 / 3.14 + 30, -ps.angle * 180 / 3.14 + 330);
	fl_end_polygon();
}
std::pair<double, double> dumb(PhysicsState ps, const std::vector<std::pair<double, double>>& vec, int goal)
{
	static std::random_device rand;
	static std::mt19937 twister{ rand() };
	static std::normal_distribution<double> norm{ 0,50 };

	static double dir = 0;

	static double x = 0, y = 0;
	if (x == ps.x || y == ps.y)
	{
		dir = -1e5;
		return { 0,-1 };
	}
	x = ps.x;
	y = ps.y;


	if (abs(dir) < 0.001) dir = norm(twister);


	return { ps.vel < 3 ? 1 : 0, (dir /= 1.5) };

}
std::pair<double, double>better(PhysicsState ps, const std::vector<std::pair<double, double>>& vec, int goal)
{

	double tx = vec[goal].first;
	double ty = vec[goal].second;

	double retAng = 0;
	double retAcc = 0;

	if (cos(ps.angle)*(tx - ps.x) + sin(ps.angle)*(ty - ps.y) > 0.5*sqrt((tx - ps.x)*(tx - ps.x) + (ty - ps.y)*(ty - ps.y)))
	{
		retAcc = 1;
		if (-cos(ps.angle)*(ty - ps.y) + sin(ps.angle)*(tx - ps.x) > 0)
		{
			retAng = -1;
		}
		else retAng = 1;
	}
	else
	{

		retAng = 1;
		if (ps.vel > 0)
		{
			retAcc = -1;
		}
	}



	return { retAcc,retAng };
}
std::pair<double, double> another(PhysicsState ps, const std::vector<std::pair<double, double>>& vec, int goal)
{
	auto gx = vec[goal].first;
	auto gy = vec[goal].second;
	if (sqrt((ps.x - gx)*(ps.x - gx) + (ps.y - gy)*(ps.y - gy)) > 0.8 + sqrt((ps.x + cos(ps.angle) - gx)*(ps.x + cos(ps.angle) - gx) + (ps.y + sin(ps.angle) - gy)*(ps.y + sin(ps.angle) - gy)))
		return { 1,0 };
	else if ((gy - ps.y)*(cos(ps.angle)) - (gx - ps.x)*(sin(ps.angle)) > 0)
	{
		return { ps.vel > 0 ? -1 : 0, 1 };
	}
	else {
		return { ps.vel > 0 ? -1 : 0, -1 };
	}
}

void catBody(PhysicsState ps, Fl_Color col)
{
	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_circle(ps.x, ps.y, vehRad);
	fl_end_polygon();

	fl_color(FL_BLACK);
	fl_begin_line();
	fl_circle(ps.x, ps.y, vehRad);
	fl_end_line();


	for (int i = 1; i < 4; i++)
	{
		double start = ps.angle + Pi / 2;
		double off = (i + 2)*Pi / 8;
		fl_line(ps.x + vehRad * cos(start + off), ps.y + vehRad * sin(start + off), ps.x + vehRad * cos(start - off), ps.y + vehRad * sin(start - off));
	}

	fl_color(col);
	fl_begin_polygon();
	fl_arc(ps.x, ps.y, vehRad, -ps.angle * 180 / Pi + 65, -ps.angle * 180 / Pi + 305);
	fl_end_polygon();

	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_arc(ps.x, ps.y, vehRad, -ps.angle * 180 / Pi + 115, -ps.angle * 180 / Pi + 255);
	fl_end_polygon();

	fl_color(col);
	fl_begin_polygon();
	fl_arc(ps.x, ps.y, vehRad, -ps.angle * 180 / Pi + 140, -ps.angle * 180 / Pi + 230);
	fl_end_polygon();

	fl_color(FL_WHITE);
	fl_begin_polygon();
	fl_circle(ps.x + vehRad / 2.0 *cos(ps.angle + Pi / 3), ps.y + vehRad / 2.0 *sin(ps.angle + Pi / 3), vehRad / 5.0);
	fl_end_polygon();

	fl_begin_polygon();
	fl_circle(ps.x + vehRad / 2.0 *cos(ps.angle - Pi / 3), ps.y + vehRad / 2.0 *sin(ps.angle - Pi / 3), vehRad / 5.0);
	fl_end_polygon();

	fl_color(FL_BLACK);
	fl_begin_polygon();
	fl_circle(ps.x + (vehRad / 2.0 + 2) *cos(ps.angle + Pi / 3), ps.y + (vehRad / 2.0 - 2) *sin(ps.angle + Pi / 3), vehRad / 5.0 - 1);
	fl_end_polygon();

	fl_begin_polygon();
	fl_circle(ps.x + (vehRad / 2.0 + 2) *cos(ps.angle - Pi / 3), ps.y + (vehRad / 2.0 - 2) *sin(ps.angle - Pi / 3), vehRad / 5.0 - 1);
	fl_end_polygon();

	for (int i : {0, 1, 2, 6, 7, 8})
	{
		double off = Pi / 3 + i * Pi *3.0 / 18;

		fl_line(ps.x + vehRad * 4.0 / 5 * cos(ps.angle + off), ps.y + vehRad * 4.0 / 5 * sin(ps.angle + off),
			ps.x + vehRad * 5.0 / 4 * cos(ps.angle + off), ps.y + vehRad * 5.0 / 4 * sin(ps.angle + off));
	}
	{
		double off = Pi / 3 + 4 * Pi *3.0 / 2 / 9;
		fl_color(col);
		fl_line_style(0, 3);
		fl_line(ps.x + vehRad * 4.0 / 5 * cos(ps.angle + off), ps.y + vehRad * 4.0 / 5 * sin(ps.angle + off),
			ps.x + vehRad * 6.0 / 4 * cos(ps.angle + off), ps.y + vehRad * 6.0 / 4 * sin(ps.angle + off));
		fl_line_style(0);
	}

}
