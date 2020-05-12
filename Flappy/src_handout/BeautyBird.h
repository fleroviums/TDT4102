#include "bird.h"

class BeautyBird : public Bird {
    private:
    void draw() override;
    void steer() override;
    Fl_PNG_Image sprite;
    char key;
    
    public:
    BeautyBird(char key, const char* spritePath);
    

};