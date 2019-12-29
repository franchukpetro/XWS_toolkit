#include "../include/window.h"


window_info init_window(const char *title) {
    int ScreenNumber;
    Window window;

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        _exit(1);
    }

    // take number of root screen
    ScreenNumber = DefaultScreen (display);

    int blackColor = BlackPixel(display, ScreenNumber);
    int whiteColor = WhitePixel(display, ScreenNumber);

    // create window
    window = XCreateSimpleWindow(display,
                                 RootWindow (display, ScreenNumber),
                                 X, Y, WIDTH, HEIGHT, BORDER_WIDTH,
                                 BlackPixel (display, ScreenNumber),
                                 WhitePixel (display, ScreenNumber));



    // select events, which should be handled
    // ExposureMask means handling Exposure event
    // KeyPressMask - pressure of any key
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // set title for the text box
    XStoreName(display, window, title);

    // create graphical context
    GC gc = XCreateGC(display, window, 0, NULL);

    window_info wi = {display, window, gc, blackColor, whiteColor};

    return wi;
}




