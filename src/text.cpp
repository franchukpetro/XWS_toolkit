#include "../include/text.h"


void Text::init(MyWindow window1, const char * in_text, int x_in=X, int y_in=Y, unsigned int Width=WIDTH, unsigned int Height=HEIGHT) {
    display = window1.display;
    window = window1.window;
    gc = window1.gc;

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

//TODO: implement  expose
void Text::expose() {};