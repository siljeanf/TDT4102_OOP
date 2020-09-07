//
//  Templates.hpp
//  oving11
//
//  Created by Silje Anfindsen on 26/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef Templates_hpp
#define Templates_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <vector>
//#include <set>
//#include <iterator>
//#include <utility>
#include <algorithm>
using namespace std;

template<typename T>
T maximum(T& a, T& b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

template<typename T>
void shuffle(vector <T> &vec) {
    for (int i= 0; i<vec.size(); ++i){
        int r = rand() % (vec.size()-i); //fra 0 til siste index i
        swap(vec[i], vec[i+r]);
    }
}


#endif /* Templates_hpp */
