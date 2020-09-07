#pragma once
#include "Track.h"
//Skal arve fra Fl_Widget
class Vehicle : public Fl_Widget {
private:
	int currentGoal = 0; //Index til det gjeldende m�let. 

	int color = 0;	// For � gi ulik farge p� gjeldande m�l
	static int numVehicles; //Static variabel som holder styr p� antall vehicles som lages
    // Har en physicsState som medlemsvariabel til klassen
	PhysicsState ps;

	Obstacle status;
	double slideAngle = 0;
    //LAGRER SOM MEDLESVARIABEL
	drivingAlgorithm* steer;
    
	drawingAlgorithm* drawBody;
    

	const Track& t; //Const referanse til en track, bruker slik dependency injection

	void checkHitGoal();
	void checkHitObstacle();
    //Oppgave 1c)
	void draw() override;
public:
    //I oppgave 1b) skal bare Fl_Widget lages i konstrukt�ren 
	Vehicle(double x, double y, double ang, drivingAlgorithm* steer, drawingAlgorithm* draw, const Track& t)
		: steer(steer), drawBody(draw), Fl_Widget{ -10,-10,11,11,"test" }, t{ t }, ps{ x,y, ang }, status{ Obstacle::None } //setter ps sin x,y,ang lik disse 
	{color = numVehicles++; //�ker den med en for hver som lages, for � f� ulik farge
        
    }
    
};
bool circleCollision(int dx, int dy, int rSum);
