//
//  cannonball.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 22/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef cannonball_hpp
#define cannonball_hpp

#include <stdio.h>

double acclY();

double velY(double initVelocityY, double time);


double posX ( double initPosition, double initVeolocity, double time);

double posY ( double initPosition, double initVeolocity, double time);

    
void printTime (double sec);

double flightTime (double initVelocityY);

// Ber brukeren om to tall, en vinkel (i grader) og en fart.
// Formålet er å endre verdien på argumentene.
// theta og absVelocity er referanser til objektene funksjonen kalles med.
void getUserInput(double& theta, double& absVelocity);

// Konverterer fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel // theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);


// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Komponentene oppdateres gjennom referansene.
// med Vector i funksjonsnavnet tenker vi på vektor-begrepet i geometri
void getVelocityVector(double theta, double absVelocity,double& velocityX, double& velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

#endif /* cannonball_hpp */
