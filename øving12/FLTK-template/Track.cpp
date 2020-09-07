//
//  Track.cpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 17/04/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "Track.hpp"
#include <FL/fl_draw.H>
#include <tuple> //For å bruke tuple greia
#include <math.h>
 
Track::Track() : Fl_Widget{10,10,10,10,""},Spill{ "Sprites/spillSprite.jpg" },
Boost{ "Sprites/boostSprite.jpg" },
Peel{ "Sprites/peelSprite.jpg" }{
    
    // Eksempelbane
    constexpr int nCircles = 30; //skal ha 30 baner
    
    //setter opp hindringer
    for (size_t i = 0; i < nCircles; i++)  //size_t er alias for et en unsignet integer, brukes for mål på størrelser
    {
        Obstacle toAdd = Obstacle::None;//alle områder som ikke faller under noen av kravene under får ikke hinder
        
        if (i > 0 && (i % (nCircles / 4) == 0))
        {
            toAdd = Obstacle::Spill;
        }
        else if (i > 0 && (i % (nCircles / 2) == 0))
        {
            toAdd = Obstacle::Peel;
        }
        else if (i > 0 && (i % (nCircles / 3) == 0))
        {
            toAdd = Obstacle::Boost;
        }
        else
        { //Legger til ett pair i goals
            goals.push_back({
                ScreenWidth / 2 + ScreenWidth / 3.0*cos(i*2.0 / nCircles * 3.14),
                ScreenHeight / 2 - ScreenHeight / 3.0*sin(i*4.0 / nCircles * 3.14)
            });
            continue;
        }
        
        obstacles.push_back({
            int(ScreenWidth / 2 + ScreenWidth / 3.0*cos(i*2.0 / nCircles * 3.14)),
            int(ScreenHeight / 2 - ScreenHeight / 3.0*sin(i*4.0 / nCircles * 3.14)),
            toAdd
        });
    }
}

   
void Track::draw_t(){
    for (auto& o : obstacles){
        switch (get<2>(o)) //Tar det tredje elementet i tupelen obstacle. Ser hvilken type det er
        {
            case Obstacle::Spill:
                Spill.draw( get<0>(o) - 25, get<1>(o) - 25);
                break;
                
            case Obstacle::Peel:
                Peel.draw(get<0>(o) - 15, get<1>(o) - 15);
                break;
                
            case Obstacle::Boost:
                Boost.draw(get<0>(o) - 10, get<1>(o) - 10);
                break;
            default:
                break;
        }
        fl_color(FL_BLACK);
        for (auto & p : goals){
            fl_begin_line(); //Tegner linjer
            fl_circle(p.first, p.second, goalRad);
            fl_end_line();}
    }
}


    

