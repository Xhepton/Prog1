/*
    g++ ch15drillfirst.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {
    return 1;
}
double slope(double x) {
    return x/2;
}
double square(double x) {
    return x*x;
}
double sloping_cos(double x) {
    return cos(x)+slope(x);
}

int main() {

    using namespace Graph_lib;

    //600-by-600 window
    constexpr int xmax = 600;
    constexpr int ymax = 600;

    //x and y axis
    Axis xa {Axis::x, Point{0,300}, xmax, xmax/20, "1 == 20 pixels"};
    Axis ya {Axis::y, Point{300,600}, ymax, ymax/20, "1 == 20 pixels"};


    // with (0,0) at (300,300)
    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    Point orig{x_orig,y_orig};

    //range [-10, 11]
    constexpr int r_min = -10;
    constexpr int r_max = 11;

    //using 400 points
    constexpr int n_points = 400;

    //x scale 20 and y scale 20
    constexpr int x_scale = 20;
    constexpr int y_scale = 20;



    Simple_window win {{100,100}, xmax, ymax, "Function graphs"};

    Function s1 {one, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Text ts {Point {90,y_orig+y_orig/2-75}, "x/2"};
    Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function cosine {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s4 {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};

    //coloring
    xa.set_color(Color::red);
    ya.set_color(Color::red);
    cosine.set_color(Color::blue);

    win.attach(xa);
    win.attach(ya);
    win.attach(s1);
    win.attach(s2);
    win.attach(ts);
    win.attach(s3);
    win.attach(cosine);
    win.attach(s4);

    win.wait_for_button();
}