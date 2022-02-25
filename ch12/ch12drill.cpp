/*
    g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;
    
    Point tl{100,100};

    Simple_window win {tl, xmax, ymax, "My window"};


    Axis xa {Axis::x, Point{15,300}, 280, 10, "x axis"};

    Axis ya {Axis::y, Point{15,300}, 280, 10, "y axis"};
    ya.set_color(Color::dark_red);
    ya.label.set_color(Color::cyan);

    Function sine {sin,0,100,Point{20,150},1000,50,50};
    sine.set_color(Color::green);

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::green);
    poly.set_style(Line_style::dash);

    Rectangle r {Point{200,200}, 100, 50};

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});

    poly_rect.add(Point{20,75});

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    Text t {Point{150,150}, "Hello, graphical world!"};

    t.set_font(Font::times_bold);
    t.set_font_size(20);

    Image ii {Point{100,100}, "image.jpg"};

    Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};

	Image cal {Point{225,225},"snow_cpp.gif"}; // 320*240-pixel gif
	cal.set_mask(Point{40,40},200,150);


    win.attach(xa);
    win.attach(ya);
    win.attach(sine);
    win.attach(poly);
    win.attach(r);
    win.attach(poly_rect);
    win.attach(t);
    win.attach(ii);
    win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);

    win.wait_for_button();

}
