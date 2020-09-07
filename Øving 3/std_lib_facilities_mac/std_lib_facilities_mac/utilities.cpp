//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 23/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "utilities.hpp"



int randomWithLimits (int lower_limit, int upper_limit) {
    return lower_limit + (rand() % (upper_limit+1 - lower_limit));
}

// skal plassere en tilfeldig valgt blink mellom 100 og 10000 meter.
//så lese inn vinkel og startfart fra bruker og si hvor langt unna spilleren er fra blinken
void playTargetPractice() {
    int blink = randomWithLimits(100, 1000);
    double vinkel = 0;
    double fart = 0;
    double v_x = 0;
    double v_y = 0;
    getUserInput(vinkel, fart);
    vinkel = degToRad(vinkel);
    
    getVelocityVector(vinkel, fart, v_x, v_y);

    
    double din_distanse = getDistanceTraveled(v_x, v_y);
  
    double diff = (blink - din_distanse);
    
  
        
    //skriver avstanden fra blinken
    
    double avvik = targetPractice(blink, v_x, v_y);
    cout << "Du er:" << avvik << " m " << "unna blinken. \n";
    

     //skriver om kastet er for langt eller for kort
    
    if (diff > 0) {
        cout << "skuddet ditt er for kort. \n";
    }
    else if (diff ==0) {
        cout << "WOW! Du traff rett på blinken. \n";
    }
    else {
        cout << "skuddet ditt er for langt./n ";
    }
    
    // skriver hvor lang tid kulen bruker på skuddet
    double tid = flightTime(v_y);
    
    cout << "Tiden kulen brukte på skuddet:" << tid << "sekunder\n";
    
    
}
