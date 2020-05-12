#include "rotate.h"
#include "FL/fl_draw.H"


void draw(Fl_RGB_Image& image) {
    int w = image.w();
    int h = image.h();
    int d = image.d();
    const char *const data = image.data()[0];
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            unsigned char r = data[(i + j * w) * d];
            unsigned char g = data[(i + j * w) * d + 1];
            unsigned char b = data[(i + j * w) * d + 2];
            if (d > 3 && data[(i + j * w) * d + 3] == 0) {
                //transparency
                continue;
            }

            fl_color(r, g, b);
            fl_begin_line();
            fl_vertex(i, j);
            fl_vertex(i + 1, j + 1);
            fl_end_line();
        }
    }
}

void drawRotatedImage(Fl_RGB_Image& image, int x, int y, int r)
{
    int w = image.w();
    int h = image.h();

    fl_push_matrix(); // Lagre forrige state
    fl_translate((x + w / 2), (y + h / 2));
    fl_rotate(r); // Rotasjonen er om øvre venstre hjørne, derfor translations i tillegg.
	fl_translate(-w / 2, -h / 2);

	draw(image);

	fl_pop_matrix(); // Hente forrige state
}
