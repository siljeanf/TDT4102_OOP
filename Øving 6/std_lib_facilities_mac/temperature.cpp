//
//  temperature.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "temperature.hpp"

//hensikt: funksjonen overlaster >>-operatoren. Oppgaven dens er å hente informasjon fra en
//istream og skrive den til vår type Temps.

istream& operator>>(istream& is, Temps& t) {
    
    
        is >> t.max >> t.min;
    return is;
}

// skriver til en vektor i stedet for en variabler
vector <Temps> readTemperatures(string filename) {
    ifstream temp_file{filename}; //åpner fil
    if (!temp_file) { error("temp_file not found");}
    
    vector <Temps> temps;
    Temps t; // linje fra filen
    while (temp_file >> t) {  //temp_file.eof() gir true ved slutten av filen
        temps.push_back(t);
        
    }
    return temps;
}





