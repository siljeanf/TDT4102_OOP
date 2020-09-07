#pragma once
#include "utilities.h"
#include <FL/fl_draw.H>

// Dette er berre eksemplar på ulik implementasjon, og trengs ikkje å gå gjennom
void catBody(PhysicsState ps, Fl_Color col);

drivingAlgorithm control;
drivingAlgorithm control2;

drawingAlgorithm full;

drivingAlgorithm dumb;
drivingAlgorithm better;
drivingAlgorithm another;

// Lite triks for å gi ulike farger
template<Fl_Color col>
void cat(PhysicsState ps)
{
	catBody(ps, col);
}

