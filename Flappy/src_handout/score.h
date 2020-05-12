#pragma once
#include <array>
#include <vector>

#include "FL/Fl_Widget.H"
#include "FL/Fl_PNG_Image.H"

class Score : public Fl_Widget {
private:
    static std::array<Fl_PNG_Image, 10> sprites;
    int score = 0;

    void draw() override;
    std::vector<int> getDigits();
    bool initialized;
public:
    Score(int x, int y);
    void increment();
    int getScore() const;
    void initialize(){initialized = true;}
    void reset();
};
