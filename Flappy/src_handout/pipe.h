#pragma once
#include <utility>

#include "FL/Fl_Widget.H"
#include "FL/Fl_PNG_Image.H"

class Pipe : public Fl_Widget {
private:

    static Fl_PNG_Image up;
    static Fl_PNG_Image down;
    int ground, height, gap;

public:
    Pipe(int position, int ground, int height, int gap);
    void draw() override;
    void move(int speed);
    std::pair<int, int> getBounds() const;
};
