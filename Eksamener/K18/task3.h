#include <cassert>
float clip(float n, float lower, float upper){
    if(n<=lower) return lower;
    else if(n<=upper) return upper;
    return n;
}

struct Color{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    Color() : r{0}, g{0}, b{0} {}
    Color(int red, int green, int blue)
        : r{static_cast<unsigned char>(clip(red, 0,255))},
        g{static_cast<unsigned char>(clip(green, 0, 255))},
        b{static_cast<unsigned char>(clip(blue, 0, 255))}
        {}
};

//Bruker unsigned char kan ta verdier fra 0 til 255

class Image{
    private:
        Color * data;
        unsigned int width;
        unsigned int height;
    public:
        Image(int width, int height);
        Image(const Image&other); //copyconstr.
        ~Image();
        Image& operator=(Image rhs); //tilordningsoperator
        Color getPixel(int x, int y);
        void setPixel(int x, int y, Color c);
        Image grayscale();
        Image threshold(unsigned int t);
        Image operator+(Image other);
        //Color applyKernel(int x, int y, Kernel k);
        //Image convolve(Kernel k);
};

Image::Image(int width, int height) : width{width}, height{height},
        data{new Color[width*height]} {
    assert(width >= 0); // Assure seamless signed->unsigned conversion
    assert(height >= 0); // --- || ---
}
Image::Image(const Image& other) : width{other.width}, height{other.height} {
    data = new Color[width*height];
    for(int i=0;i<width*height;++i){
        data[i] = other.data[i];
    }
}

Image::~Image(){
    delete[] data;
}
//Må definere tilordningsoperator for å kunne tilordne Image-objekter en annen Image-verdi???

Color Image::getPixel(int x, int y){return data[width*y+x];}
void Image::setPixel(int x, int y, Color c){
    data[width*y+x] = c;
}

Image Image::grayscale(){
    Image bw = Image(*this); //make copy to be manipulated
    for(int i=0;i<width*height;++i){
        int pxAvg = (1/3*(data[i].r+data[i].g+data[i].b));
        int px_x = i%width;
        int px_y = (i-(i%width))/width;
        bw.setPixel(px_x, px_y, Color(pxAvg, pxAvg, pxAvg));
    }
    return bw;
}
Image Image::threshold(unsigned int t){
    Image newImg = Image(*this);
    for(int i=0;i<width*height;++i){
        if(data[i].r > t) data[i].r = 255;
        else data[i].r = 0;
        if(data[i].g > t) data[i].g = 255;
        else data[i].g = 0;
        if(data[i].b > t) data[i].b = 255;
        else data[i].b = 0;
    }
    return newImg;
}

Image Image::operator+(Image other){
    assert(width==other.width && height==other.height);
    Image added = Image(other);
    for(int i=0;i<width*height;++i){
        added.data[i].r = (data[i].r+other.data[i].r)/2;
        added.data[i].g = (data[i].g+other.data[i].g)/2;
        added.data[i].b = (data[i].b+other.data[i].b)/2;   
    }
    return added;
}