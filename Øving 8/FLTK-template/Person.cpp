//
//  Person.cpp
//  FLTK-template


#include "Person.hpp"

Person::Person(string name, string email,Car* car) : car(car), name(name), email(email) {};


string Person::getName() const{
    return name;    
}

string Person:: getEmail() const{
    return email;
}


void Person :: setEmail(string email) {
    this ->email = email; //setter email-privat variabelene lik argumentet i funksjonen
}

bool Person:: hasAvailableSeats() const{
    if ( (car!=0) and (car->hasFreeSeats()) ) { //peker på typen car som sjekker om den har hasFreeSeats
        return true;
    }
    else {
        return false;
    }
}


ostream& operator<< (ostream& os, const Person& p) {
    os << "navn: " << p.name << "\n Email: " << p.email << "\n";
    return os;
};


