#include "Emoji.h"

Face::Face(Point c, int r) : faceCirc{c, r}
{
	faceCirc.set_fill_color(Color::yellow);
	faceCirc.set_color(Color::black);
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(faceCirc);
}

EmptyFace::EmptyFace(Point c, int r) : Face{c, r}, lEye{Point{c.x-20,c.y-20}, r/10, r/5}, rEye{Point{c.x+20,c.y-20}, r/10, r/5} {
    /*Point lPoint{static_cast<double>(c.x)*0.9,static_cast<double>(c.y)*0.9};
    Point rPoint{static_cast<double>(c.x)*1.1,static_cast<double>(c.y)*0.9};
    int eyeW = r/4;
    int eyeH = r*4;
    lEye {lPoint, eyeW, eyeH};
    rEye {rPoint, eyeW, eyeH};
    */
    lEye.set_fill_color(Color::black);
    rEye.set_fill_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(lEye);
    win.attach(rEye);
}

SmilingFace::SmilingFace(Point c, int r, int smileDegree) : EmptyFace{c, r}, smileMouth{{c.x, c.y+20},r,r,180,smileDegree}{
    smileMouth.set_color(Color::black);
    smileMouth.set_style(Line_style(Line_style::solid, 2));

}
void SmilingFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(smileMouth);
}

SadFace::SadFace(Point c, int r, int smileDegree) : EmptyFace{c,r}, sadMouth({c.x,int(c.y*1.1)},r,r,0,smileDegree){
    sadMouth.set_color(Color::black);
    sadMouth.set_style(Line_style(Line_style::solid, 2));
}
void SadFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(sadMouth);
}

AngryFace::AngryFace(Point c, int r) : SadFace{c,r, 180}, lBrow{{c.x-30,c.y-15},r,r,0,90}, rBrow{{c.x+30,c.y-15},r,r,90,180}{
    lBrow.set_color(Color::black);
    rBrow.set_color(Color::black);

}
void AngryFace::attach_to(Graph_lib::Window& win){
    SadFace::attach_to(win);
    win.attach(lBrow);
    win.attach(rBrow);
}

WinkingFace::WinkingFace(Point c, int r) : SmilingFace{c,r,360}, upperWinkLine{{c.x+20,c.y-20},{c.x+30,c.y-30}}, lowerWinkLine{{c.x+20,c.y-20},{c.x+30,c.y-10}}, eyeCover{Point{c.x+20,c.y-20}, r/10, r/5}{
    eyeCover.set_fill_color(Color::yellow);
    eyeCover.set_color(Color::yellow);
    upperWinkLine.set_color(Color::black);
    lowerWinkLine.set_color(Color::black);

    upperWinkLine.set_style(Line_style(Line_style::solid, 3));
    lowerWinkLine.set_style(Line_style(Line_style::solid, 3));

}
void WinkingFace::attach_to(Graph_lib::Window& win){
    SmilingFace::attach_to(win);
    win.attach(eyeCover);
    win.attach(upperWinkLine);
    win.attach(lowerWinkLine);
}

SurprisedFace::SurprisedFace(Point c, int r) : SmilingFace{c,r,540} {}
void SurprisedFace::attach_to(Graph_lib::Window& win){
    SmilingFace::attach_to(win);
}