#pragma once
#include "Vehicle.h"

enum class Obstacle{Spill, Boost, Peel, None};

class Track : public Fl_Widget{
    private:
        std::vector<std::pair<double,double>> goals;
        std::vector<std::tuple<double,double,Obstacle>> obstacles;
    public:
        Track() : Fl_Widget(10, 10, 10, 10) {
            //Vilkårlig bane i første omgang..
            goals.push_back({200,300});
            goals.push_back({400,300});
            goals.push_back({500,400});
            goals.push_back({700,300});
            goals.push_back({800,200});
            obstacles.push_back({300,300,Obstacle::Peel});
            obstacles.push_back({400,400,Obstacle::Boost});
            obstacles.push_back({800,500, Obstacle::Spill});
            obstacles.push_back({500,500,Obstacle::None});
        }
        void draw() override;
        std::vector<std::pair<double, double>> getGoals() const{return goals;}
        std::vector<std::tuple<double,double,Obstacle>> getObstacles() const{return obstacles;}
};

