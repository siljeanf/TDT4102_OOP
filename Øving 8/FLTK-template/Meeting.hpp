//
//  Meeting.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 04/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#ifndef Meeting_hpp
#define Meeting_hpp

#include <stdio.h>
#include "std_lib_facilities.h"
#include "Person.hpp"

enum Campus {
trondheim, gjøvik, bergen //får verdiene 0,1,2
};

//overlaster << operatoren
ostream& operator<< (ostream& os, const Campus& c);


class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set< const Person*> participants;
    static set<const Meeting*> meetings;
    
public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    
    const Person getLeader() const;
    // const bak funksjonen betyr at funksjonen ikke skal endre på noe
    // const foran funksjonne betyr at funksjonen returnerer en verdi av typen int/string/person etc. som er konstant
    
    void addParticipant(const Person* p);
    
    // konstruktør
    Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader);

    //destruktør
    ~Meeting();
    
    vector<string> getParticipantList();
    vector < const Person*> findPotentialCoDriver();

};
//overlaster << operatoren
ostream& operator<< (ostream& os, Meeting& m);

#endif /* Meeting_hpp */
