#pragma once

#include <vector>
#include <tuple>

constexpr int ScreenWidth = 1000;
constexpr int ScreenHeight = 600;

// Denne er det artig å endre på!
constexpr double vehRad = 15;

constexpr double goalRad = 30;

constexpr double spillRad = 20;
constexpr double boostRad = 10;
constexpr double peelRad = 5;

//Oppgave 2a
struct PhysicsState {
	double x, y, angle, vel, grip = 1;
};

//OPPGAVE 2E), bruker alias for Œ forenkle skriving 
using drivingAlgorithm = std::pair<double, double>(PhysicsState ps, const std::vector<std::pair<double, double>>& goals, int currentGoal);

using drawingAlgorithm = void(PhysicsState ps);

enum class Obstacle
{
	Spill, Boost, Peel, None
};
