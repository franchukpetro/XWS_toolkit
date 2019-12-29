#ifndef XWS_TOOLKIT_WINDOW_H
#define XWS_TOOLKIT_WINDOW_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <iostream>

#define X 0
#define Y 0
#define WIDTH 300
#define HEIGHT 100
#define WIDTH_MIN 50
#define HEIGHT_MIN 50
#define BORDER_WIDTH 5

class MyWindow{
public:
    Display *display;
    Window window;
    GC gc;

    void init_window(const char *title);
};


#endif //XWS_TOOLKIT_WINDOW_H
