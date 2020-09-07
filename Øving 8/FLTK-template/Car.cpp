//
//  Car.cpp
//  FLTK-template

#include "Car.hpp"


Car::Car(int freeSeats) : freeSeats(freeSeats) {} //deklarerer medlemsinitialiseringsliste


bool Car::hasFreeSeats() const{
    if (freeSeats > 0){
        return true;
    }
    else {
        return false;
    }
}

void Car::reserveFreeSeat() {
    freeSeats --;
}


