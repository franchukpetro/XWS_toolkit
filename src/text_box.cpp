#include "../include/text_box.h"


void add_text_box(window_info wi, const char *text, int x, int y)
{
    XDrawString(wi.display, wi.window, wi.gc, x, y,
                text, strlen(text));
}


