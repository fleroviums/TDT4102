#include <cstdlib>
#include <iostream>

#include "constants.h"
#include "track.h"


void Track::draw() {
    //Tegn bakgrunn her


    if(!initialized){
        initialize_game.draw(w()/2 - initialize_game.data_w()/2, 0);
        if(Fl::event_key(' ')){
            initialized = true;
            bird->initializeGame();
            //score->initialize();
        }
        return;
    }    

    if(!gameOver){
        update();    
    } 
    //Tegn pipes her

    if(gameOver){
        game_over.draw(this->w()/2 - game_over.data_w()/2, this->h()/2);
        restart_im.draw(this->w()/2 - restart_im.data_w()/2, 2*this->h()/3);
        if (Fl::event_key(FL_Enter)){
            restart();
        }
    }    
}


void Track::restart() {
    gameOver = false;
    initialized = false;
    bird->reset();
    //score->reset();
    pipes.clear();
}

void Track::update() {
    // Check for collision

    for (auto it = pipes.begin(); it != pipes.end();) {
        // Update pipes
        
        if (it->x() <= birdPosition && it->x() > birdPosition - speed) {
            // Count points
        }

        // Remove pipes no longer visible
        if (it->x() < -it->w()) {
            it = pipes.erase(it);
        }
        else {
            ++it;
        }
    }
    // Add pipes
}


void Track::addPipe() {
    // Adds a pipe every 4*pipeWidth
    static int position = pipeWidth*4;
    position+= speed;
    if (position > pipeWidth * 4) {
        int height = rand() % maxPipeHeight;
        pipes.emplace_back(this->w(), ground, height, pipeGap);
        position = 0;
    }
}

bool Track::collision() const {
    // Checks if bird has collided with ground or a pipe
    // Collides with ground
    if (bird->y() + bird->h() >= ground) {
        return true;
    }

    // No pipes to collide with
    if (!pipes.size()) {
        return false;
    }

    // Can only collide with first pipe
    const Pipe& pipe = pipes.front();

    // auto [top, bottom] = pipe.getBounds(); // Structured bindings requires C++17
    // C++14 for de på mac:
    auto bound = pipe.getBounds();
    int top = bound.first;
    int bottom = bound.second;
    return (bird->x() + bird->w() >= pipe.x() + collisionMargin && bird->x() <= pipe.x() + pipe.w() - collisionMargin)
        && ((bird->y() <= top - collisionMargin) || (bird->y() + bird->h() >= bottom + collisionMargin));
}


Track::Track(int w, int h) :
    Fl_Widget(0, 0, w, h),
    //Endre ground til å være avhengig av base
    ground(h),
    gameOver{false},
    initialized{false} {}
