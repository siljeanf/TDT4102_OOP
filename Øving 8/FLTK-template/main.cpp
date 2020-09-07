// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp
#include "Graph.h"
#include "Car.hpp"
#include "Person.hpp"
#include "Meeting.hpp"
#include "Window.h"
#include "MeetingWindow.hpp"


using namespace Graph_lib;

int main() {
/*
    Car c(1);
    Car c2(3);
    Car c3(4);
    //cout << c.hasFreeSeats() << '\n';
    
    Person p1("Silje", "siljeanf@stud.ntnu.no", &c);
//cout << p1.hasAvailableSeats()<<endl;
    
    Person p2 ("Ove", "ove100@stud.ntnu.no",&c3);
    Person p3 ("Kine", "kine98@hotmail.com", &c2);
    
    Meeting m2(20,10,12, trondheim, "styret", &p2);
    
    Meeting m3(20,10,12, trondheim, "excom", &p1);
    
    m3.addParticipant(&p3);
    m3.addParticipant(&p2);// & gir adressen til objektet
    

    vector <const Person*> v = m2.findPotentialCoDriver();
    
    for (auto i : v) {
        cout << *i;
    }
*/
//GRAFIKK
    Point p = {50,50};
    int w = x_max();
    int h = y_max();
    string title = "Medlemmer";
    
    MeetingWindow win(p, w, h, title);
    gui_main();
    
    
    return 0;
}

