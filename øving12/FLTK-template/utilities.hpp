//
//  utilities.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 10/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#include <vector>
#include <tuple>
#include "std_lib_facilities.h"

constexpr int ScreenWidth = 1000;
constexpr int ScreenHeight = 600;

// Denne er det artig Â endre pÂ!
constexpr double vehRad = 100; //radius for kjøretøyet

constexpr double goalRad = 30; //radius for å treffe målet

constexpr double spillRad = 20; //oljesøl reduserer veigrep
constexpr double boostRad = 10; //forbedrer kjøreegenskaper
constexpr double peelRad = 5; //bananskall som får kjøretøyet til å skli

//hindringer
enum class Obstacle{Spill, Boost, Peel, None};

//Lager en struct til kjøretøyet
struct PhysicsState{
    double x;
    double y;
    double angle;
    double vel;
    double grip = 1;
};

//aliasfunksjon
using drivingAlgorithm = pair<double, double>(PhysicsState ps, const vector<pair<double, double>>& goals, int currentGoal);

using drawingAlgorithm = void(PhysicsState ps);

