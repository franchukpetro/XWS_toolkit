#include "include/window.h"
#include "include/button.h"
#include "include/text_box.h"


int main() {
    XEvent report;

    window_info wi = init_window("Example");
    XMapWindow(wi.display, wi.window);

    add_text_box(wi, "Hello!", 10, 10);
    button_t button = add_button("Button", wi, 30, 30);


    // loop, for active listening of any events
    while (1) {
        // take event from query
        XNextEvent(wi.display, &report);


        switch (report.type) {
            // expose event
            case Expose :
                // wait untill all expose events will come
                if (report.xexpose.count != 0)
                    break;
                wi.gc = XCreateGC(wi.display, wi.window, 0, NULL);
                XSetForeground(wi.display, wi.gc, BlackPixel (wi.display, 0));
                add_text_box(wi, "Hello, world!", 10, 10);
                handler(wi, button);
                XFreeGC(wi.display, wi.gc);
                XFlush(wi.display);
                break;
            case KeyPress :
                // in case of press of any key, close connection and exit from the program
                XCloseDisplay(wi.display);
                _exit(0);
        }
    }
}




