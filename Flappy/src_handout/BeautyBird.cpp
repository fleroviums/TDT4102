#include "BeautyBird.h"
#include "rotate.h"

BeautyBird::BeautyBird(char key, const char* spritePath): Bird(), sprite(spritePath), key(key){};

void BeautyBird::draw() {
    //Tegn bildet til vinduet
}

void BeautyBird::steer(){
    //Implementer en styringsfunksjon
}