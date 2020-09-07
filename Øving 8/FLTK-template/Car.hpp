//
//  Car.hpp
//  FLTK-template
//

#ifndef Car_hpp
#define Car_hpp

#include "std_lib_facilities.h"
#include <stdio.h>

class Car{
private:
    int freeSeats; //indikerer antall ledige seter i bilen
    
public:
    // const garanterer at man ikke kan endre på medlemsvariabler i funksjonen
    bool hasFreeSeats() const; //returnerer true om bilen har ledige seter, og false elles.
    void reserveFreeSeat();   //«reserverer» eit ledig sete ved å dekrementere freeSeats-variabelen
    Car(int freeSeats);//konstruktøren tar inn hvor mange ledige seter bilen har
};

#endif /* Car_hpp */
