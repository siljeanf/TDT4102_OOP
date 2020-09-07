//
//  Meeting.cpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 04/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "Meeting.hpp"

ostream& operator<< (ostream& os, const Campus& c){
    if (c == Campus::trondheim) {
        os << "Trondheim";}
    if (c == Campus::gjøvik) {
        os << "Gjøvik";}
    if (c== Campus::bergen) {
        os << "Bergen";}
    return os;
}

int Meeting::getDay() const{ //getfunksjoner skal ikke kunne endre på klassen, har const til slutt
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

string Meeting::getSubject() const {
    return subject;
}

Campus Meeting::getLocation() const {
    return location;
}

const Person Meeting::getLeader() const{
    return *leader;
}

void Meeting::addParticipant(const Person *p) {
    participants.insert(p);
}

set<const Meeting*> Meeting::meetings;

//konstruktør
Meeting::Meeting( int day, int startTime, int endTime, Campus location, string subject, const Person* leader) :
day{day}, startTime{startTime}, endTime{endTime}, subject{subject}, location{location}, leader{leader} {
    //legger til leder i participants
    addParticipant(leader);
    
    //legger til møte i meetings
    meetings.insert(this);
}
//destruktør
Meeting::~Meeting() {
    meetings.erase(this);
}

vector<string> Meeting::getParticipantList() {
    vector <string> participantList{};
    for (auto p : participants) {
        string name = p->getName();
        participantList.push_back(name);
    }
    return participantList;
}

ostream& operator<< (ostream& os,  Meeting& m) {
    os << "møtets tema er: " << m.getSubject() << '\n' << "møtets location er: " << m.getLocation() << '\n'
    << "møtet starter kl. " << m.getStartTime() << '\n' << "møtet slutter kl. " << m.getEndTime() << '\n'
    << "møtets leder har " << m.getLeader() << '\n' << "møtets deltagere er: " << '\n';
    
    for (auto d : m.getParticipantList() ) {
        os << d << '\n';
    }
    return os;
}

vector < const Person*> Meeting:: findPotentialCoDriver(){
    vector < const Person*> freeCarSeats;
    
    for (auto meeting : meetings) {
        if (meeting->day == day and abs(meeting->startTime-startTime) <= 1 and abs(meeting->endTime-endTime) <= 1 and
            location == meeting->location &&this!=meeting) {
            //løkker gjennom participants
            
                for (auto p : meeting->participants) {
                    
                    if (p->hasAvailableSeats()) {
                        freeCarSeats.push_back(p);
                    }
                }
            }
        }
    return freeCarSeats;
}
