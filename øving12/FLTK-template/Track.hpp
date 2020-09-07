//
//  Track.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 17/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#ifndef Track_hpp
#define Track_hpp

#include <stdio.h>
#include <FL/Fl_Widget.H>
#include <vector>
#include <FL/Fl_JPEG_Image.H>
#include "utilities.hpp"
#include "std_lib_facilities.h"
#include <tuple>

class Track : public Fl_Widget {
private:
    vector< pair <double,double>> goals; //vektor bestående av x, y posisjon til målet
    vector< tuple <double,double, Obstacle>> obstacles; //vektor bestående av tupler som representerer en hindring på banen
    void draw_t(); //tegner opp banen
    
public:
    Track(); //konstruktør til track ( lager banen)
    const auto& getGoals() const{//Returnerer konst referanse til goals vektoren
        return goals;}
    
    const auto& getObstacles() const {
        return obstacles;} //returnerer konst refereanse til hindringer
    
    Fl_JPEG_Image Spill, Boost, Peel;
    
};



#endif /* Track_hpp */
