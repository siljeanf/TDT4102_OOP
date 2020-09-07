//
//  MeetingWindow.hpp
//  FLTK-template
//
//  Created by Silje Anfindsen on 06/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#ifndef MeetingWindow_hpp
#define MeetingWindow_hpp
#include <stdio.h>
#include "std_lib_facilities.h"
#include "Window.h"
#include "GUI.h"
#include "Meeting.hpp"


using namespace Graph_lib;

class MeetingWindow : public Graph_lib::Window {
private:
    static constexpr int fieldH = 50;
    static constexpr int fieldW = 800;
    static constexpr int fieldPad = 100;
    static constexpr int buttonW = 100;
    static constexpr int buttonH = 50;
    static constexpr int buttonPad = 50;
    static constexpr int pad = 50;
    
    
    static void cb_quit(Address, Address pw);
    static void cb_add(Address, Address pw);
    
    Button quitBtn;
    Button addBtn;
   
    In_box personName;
    In_box personEmail;
    
public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    Vector_ref<Person> people;
    void addPerson();
 };



#endif /* MeetingWindow_hpp */
