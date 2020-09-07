#include "Emoji.h"

// A yellow, empty face.
//konsktruktøren til klassen Face
Face::Face(Point center, int radius): face{center, radius} { //medlemsinitialiseringsliste, deklarerer sirkel
   
    face.set_fill_color(Color::yellow); //setter farge på sirkelen

}

// funksjon som kobler konkrete former til skjermen gjennom win.attach()
void Face::attach_to(Graph_lib::Window& win) {
    win.attach(face); //kobler formen face til skjerm med innebygd funksjon attach(Shape) F.eks Circle
}


//EmptyFace initialsierer konstruktøren i Face
EmptyFace::EmptyFace(Point center, int radius): Face{center, radius}, eye1{{center.x-15, center.y -20}, 5}, eye2{{center.x+15, center.y -20}, 5} {
    
    eye1.set_fill_color(Color::black); //setter øyefarge
    eye2.set_fill_color(Color::black);
}
    
void EmptyFace::attach_to(Graph_lib:: Window& win) {
    Face::attach_to(win); //kaller face sin attach_to funksjon
    win.attach(eye1);
    win.attach(eye2);
    
}

SmilingFace::SmilingFace(Point center, int radius) : EmptyFace{ center, radius},
smile{center, radius, radius , 190, 0} {
    //Arc(Point center, int w, int h, int sd, int ed)
    
    smile.set_color(Color::red);
 }

void SmilingFace::attach_to(Graph_lib::Window &win) {
    EmptyFace::attach_to(win);
    win.attach(smile);
}


WonderFace::WonderFace(Point center, int radius) : EmptyFace{center, radius},
eyebrow1{{center.x-20, center.y - 20}, radius/4, radius/2, 50, 180},
eyebrow2{{center.x+20, center.y - 20}, radius/4, radius/2, 0, 120},
mouth{{center.x-10, center.y+45}, radius, radius, 40, 90} {
    
    eyebrow1.set_color(Color::black);
    eyebrow2.set_color(Color::black);
    mouth.set_color(Color::black);
}

void WonderFace::attach_to(Graph_lib::Window &win) {
    EmptyFace::attach_to(win);
    win.attach(eyebrow1);
    win.attach(eyebrow2);
    win.attach(mouth);
}

WtfFace::WtfFace(Point center, int radius) : Face{center, radius}, mouth{{center.x+2,center.y+20},radius/4, radius/5}, eye1{{center.x-20, center.y-10}, ">"}, eye2{{center.x+20, center.y-10}, "<"} {
    eye1.set_color(Color::black);
    eye2.set_color(Color::black);
    mouth.set_fill_color(Color::blue);
}

void WtfFace::attach_to(Graph_lib::Window &win) {
    Face::attach_to(win);
    win.attach(mouth);
    win.attach(eye1);
    win.attach(eye2);
}

CryingFace::CryingFace(Point center, int radius) : EmptyFace(center, radius), tear{{center.x+15,center.y}, radius/15, radius/8}, mouth{{center.x, center.y+30}, radius/2, radius/2, 25,150} {
    tear.set_fill_color(Color::cyan);
    mouth.set_color(Color::red);
}

void CryingFace::attach_to(Graph_lib::Window &win) {
    EmptyFace::attach_to(win);
    win.attach(tear);
    win.attach(mouth);
}

LoveFace::LoveFace(Point center, int radius) : Face(center, radius), eye1{{center.x-20,center.y-10}, "♥"}, eye2{{center.x+20,center.y-10}, "♥"}, mouth{{center.x,center.y+15}, radius, radius/2, 160,0} {
    mouth.set_color(Color::red);
    eye1.set_color(Color::red);
    eye2.set_color(Color::red);
    
}

void LoveFace::attach_to(Graph_lib::Window &win) {
    Face::attach_to(win);
    win.attach(mouth);
    win.attach(eye1);
    win.attach(eye2);
}

EmojiIncest::EmojiIncest(Point center, int radius) : Face(center, radius),
eye1{ {center.x-30,center.y-10}, "🔥"}, eye2{{center.x+16,center.y-10}, "🔥"}, smile{ {center.x-4,center.y+25}, "🍔" } {
    

}

void EmojiIncest::attach_to(Graph_lib::Window &win) {
    Face::attach_to(win);
    win.attach(smile);
    win.attach(eye1);
    win.attach(eye2);
}
