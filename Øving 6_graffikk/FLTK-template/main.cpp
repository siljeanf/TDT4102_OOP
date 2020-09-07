// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp
#include "Graph.h"
#include "Simple_window.h"
#include "temperature.hpp"
#include "filhåndtering.hpp"

using namespace Graph_lib;

int main() {
    
    
vector <Temps> temps = readTemperatures("temperatures.txt");
    
// general layout
constexpr int xmax = 1280; //størrelse på vindu
constexpr int ymax = 720;

constexpr int xoffset = 100; // avstand fra venstre side av vindet til yakse
constexpr int yoffset = 60; // avstand fra bunn av vindu til x-akse

constexpr int xspace = 40; // avstand mellom akser
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset - xspace; // lengde av akse
constexpr int ylength = ymax - yoffset - yspace;

constexpr int base_month = 0;
constexpr int end_month = 365;
    
constexpr double xscale = double(xlength)/366;
constexpr double yscale = double(ylength)/100;

//oppretter en klasse for skalering av data
class Scale {
private:
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s}{}
    int operator()(int v)const{ return cbase + (v-vbase)*scale; }
};
    
Scale xs{xoffset, base_month, xscale};
Scale ys{ymax/2,0, -yscale};

// bygger grafen
Simple_window win{Point{ 100,100 },xmax,ymax,"Temperaturer i Trondheim"};

Axis x {Axis::x, Point{xoffset,ymax/2}, xlength, (end_month - base_month)/13,
"måneder   jan   feb   mar   apr   mai   jun   jul   aug   sep   okt   nov   des "};

x.label.move(-100,0);

Axis y {Axis::y, Point{xoffset,ymax - yoffset}, ylength, 13, "grader i C" };

Open_polyline maximum;
Open_polyline minimum;

//henter ut verdier til plotting
for (int i=0; i<temps.size() ;++i){
    maximum.add(Point{ xs(i), ys(temps[i].max)});
    minimum.add(Point{xs(i),ys(temps[i].min)});
}

Text maximum_label {Point{20, maximum.point(0).y}, "Max"};
maximum.set_color(Color::red);
maximum_label.set_color(Color::red);
    
Text minimum_label {Point{20, minimum.point(0).y}, "Min"};
minimum.set_color(Color::blue);
minimum_label.set_color (Color::blue);
    
//setter alt sammen
    
win.attach(maximum);
win.attach(minimum);
    
win.attach(maximum_label);
win.attach(minimum_label);
    
win.attach(x);
win.attach(y);
    
win.wait_for_button();
    
gui_main();

};
    



    
// ble ikkke ferdig med plottingen



/*
 
 for (int i==0; i<v.size() ;++i) {
 vector <Temps> v_max;
 vector <Temps> v_min;
 v_max.push_back(v[i].max);
 v_min.push_back(v[i].min);
 }
 
 int days = v.size();
 
 //lager graf

 
 
int max(vector<int> v) {
    // assumes at least 1 element in v
    int max = v[0];
    for (unsigned int i = 1; i < v.size(); i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}
int min(vector<int> v) {
    // assumes at least 1 element in v
    int min = v[0];
    for (unsigned int i = 1; i < v.size(); i++) {
        if (v[i] < min) min = v[i];
    }
    return min;
}

constexpr int xAxisSize = 330;
constexpr int yAxisSize = 210;
constexpr int maxMonthNo = 11;

int xCoord(Point origo, int i) {
    return(origo.x + ((i * xAxisSize) / maxMonthNo));
}

int yCoord(Point origo, int temp, int totalMin, int ySpan) {
    return(origo.y - (yAxisSize * (temp - totalMin)) / ySpan);
}

int main() {
    Point tl{ 100, 100 }; // tl is Top-Left corner of our window
    Point origo{ 40, 255 };
    Simple_window win(tl, 400, 300, "Lecture 2 Example 4");
    Axis xa(Axis::x, origo, xAxisSize, maxMonthNo, "Month (August 2017 .. July 2018)");
    win.attach(xa); // attach xa to the window, win
    xa.set_color(Color::black);
    Axis ya(Axis::y, origo, yAxisSize, 7, "Celsius (-5 .. +25)");
    win.attach(ya); // attach ya
    ya.set_color(Color::black);
    
    // two vectors of max and min temperatures in Trondheim for august 2017 to july 2018
    
    
    
    vector<int> maxTemp{ 17, 16, 9, 3, 1, 0, 0, 1, 9, 19, 15, 23 };
    vector<int> minTemp{ 10, 9, 5, -2, -3, -4, -6, -6, 1, 8, 8, 13 };
    int totalMax = max(maxTemp); // knows that maxtemp must always be equal or larger than mintemp
    int totalMin = min(minTemp);
    int ySpan = totalMax - totalMin; // no of degrees to span all of y-axis
    
    Open_polyline oplMax;
    for (int i = 0; i < maxTemp.size(); i++) {
        oplMax.add(Point{ xCoord(origo,i), yCoord(origo, maxTemp[i], totalMin, ySpan) });
    }
    oplMax.set_color(Color::red);
    win.attach(oplMax);
    
    Open_polyline oplMin;
    for (int i = 0; i < minTemp.size(); i++) {
        oplMin.add(Point{ xCoord(origo,i), yCoord(origo, minTemp[i], totalMin, ySpan) });
    }
    oplMin.set_color(Color::blue);
    win.attach(oplMin);
    
    constexpr int backX = 100;
    constexpr int backY = 50;
    constexpr int back_width = 150;
    constexpr int back_height = 45;
    Rectangle background{ Point{backX, backY}, back_width, back_height }; // PPP 12.7.6
    background.set_fill_color(Color::yellow);
    win.attach(background);
    fl_color(Color::dark_red); // FLTK function; Sets the color for all subsequent drawing operations.
    Text trd{ Point{110, 75}, "Trondheim - Norway" };
    win.attach(trd);
    
    win.wait_for_button();
};

*/
