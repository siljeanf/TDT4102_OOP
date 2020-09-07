#include "Vehicle.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H> //For � kunne tegne
#include <cmath>
#include <tuple>
#include <iostream>

int Vehicle::numVehicles = 0; //Setter antall vehicles til null. 

//OPPGAVE 3c)
bool circleCollision(int dx, int dy, int rSum)
{
	return (dx*dx + dy*dy < rSum*rSum);
}

//OPPGAVE 3e)
void Vehicle::checkHitGoal()
{
	auto goals = t.getGoals();
	if (circleCollision(ps.x - goals[currentGoal].first, ps.y - goals[currentGoal].second, vehRad + goalRad))
	{
		currentGoal = (currentGoal + 1) % goals.size(); //Oppdaterer hva neste m�l er 
	}
}

//OPPGAVE 3f)
void Vehicle::checkHitObstacle()
{
	for (auto& o : t.getObstacles())
	{
		switch (std::get<2>(o))
		{
		case Obstacle::Boost:
			if (circleCollision(ps.x - std::get<0>(o), ps.y - std::get<1>(o), vehRad + boostRad))
			{ //�ker grip
				ps.grip = 2;
			}
			break;
		case Obstacle::Spill:
			if (circleCollision(ps.x - std::get<0>(o), ps.y - std::get<1>(o), vehRad + spillRad))
			{ //Minker grip
				ps.grip = 0.5;
			}
			break;
		case Obstacle::Peel:
			if (status != Obstacle::Peel && circleCollision(ps.x - std::get<0>(o), ps.y - std::get<1>(o), vehRad + peelRad) && ps.vel > 2)
			{
				status = Obstacle::Peel;
				slideAngle = ps.angle;
			}
			break;
		default:
			break;
		}
	}
}
//Oppgave 1c), kun for testing f�rst i oppgaven
void Vehicle::draw() {
    // Setter farge p� den draw funksjonen som blir tegnet etterp�
    fl_color(FL_BLUE);
    // NB ette er en funksjon som kalles!! lager ikke objekt som tidligere
    fl_circle(300, 20, 20);
    /*
    if(Fl::event_key(FL_Up)){
        ps.y = ps.y - 5;
    }
    if(Fl::event_key(FL_Down)){
        ps.y = ps.y  + 5;
    }
    if(Fl::event_key(FL_Right)){
        ps.x = ps.x  + 5;
    }
    if(Fl::event_key(FL_Left)){
        ps.x = ps.x  - 5;
    }
    */
	checkHitGoal();
	checkHitObstacle();

	auto acc = steer(ps, t.getGoals(), currentGoal); // Nyttar drivingAlgorithm. Returnerer en key med velAcc og angAcc. Denne styrer styringa. 
    // Tilsvarer velAcc
	acc.first = (fmin(fmax(-1, acc.first), 1)); // S�rgjer for at dei ligg i [-1,1]
    // Tilsvarer angAcc
	acc.second = (fmin(fmax(-1, acc.second), 1));

	if (status == Obstacle::Peel)
	{
		acc.first = 1 - 2 * (ps.vel > 0); // For at bremsing skal skje. If-setning kan ogs� brukast
		acc.second = 8;
	}

    //Disse er oppgitt i oppgaven
	ps.grip += 0.01*(1 - ps.grip);

	ps.vel += 0.006 * ps.grip * acc.first *(abs(6 - ps.vel) + 5 * ((ps.vel > 0) != (acc.first > 0)));
	ps.angle += 0.03 * ps.grip * acc.second;
    
	if (status == Obstacle::Peel)
	{
		ps.x += ps.vel*cos(slideAngle);
		ps.y += ps.vel*sin(slideAngle);
		if (abs(ps.vel) < 0.05)
		{
			status = Obstacle::None;
		}
	}
	else
	{
		ps.x += ps.vel*cos(ps.angle);
		ps.y += ps.vel*sin(ps.angle);
	}
//    Sjekker at bilen ikke er utenfor vinduet. Om den er det s� kj�rer den ikke ut, men beholder posisjonen til max verdien til vinduet 
	ps.x = fmin(ScreenWidth - vehRad, fmax(vehRad, ps.x)); // At k�yret�yet ikkje g�r utanfor. Om du brukar radiusen er valfritt, men ser betre ut.
	ps.y = fmin(ScreenHeight - vehRad, fmax(vehRad, ps.y));
    //Setter farge, som starter p� 0 og �ker med en
	fl_color(color);	//Teikner det gjeldande m�let.
	fl_begin_polygon(); //Lager at de f�r fyll
    //Lager en circle
	fl_circle(t.getGoals()[currentGoal].first, t.getGoals()[currentGoal].second, goalRad - (color + 1) * 2);
	fl_end_polygon();

	drawBody(ps);	// Teiknar med drawingAlgorithm
}

