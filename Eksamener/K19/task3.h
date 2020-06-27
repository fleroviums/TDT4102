#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
using namespace Graph_lib;
constexpr int dispWidth = 10;
constexpr int dispHeight = 10;
constexpr int ridesPerDay = 2;

struct Location{
    string name;
    Point p;
    Location(string str, Point pt);
};
Location::Location(string str, Point pt) : name{str}, p{pt} {}

class BikeStation{
    private:
        Location loc;
        unsigned int capacity;
        unsigned int bikes;
        Vector_ref<Shape> display;
    public:
        void setBikes(unsigned int num);
        unsigned int getBikes();
        string getName(){return loc.name;}
        unsigned int getCapacity(){return capacity;}
        string status();
        string status_ss();
        BikeStation(Location where, unsigned int cap, unsigned int numBikes) : loc{where}, capacity{cap}, bikes{numBikes} {
            Rectangle rect = Rectangle(loc.p, dispWidth, dispHeight);
            rect.set_fill_color(Color::white);
            Text stName = Text(loc.p, loc.name);
            stName.set_color(Color::blue);
            stName.set_font_size(20);
            Text stStatus = Text({loc.p.x+2, loc.p.y+15}, status());
            stStatus.set_color(Color::black);
            display.push_back(rect);
            display.push_back(stName);
            display.push_back(stStatus);
        }
};

map<string, int> simulateOneDay(vector<BikeStation*> stations);
