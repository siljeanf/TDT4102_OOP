//
//  Vehicle.cpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 10/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "Vehicle.hpp"
#include <cmath>

int Vehicle::numVehicles = 0; //Setter antall vehicles til null.

//oppg 3C: funksjon som sjekker om sirklene overlapper
bool circleCollision(double delX, double delY, double sumR){
    //avgjør om to sirkler overlapper ved å sjekke om avstand mellom sentrene er mindre enn 2*radius
    int r = (delX*delX +delY*delY); //kvadratet av faktisk avstand mellom sirklene
    if ( r >= sumR*sumR) {
        return false;
    }
    else {
        return true;
    }
}


//oppgave 3e: sjekker om kjøretøyet har truffet målet
void Vehicle::checkHitGoal(){
    auto goals = t.getGoals(); //henter ut en vektor bestående av alle målene, hvert mål består av et par: x og y koordinat
    double x = ps.x - goals[currentGoal].first;
    double y = ps.y - goals[currentGoal].second;
    if ( circleCollision(x, y , vehRad + goalRad)){ //oppdaterer nytt mål
        currentGoal = (currentGoal + 1) % goals.size(); //finner et nytt mål hvis det er nådd
    }
}

//oppgave 3f): sjekker om det har truffet et hinder
void Vehicle::checkHitObstacles(){
    for (auto& o : t.getObstacles()) //henter ut en obstacle (medlemsfuksjon i track, t)
    {
        switch (get<2>(o)) //switch tar inn typen til 3.element i tuppelen obstacle = Obstacle
        {
            case Obstacle::Boost:
                if (circleCollision(ps.x - get<0>(o), ps.y - get<1>(o), vehRad + boostRad)){
                    ps.grip = 2;//Øker grip til 2
                }
                break;
            case Obstacle::Spill:
                if (circleCollision(ps.x - get<0>(o), ps.y - get<1>(o), vehRad + spillRad)){
                    ps.grip = 0.5;//Minker grip
                }
                break;
            case Obstacle::Peel: //sklir hvis vel > 2, og at kjøretøyet kolliderer med bananskallet
                if (status != Obstacle::Peel && circleCollision(ps.x - get<0>(o), ps.y -get<1>(o), vehRad + peelRad) && ps.vel > 2){
                    status = Obstacle::Peel; //setter status til peel
                    slideAngle = ps.angle; //sparer på vinkelen kjøretøyet hadde før det sklidde
                }
                break;
                
            default:
                break;
        }
    }}
                
                
                
void Vehicle::draw(){
    double velAcc = 0;
    double angAcc = 0;
    // Setter farge på den draw funksjonen som blir tegnet etterpå
    fl_color(FL_BLUE);
    // NB dette er en funksjon som kalles!! lager ikke objekt som tidligere
    fl_circle(300, 20, 20);
    
    /*
    //styring
    if (Fl::event_key(FL_Up)) { //hvis piltast opp
        velAcc -= 1;
    }
    else if (Fl::event_key(FL_Down)) {//piltast ned
        velAcc += 1;
    }
    else if(Fl::event_key(FL_Left)){ //piltast venstre
        angAcc -=1;
    }
    else if(Fl::event_key(FL_Right)){ //piltast høyre
        angAcc +=1;
    }
    */
    
    checkHitGoal();
    checkHitObstacles();
    
    //Driving Algorithm som returnerer key med velAcc og angAcc
    auto acc = steer(ps, {}, 0); // Denne styrer styringa.
    // Tilsvarer velAcc
    acc.first = (fmin(fmax(-1, acc.first), 1)); // Sørger for at de ligger i [-1,1]
    // Tilsvarer angAcc
    acc.second = (fmin(fmax(-1, acc.second), 1));
    
    if (status == Obstacle::Peel)
    {
        acc.first = 1 - 2 * (ps.vel > 0); // For at bremsing skal skje. If-setning kan ogsÂ brukast
        acc.second = 8;
    }

    /*
    //sjekker at velAcc og angAcc er innenfor gitt intervall [-1,1]
    if (velAcc < -1 ){
        velAcc = -1;
    }
    if (velAcc > 1){
        velAcc = 1;
    }
    if (angAcc < -1){
        angAcc = -1;
    }
    if (angAcc > 1){
        angAcc = 1;
    }
     */
    

    
    //oppgitt i oppgaven
    ps.grip += 0.01*(1-ps.grip);
    ps.vel += 0.006 * ps.grip * velAcc * (6-abs(ps.vel) + 5*((ps.vel > 0) != (velAcc > 0)));
    ps.angle += 0.03 * ps.grip * angAcc;
    ps.x += ps.vel * cos(ps.angle);
    ps.y += ps.vel * sin(ps.angle);

    //hvis den treffer et bananskall skal vinkelen slideAngle beholdes med akselerasjon og ny status settes etter den er ferdig sklidd
    if (status == Obstacle::Peel){
        ps.x += ps.vel*cos(slideAngle);
        ps.y += ps.vel*sin(slideAngle);
        if (abs(ps.vel) < 0.05){ //gjelder helt til farten er mindre enn 0.05
            status = Obstacle::None;}}
    
    else{
        ps.x += ps.vel*cos(ps.angle);
        ps.y += ps.vel*sin(ps.angle);}
    
    
    //sjekker om vehicle er utenfor gitt område
    if (ps.x > ScreenWidth/2 - vehRad){
        ps.x = ScreenWidth/2 - vehRad;
    }
    
    if (ps.x < -ScreenWidth/2 + vehRad){
        ps.x = -ScreenWidth/2 + vehRad;
    }
   
    if (ps.y > ScreenHeight/2 - vehRad){
        ps.y = ScreenHeight/2 - vehRad;
    }

    if (ps.y < -ScreenHeight/2+ vehRad){
        ps.y = -ScreenHeight/2 + vehRad;
    }
    
    //ps.x = fmin(ScreenWidth - vehRad, fmax(vehRad, ps.x));
    //ps.y = fmin(ScreenHeight - vehRad, fmax(vehRad, ps.y));
    
    //Setter farge, som starter på 0 og øker med en
    fl_color(FL_RED);    //Teikner det gjeldande mÂlet.
    fl_begin_polygon(); //Lager at de får fyll
    //Lager en circle
    fl_circle(t.getGoals()[currentGoal].first, t.getGoals()[currentGoal].second, goalRad);
    fl_end_polygon();
    
    drawBody(ps);    // Teiknar med drawingAlgorithm
}
        
    
/*
    //sirkel
    fl_color(FL_RED);
    fl_begin_polygon();
    
    //fl_circle(ps.x+ScreenWidth/2 ,ps.y+ScreenHeight/2 , vehRad);
    fl_pie(ps.x+ScreenWidth/2, ps.y+ScreenHeight/2, vehRad, vehRad, ps.angle*180/3.14 + 50, ps.angle*180/3.14 - 50);
    
    
    fl_end_polygon();
   
    drawBody(ps);
*/
    
