#include "pipe.h"


void Pipe::draw() {
    up.draw(x(), ground-height, up.w(), height);
    down.draw(x(), ground-height-gap-down.h(), down.w(), down.h());
}

void Pipe::move(int speed) {
    x(x() - speed);
}

Pipe::Pipe(int position, int ground, int height, int gap) 
    : Fl_Widget(position, 0, 52, 400), ground{ground}, height{height}, gap{gap} {}

std::pair<int, int> Pipe::getBounds() const {
    int bottom = ground-height;
    return std::make_pair(bottom-gap, bottom);
}

Fl_PNG_Image Pipe::up{"../sprites/pipe-green.png"};
Fl_PNG_Image Pipe::down{"../sprites/pipe-green-down.png"};