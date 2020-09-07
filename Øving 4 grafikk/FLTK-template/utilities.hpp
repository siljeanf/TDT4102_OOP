//
//  utilities.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 29/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>
#include "std_lib_facilities.h"

int incrementByValueNumTimes (int startValue, int increment, int numTimes);


int incrementByValueNumTimesRef();

void incrementByValueNumTimesRef(int &startValue, int &increment, int &numTimes);

void swapNumbers(int &a,int &b);


void randomizeVector( vector <int> &v, int n);

void sortVector(vector <int> &vr);

int medianOfVector(vector <int> vr);

string randomizeString(char lower, char upper, int antall);

string readInputToString(char lower, char upper, int n);

int countChar(string str, char letter);

#endif /* utilities_hpp */


