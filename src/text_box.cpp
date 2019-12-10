#include "../include/text_box.h"


int TextBox(Display *display,const char *title, const char *text)
{
    int ScreenNumber;
    GC gc;				// graphic context
    XEvent report;
    Window window;


    // take number of root screen
    ScreenNumber = DefaultScreen ( display );

    // create window
    window = XCreateSimpleWindow ( display,
                                   RootWindow ( display, ScreenNumber ),
                                   X, Y, WIDTH, HEIGHT, BORDER_WIDTH,
                                   BlackPixel ( display, ScreenNumber ),
                                   WhitePixel ( display, ScreenNumber ) );


    // select events, which should be handled
    // ExposureMask means handling Exposure event
    // KeyPressMask - pressure of any key
    XSelectInput ( display, window, ExposureMask | KeyPressMask );

    // set title for the text box
    XStoreName(display, window, title);

    // show window on the screen
    XMapWindow ( display, window );


    // loop, for active listening of any events
    while ( 1 ) {
        // take event from query
        XNextEvent ( display, &report );


        switch ( report.type ) {
            // expose event
            case Expose :
                // wait untill all expose events will come
                if ( report.xexpose.count != 0 )
                    break;

                gc = XCreateGC ( display, window, 0 , NULL );

                XSetForeground ( display, gc, BlackPixel ( display, 0) );
                XDrawString ( display, window, gc, 20,50,
                              text, strlen(text));
                XFreeGC ( display, gc );
                XFlush(display);
                break;
            case KeyPress :
                // in case of press of any key, close connection and exit from the program
                XCloseDisplay ( display );
                _exit ( 0 );
        }
    }
}