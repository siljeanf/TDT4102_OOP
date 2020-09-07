//
//Person.hpp
//  oving11
//
//  Created by Silje Anfindsen on 25/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include "iteratorer.hpp"
#include <stdio.h>
#include <list>


class Person{ //skal skrive ut personobjekter til skjerm
private:
    string firstName;
    string lastName;
public:
    Person() : firstName{""}, lastName{""} {}; //konstruktør
    Person(string firstName, string lastName) : firstName{firstName}, lastName{lastName}{}; //lager en person
    
    bool operator< (const Person &p2) const;
    
    friend ostream& operator<< (ostream& os, const Person &p);
    //skal skrive ut personobjekter til skjerm
    void insertOrdered(list<Person> &l, const Person& p);
    
    
};
#endif 
