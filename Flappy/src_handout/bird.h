#pragma once

#include "FL/Fl_Widget.H"
#include "FL/Fl_PNG_Image.H"

class Bird : public Fl_Widget {
protected:
    double velocity = 0;
    bool stopBird;
    void update();
private:
    
    void draw() override;
    virtual void steer();
    
public:
    Bird();
    void setGameOver(){stopBird = true;}
    void initializeGame(){stopBird = false;}
    void reset();
};
