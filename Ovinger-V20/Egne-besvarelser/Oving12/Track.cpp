#include "Track.h"
void Track::draw(){
    fl_color(FL_BLACK);
    fl_line_style(FL_SOLID);
    for(auto c : goals){
        fl_circle(c.first, c.second, goalRadius); //track tiles outline
    }
    for(auto o : obstacles){
        double obsRadius = 0;
        switch (std::get<2>(o))
        {
        case Obstacle::Peel:
            fl_color(FL_YELLOW); obsRadius = peelRadius; break;
        case Obstacle::Spill:
            fl_color(FL_BLACK); obsRadius = spillRadius; break;
        case Obstacle::Boost:
            fl_color(131); obsRadius = boostRadius; break;  //Orange
        default:
            fl_color(7); obsRadius = goalRadius; break; //White, on None
        }
        fl_pie(std::get<0>(o)-obsRadius, std::get<1>(o)-obsRadius, obsRadius*2-1, obsRadius*2-1, 0, 360);
    }
}
