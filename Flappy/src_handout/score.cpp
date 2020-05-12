#include "constants.h"
#include "score.h"

std::array<Fl_PNG_Image, 10> Score::sprites {
    Fl_PNG_Image{"../sprites/0.png"},
    Fl_PNG_Image{"../sprites/1.png"},
    Fl_PNG_Image{"../sprites/2.png"},
    Fl_PNG_Image{"../sprites/3.png"},
    Fl_PNG_Image{"../sprites/4.png"},
    Fl_PNG_Image{"../sprites/5.png"},
    Fl_PNG_Image{"../sprites/6.png"},
    Fl_PNG_Image{"../sprites/7.png"},
    Fl_PNG_Image{"../sprites/8.png"},
    Fl_PNG_Image{"../sprites/9.png"},
};

Score::Score(int x, int y) : Fl_Widget(x, y, scoreWidth, scoreHeight) {}

void Score::increment() {
    score++;
}


void Score::draw() {
    std::vector<int> digits = getDigits();
    int x = this->x() - scoreWidth*(digits.size() / 2.0);
    for (int digit : digits) {
        sprites[digit].draw(x, y());
        x+=scoreWidth;
    }
}

std::vector<int> Score::getDigits() {
    std::vector<int> digits;
    int temp = score;
    while (temp >= 10) {
        digits.insert(digits.begin(), temp % 10);
        temp /= 10;
    }
	digits.insert(digits.begin(), temp);

    return digits;
}

int Score::getScore() const {
    return score;
}


void Score::reset() {
    score = 0;
    initialized = false;
}