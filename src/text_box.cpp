#include "../include/text_box.h"


void TextBox::init_text_box(MyWindow window, const char *in_text, int in_x, int in_y){
    in_window = window;
    text = in_text;
    x = in_x;
    y = in_y;
}

void TextBox::add_text_box()
{
    XDrawString(in_window.display, in_window.window, in_window.gc, x, y,
                text, strlen(text));
}

