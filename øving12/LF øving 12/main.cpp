// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
int main() {
    Fl_Double_Window* win = new Fl_Double_Window{400, 400, 400, 400};
    win->color(FL_RED);
    win->end();
    win->show();
    Fl::run();
    

};

