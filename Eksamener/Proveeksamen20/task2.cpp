#include "task2.h"
#include "Graph.h"
#include "Window.h"
using namespace Graph_lib;

bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height){
    if(x > r_x && x < r_x+r_width){ //if valid x
        return (y > r_y && y < r_y + r_height); //true for valid y
    }
    return false;
}
bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad){
    return ((x-c_x)*(x-c_x)+(y-c_y)*(y-c_y)) < c_rad*c_rad;   
}
map<string, Color> colors = {
    {"red", Color::red},
    {"blue", Color::blue},
    // og mer
};

Color string_to_color(string clr){
    return colors.at(clr); //tryggere enn operator[], kaster exception av seg selv:)
}

string color_to_string(Color color){
    for (auto it = colors.begin(); it != colors.end(); ++it){
        if (it->second == color){return it->first;}
    }
    return "unknown color";
}
// se mini-dak.cpp!!