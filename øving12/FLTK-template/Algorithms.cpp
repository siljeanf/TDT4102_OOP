//
//  Algorithms.cpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 19/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "Algorithms.hpp"
#include <FL/Fl.H>
#include <random>
#include "std_lib_facilities.h"

//styring av kjøretøyet control
pair<double, double> control(PhysicsState ps, const vector<pair<double, double>>& goals, int currentGoal){
    return { Fl::event_key(FL_Up) - Fl::event_key(FL_Down), Fl::event_key(FL_Right) - Fl::event_key(FL_Left) };
}

void full(PhysicsState ps)
{
    fl_color(FL_BLUE);
    fl_begin_polygon();
    fl_pie(ps.x - vehRad, ps.y - vehRad, 2 * vehRad, 2 * vehRad, -ps.angle * 180 / 3.14 + 30, -ps.angle * 180 / 3.14 + 330);
    fl_end_polygon();
}
