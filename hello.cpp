#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <string.h>

#define X 900
#define Y 300
#define WIDTH 200
#define HEIGHT 70
#define WIDTH_MIN 50
#define HEIGHT_MIN 50
#define BORDER_WIDTH 5
#define TITLE "Example"
#define ICON_TITLE "Example"
#define PRG_CLASS "Example"


// Function that gives properties of program to window manager
static void SetWindowManagerHints (
        Display * display, 	// Pointer on Display structure
        char * PClass, 		// Class of a program
        char * argv[],   	// Arguments of a program
        int argc,
        Window window,    	// Identificator of the window
        int x,     			// Coordinates of the window
        int y,
        int win_wdt,		// Width of the window
        int win_hgt,  		// Height of the window
        int win_wdt_min,	// Minimal possible width of the window
        int win_hgt_min, 	// Minimal possible height of the window
        char * ptrTitle,  	// Window title
        char * ptrITitle,	// Window pictogram title
        Pixmap pixmap
)
{
    XSizeHints size_hints; // Size info

    XWMHints wm_hints;
    XClassHint class_hint;
    XTextProperty windowname, iconname;


    // Convert window name and icon name to XTextProperty
    if ( !XStringListToTextProperty (&ptrTitle, 1, &windowname ) ||
         !XStringListToTextProperty (&ptrITitle, 1, &iconname ) ) {
        puts ( "No memory!\n");
        _exit ( 1 );
    }


    size_hints.flags = PPosition | PSize | PMinSize;
    size_hints.min_width = win_wdt_min;
    size_hints.min_height = win_hgt_min;
    wm_hints.flags = StateHint | IconPixmapHint | InputHint;
    wm_hints.initial_state = NormalState;
    wm_hints.input = True;
    wm_hints.icon_pixmap= pixmap;
    class_hint.res_name = argv[0];
    class_hint.res_class = PClass;

    // set window manager properties
    XSetWMProperties ( display, window, &windowname,
                       &iconname, argv, argc, &size_hints, &wm_hints,
                       &class_hint );
}


int main(int argc, char *argv[])
{
    Display * display;
    int ScreenNumber;
    GC gc;				// graphic context
    XEvent report;
    Window window;

    // Conect to X Server
    if ( ( display = XOpenDisplay ( NULL ) ) == NULL ) {
        puts ("Can not connect to the X server!\n");
        _exit ( 1 );
    }

    // take number of root screen
    ScreenNumber = DefaultScreen ( display );

    // create window
    window = XCreateSimpleWindow ( display,
                                   RootWindow ( display, ScreenNumber ),
                                   X, Y, WIDTH, HEIGHT, BORDER_WIDTH,
                                   BlackPixel ( display, ScreenNumber ),
                                   WhitePixel ( display, ScreenNumber ) );

    // set properties for window manager
    SetWindowManagerHints ( display, PRG_CLASS, argv, argc,
                            window, X, Y, WIDTH, HEIGHT, WIDTH_MIN,
                            HEIGHT_MIN, TITLE, ICON_TITLE, 0 );

    // select events, which should be handled
    // ExposureMask means handling Exposure event
    // KeyPressMask - pressure of any key
    XSelectInput ( display, window, ExposureMask | KeyPressMask );

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
                              "Hello, world!", strlen ( "Hello world!" ) );
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