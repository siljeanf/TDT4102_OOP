//
//  temperature.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef temperature_hpp
#define temperature_hpp

#include <stdio.h>
#include "std_lib_facilities.h"


struct Temps {float min; float max;};

istream& operator>>(istream& is, Temps& t);
//operator som overlaste >> operatoren ved å hente informasjon fra
//en istream og skrive den til typen Temps


vector <Temps> readTemperatures(string filename);


#endif /* temperature_hpp */
