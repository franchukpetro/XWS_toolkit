#ifndef PROJECT_WIDGET_H
#define PROJECT_WIDGET_H


#include <X11/Xlib.h>

class MyWidget {
public:

    Display *display;
    Window window;
    GC gc;

    int x;
    int y;
    unsigned int width;
    unsigned int height;

    void init(int x, int y);

    void remove();


};

#endif //PROJECT_WIDGET_H
