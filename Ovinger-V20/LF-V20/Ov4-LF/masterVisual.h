#pragma once
#include "Graph.h"
#include "Simple_window.h"

constexpr int winW = 500;
constexpr int winH = 500;

constexpr int padY = winH/17; 
constexpr int padX = winW/11; 
constexpr int radCircle = padX/8;


constexpr int btnW = padX;
constexpr int btnH = padY;
constexpr int inBoxW = winW -3*padX-btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX,padY};
constexpr Point upperLeftCornerBtn = Point{winW-padX-btnW,padY};



class MastermindWindow:public Window{
public:
    MastermindWindow(Point xy,int w, int h, const string& title);
    static void cb_guess(Address, Address pw){
        reference_to<MastermindWindow>(pw).newGuess();
    }
    string wait_for_guess();
    Vector_ref<Rectangle> vr;
    Vector_ref<Circle> vc;
    string getInput(unsigned int n, char lower, char upper);
    void redraw(){
        Fl::wait();
        Fl::redraw();
    }
private:
    void newGuess(){button_pressed = true;}
    bool button_pressed;
    Button guessBtn;
    In_box guess;
};




void addGuess(MastermindWindow &mwin, const string code,const int size, const char startLetter, const int round);
void hideCode(MastermindWindow &mwin,const int size);

void addFeedback(MastermindWindow &mwin,const int correctPosition, const int correctCharacter,
const int size, const int round);
