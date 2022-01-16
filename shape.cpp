#include "shape.h"
#include <iostream>
#include <map>

using namespace std;

unique_ptr<Rectangle> make_rectangle(){
    int r_width, r_height, r_area;
    cin >> r_width >> r_height;
    r_area = r_width * r_height;

    unique_ptr<Rectangle> rec(new Rectangle {r_width, r_height, r_area});
    return rec;
}

unique_ptr<Circle> make_circle(){
    int c_radius; double c_area;
    cin >> c_radius; c_area = (c_radius * c_radius) * 3.14;

    unique_ptr<Circle> cir(new Circle {c_radius, c_area});
    return cir;
}

Command getCommand(const string& command){
    Command cmd;

    if(command == "rect"){ cmd = RECT; }
    else if(command == "circle") { cmd = CIRCLE; }
    else if(command == "print") { cmd = PRINT; }
    else if (command == "sum") { cmd = SUM; }
    else if (command == "sort") { cmd = SORT; }
    else if (command == "clear") {cmd = CLEAR; }
    else if (command == "quit") {cmd = QUIT; }
    else { cmd = INVALID; }

    return cmd;
}

