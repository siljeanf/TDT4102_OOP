//
//  Person.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 04/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include "std_lib_facilities.h"
#include "Car.hpp"

class Person {
private:
    string name;
    string email;
    Car* car; //en peker til Car

public:
    Person( string name, string email,Car* car=nullptr);
    //default argument deklarerers i hpp-filen og må skrives sist
    //nullptr setter defaultverdi til car til 0
    
    string getName() const;
    string getEmail() const;
    void setEmail(string email);
    bool hasAvailableSeats() const;
    
    friend ostream& operator<< (ostream& os, const Person& p);
};





#endif /* Person_hpp */
