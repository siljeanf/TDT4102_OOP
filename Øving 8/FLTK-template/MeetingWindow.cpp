//
//  MeetingWindow.cpp
//  FLTK-template


#include "MeetingWindow.hpp"
using namespace Graph_lib;
//konstruktør
MeetingWindow::MeetingWindow( Point xy, int w, int h, const string& title) : Window{ xy, w, h,  title}, quitBtn(Point{ x_max()-3*pad, pad }, buttonW, buttonH, "Quit", cb_quit), addBtn({xy.x+fieldPad, xy.y+4*pad+2*fieldH}, buttonW, buttonH, "Add person", cb_add), personName{{xy.x + fieldPad, xy.y + (pad+fieldH) }, fieldW, fieldH, "Name"}, personEmail{{ xy.x+fieldPad, xy.y + 2*(pad+fieldH)}, fieldW, fieldH, "Email"}{
    
        attach(quitBtn);
        attach(addBtn);
        attach(personName);
        attach(personEmail);
}

void MeetingWindow::addPerson() {
    string name = personName.get_string();
    string email = personEmail.get_string();
    Person p(name, email);
    people.push_back(p);
    cout << '\n' << p;
}


void MeetingWindow::cb_quit(Address, Address pw) {
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_add(Address, Address pw) {
    reference_to<MeetingWindow>(pw).addPerson();
}

