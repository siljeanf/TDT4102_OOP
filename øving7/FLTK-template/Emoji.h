#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "Graph_lib.h"
#endif

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0; //virtuell funksjon

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji { //arver fra klassen Emoji
private:
    Circle face; //deklarere en variabel face i formen Circle (nytt shape element)
	

public:
	Face(Point center, int radius);
	virtual void attach_to(Graph_lib::Window& win)=0;
    //overskriver denne formen til vinduet
    //klassen er abstrakt hvis man skriver =0
};


// klassen EmptyFace er en konkret klasse som arver fra den abstrakte klassen Face
class EmptyFace : public Face {
private:
    Circle eye1; //deklarer variabler øyne i formen Circle
    Circle eye2;
    
public:
    EmptyFace(Point center, int radius); //konstruktør
    virtual void attach_to(Graph_lib :: Window& win) override; //en overlasting av attach_to fra Face
    //override gir en konkret feilmelding dersom attach_to ikke finnes i klassen det arves fra
    
};


class SmilingFace : public EmptyFace {
private:
    Graph_lib::Arc smile;
public:
    SmilingFace(Point center, int radius);
    virtual void attach_to(Graph_lib:: Window& win) override;
    
};

class WonderFace : public EmptyFace{
private:
    Graph_lib::Arc eyebrow1;
    Graph_lib::Arc eyebrow2;
    Graph_lib::Arc mouth;
    
public:
    WonderFace(Point center, int radius);
    virtual void attach_to(Graph_lib::Window& win) override;
};

class WtfFace : public Face{
private:
    Text eye1;
    Text eye2;
    Ellipse mouth;
    
public:
    WtfFace(Point center, int radius);
    virtual void attach_to(Graph_lib::Window&win) override;
    
};

class CryingFace : public EmptyFace{
private:
    Ellipse tear;
    Arc mouth;
public:
    CryingFace(Point center, int radius);
    virtual void attach_to(Graph_lib::Window &win) override;
};

class LoveFace : public Face{
private:
    Text eye1;
    Text eye2;
    Arc mouth;
public:
    LoveFace(Point center, int radius);
    virtual void attach_to(Graph_lib::Window &win)override;
};

class EmojiIncest : public Face {
private:
    Text smile;
    Text eye1;
    Text eye2;
    
public:
    EmojiIncest(Point center, int radius);
    virtual void attach_to(Graph_lib::Window &win) override;
};

