#include <memory>
#include <string>
#include <vector>

struct Rectangle {
    int width;
    int height;
    int area;
} ;

struct Circle{
    int radius;
    double area;
} ;

enum Command { RECT, CIRCLE, PRINT, SUM, SORT, CLEAR, QUIT, INVALID} ;

Command getCommand(const std::string& command);

std::unique_ptr<Rectangle> make_rectangle ();

std::unique_ptr<Circle> make_circle ();

