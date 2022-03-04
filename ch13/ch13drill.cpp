/*
    g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {{100,100}, xmax, ymax, "grid"};

    int x_size = win.x_max();
    int y_size = win.y_max();
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point{x,0}, Point{x,y_size});
    for (int y=y_grid; y<y_size; y+=y_grid)
        grid.add(Point{0,y}, Point{x_size,y});

    Rectangle rec00 {Point{0,0}, 100,100};
    Rectangle rec11 {Point{100,100}, 100,100};
    Rectangle rec22 {Point{200,200}, 100,100};
    Rectangle rec33 {Point{300,300}, 100,100};
    Rectangle rec44 {Point{400,400}, 100,100};
    Rectangle rec55 {Point{500,500}, 100,100};
    Rectangle rec66 {Point{600,600}, 100,100};
    Rectangle rec77 {Point{700,700}, 100,100};
    rec00.set_fill_color(Color::red);
    rec11.set_fill_color(Color::red);
    rec22.set_fill_color(Color::red);
    rec33.set_fill_color(Color::red);
    rec44.set_fill_color(Color::red);
    rec55.set_fill_color(Color::red);
    rec66.set_fill_color(Color::red);
    rec77.set_fill_color(Color::red);


    Image twohun1 {Point{200,0}, "img200.jpg"};
    Image twohun2 {Point{400,0}, "img200.jpg"};
    Image twohun3 {Point{400,200}, "img200.jpg"};

    Image onehun {Point{0,0}, "img100.jpg"};

    win.attach(grid);
    win.attach(rec00);
    win.attach(rec11);
    win.attach(rec22);
    win.attach(rec33);
    win.attach(rec44);
    win.attach(rec55);
    win.attach(rec66);
    win.attach(rec77);
    win.attach(twohun1);
    win.attach(twohun2);
    win.attach(twohun3);
    win.attach(onehun);

    int i = 0;
//    int j = 1;
    while(true) {
        win.wait_for_button();

        i++;
        if (i < 8) onehun.move(100,0);

        else {
/*
            j++;
            if (j == 8) {
                onehun.move(-700,-700);
            }
            else {
*/               onehun.move(-700,100);
                i = 0;
 //           }
        }
    }
}
