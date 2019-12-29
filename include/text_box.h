#ifndef XWS_TOOLKIT_TEXT_BOX_H
#define XWS_TOOLKIT_TEXT_BOX_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include "window.h"


class TextBox{
public:
    MyWindow in_window;
    const char *text;
    int x;
    int y;

    void init_text_box(MyWindow window, const char *in_text, int in_x, int in_y);
    void add_text_box();
};





#endif //XWS_TOOLKIT_TEXT_BOX_H
