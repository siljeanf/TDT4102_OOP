//
//  cannonball.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 22/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "cannonball.hpp"

#include <math.h>       /* pow */


double acclY() {
    double acc = -9.81;
    return acc;
    
}

double velY(double initVelocityY, double time) {
    double v_y=0;
    double a_y= acclY();
    v_y = initVelocityY + (time * a_y);
    return v_y;
}

double posY ( double initPosition, double initVeolocity, double time) {
    double pos_y = 0;
    double a_y = acclY();
    pos_y = initPosition + (initVeolocity * time ) + ( (a_y * pow(time, 2) )/2);
    return pos_y;
}


double posX (double initPosition, double initVeolocity, double time) {
    double pos_x = 0;
    double a_x = 0; // aks. i x-retning er 0.
    pos_x = initPosition + (initVeolocity * time ) + ( (a_x * pow(time, 2)) / 2); 
    return pos_x;
}

void printTime (double sec) {
    int h = sec/(3600);
    int min = (sec/60) - (h*60);
    int s = sec - (h*3600) - (min*60);
    cout << h << "timer, " << min <<  "minutter," << s << "sekunder." <<'\n';
}

double flightTime (double initVelocityY) {
    double a_y = acclY();
    return (-2*initVelocityY)/ (a_y);
}

// Ber brukeren om to tall, en vinkel (i grader) og en fart.
// Formålet er å endre verdien på argumentene.
// theta og absVelocity er referanser til objektene funksjonen kalles med.
void getUserInput(double& theta, double& absVelocity) {
    cout << "oppgi en vinkel  (i grader):" ;
    cin >> theta;
    cout << "\n oppgi en fart:" ;
    cin >> absVelocity;
}

// Konverterer fra grader til radianer
double degToRad(double deg) {
    return (deg * M_PI)/180;
}

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
    double v_x = cos(theta)*absVelocity;
    return v_x;
}

double getVelocityY(double theta, double absVelocity) {
    double v_y = sin(theta) * absVelocity;
    return v_y;
}

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Komponentene oppdateres gjennom referansene.
// med Vector i funksjonsnavnet tenker vi på vektor-begrepet i geometri
void getVelocityVector(double theta, double absVelocity,double& velocityX, double& velocityY) {
    velocityX = getVelocityX(theta, absVelocity);
    velocityY = getVelocityY(theta, absVelocity);
}
//skal returnere x-posisjon når kanonkulen er på bakken
double getDistanceTraveled(double velocityX, double velocityY) {
    double t = flightTime(velocityY);
    
    return posX(0, velocityX, t);
    
}


// skal returnere avviket mellom avstanden fra målet og der kula lander.
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double total_distance = getDistanceTraveled(velocityX, velocityY);
    double avvik = abs(total_distance - distanceToTarget);
    return avvik;
}

