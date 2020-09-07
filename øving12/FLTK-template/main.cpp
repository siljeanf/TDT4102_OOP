
#include <FL/Fl.H>
#include "std_lib_facilities.h"
#include <FL/Fl_Double_Window.H>
#include "Vehicle.hpp"

#include <chrono> 
#include <thread>
int main() {
    //dynamisk allokering
        Fl_Double_Window* win = new Fl_Double_Window{400, 400, 400, 400};
        win->color(FL_RED);
        win->end();
        win->show();
        Fl::run();
    
    
    /*
    unique_ptr <Fl_Double_Window> dwin = make_unique<Fl_Double_Window>(ScreenWidth, ScreenHeight, "window") ; //konstruerer vinduet
    //åpne et tomt vindu
   auto v = new Vehicle{1,0,0,0,0,0};
    dwin->end();
    dwin->show();
    //dwin->color(FL_BLACK);
    auto next = chrono::steady_clock::now();
    while ( dwin->shown() ) {
        this_thread::sleep_until(next);
        next += chrono::microseconds(1000000 / 60);
        Fl::check();
        Fl::redraw();}
    */
    
    
    //v->draw();

    return 0;
}


