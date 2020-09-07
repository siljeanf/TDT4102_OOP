//
//  Person.cpp
//  oving11
//
//  Created by Silje Anfindsen on 25/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "Person.hpp"

ostream& operator<< (ostream& os, const Person &p){
    os << p.firstName << " " << p.lastName << endl;
    return os;
}


bool Person::operator < (const Person &p2) const{
    return firstName < p2.firstName;
}


//skal sette inn et personobjekt i listen
void Person:: insertOrdered(list<Person> &l, const Person& p) {
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++) {
        if (p< *it) {
            l.insert(it, p);
            return;
        }
    }
    l.push_back(p);
}
