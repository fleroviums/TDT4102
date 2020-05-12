#pragma once
#include <list>
#include <memory>

#include "FL/Fl_Widget.H"
#include "FL/Fl_PNG_Image.H"

#include "bird.h"
#include "score.h"
#include "pipe.h"
#include "BeautyBird.h"


class Track : public Fl_Widget {
private:
    void draw() override;
    void update();
    void addPipe();
    bool collision() const;
    void restart();

    std::unique_ptr<Bird> bird= std::make_unique<Bird>();

    Fl_PNG_Image game_over{"../sprites/gameover.png"};
    Fl_PNG_Image initialize_game{"../sprites/message.png"};
    Fl_PNG_Image restart_im{"../sprites/Restart.png"};

    //Legg til bakgrunnsbilder her
   
    
    
    //-----------------------------
    const int ground;
    std::list<Pipe> pipes;
    bool gameOver;
    bool initialized;

public:
    Track(int w, int h);
};

