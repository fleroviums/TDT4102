#pragma once
#include "utilities.h"
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H> //NB lowercase f, compiler told me to
#include <FL/Fl.H>
#include <tuple>
#include "Track.h"

class Track; // Forward declaration


class Vehicle : public Fl_Widget{
    public:
        Vehicle(double x,double y, double angle, Track& track) : Fl_Widget(10, 10, 10, 10), status{x,y,angle}, track{track} {}
        //~Vehicle();
        void draw() final;
        void obsCollision();
    protected:
        virtual std::pair<double,double> steer() const=0;
        virtual void drawBody() const=0;
        PhysicsState status;
        const Track &track; 
        int goalIndex = 0;
        Obstacle obsStatus;
    private:
};

class PlayerVehicle : public Vehicle{
    public:
        PlayerVehicle(double x, double y, double angle, Track& track) : Vehicle(x,y,angle, track) {}
        void drawBody() const override;
        std::pair<double,double> steer() const override;

};
bool circleCollision(double delX, double delY, double sumR);