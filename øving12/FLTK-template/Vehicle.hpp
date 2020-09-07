//
//  Vehicle.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 10/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#pragma once
#include "Track.hpp"
#include <stdio.h>
#include <FL/Fl.H>
#include "std_lib_facilities.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_draw.H>
#include "utilities.hpp"


class Vehicle : public Fl_Widget{
private:
    int currentGoal = 0; //Index til det gjeldende målet.
    static int numVehicles; //Static variabel som holder styr på antall vehicles som lages
    int height;
    int width;
    
    PhysicsState ps; //physics state som medlemsvariabel
    
    drivingAlgorithm* steer; //styring for selvkjørende bil
    drawingAlgorithm* drawBody; //tegner unik algoritme
    drawingAlgorithm control;
    
    Obstacle status; //inneholder info om gitt hindring er truffet
    
    double slideAngle = 0; //vinkel når man sklir på bananskall
    
    const Track& t; //Const referanse til en track, bruker slik dependency injection
    
    void checkHitGoal(); //sjekker om kjøretøy har nådd målet
    void checkHitObstacles(); //sjekker om kjøretøyet har truffet et hinder og utfører en konsekvens

    void draw() override;
    
public:
    Vehicle(double x, double y, double angle, drivingAlgorithm* steer, drawingAlgorithm* draw, const Track& t ): steer(steer), drawBody(draw), t{t}, Fl_Widget{10,10,10,10}, ps{x,y,angle,0,1} {}
};

//fri funksjon, uavhengig av klassen
bool circleCollision(double delX, double delY, double sumR);
