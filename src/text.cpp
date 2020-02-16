#include "../include/text.h"
#include "../include/MyDialog.h"


void Text::init(window_info wi , const char * in_text, int x_in=X, int y_in=Y, unsigned int Width=WIDTH, unsigned int Height=HEIGHT) {
    display = wi.display;
    window = wi.window;
    gc = wi.gc;

    x = x_in;
    y = y_in;
    width = Width;
    height = Height;

    text = in_text;
};

void Text::draw() {
    XDrawString(display, window, gc, x, y,
                text, strlen(text));
};


void Text::expose() {
    draw();
};