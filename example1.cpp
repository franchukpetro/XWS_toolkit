#include "include/window.h"
#include "include/button.h"
#include "include/text_box.h"


int main() {
    XEvent report;

    MyWindow window;
    window.init_window("Example");

    XMapWindow(window.display, window.window);

    TextBox text1;
    text1.init_text_box(window, "Hello, world!", 10, 10);
    text1.add_text_box();

    TextBox text2;
    text2.init_text_box(window, "Hey there!!", 10, 30);
    text2.add_text_box();

    /*
    Button button1;
    button1.init_button(window, "Button 1", 10, 50);
    button1.add_button();
    */

    // loop, for active listening of any events
    while (1) {
        // take event from query
        XNextEvent(window.display, &report);


        switch (report.type) {
            // expose event
            case Expose :
                // wait untill all expose events will come
                if (report.xexpose.count != 0)
                    break;
                window.gc = XCreateGC(window.display, window.window, 0, NULL);
                XSetForeground(window.display, window.gc, BlackPixel (window.display, 0));
                text1.add_text_box();
                text2.add_text_box();
                //button1.handler();
                XFreeGC(window.display, window.gc);
                XFlush(window.display);
                break;
            case KeyPress :
                // in case of press of any key, close connection and exit from the program
                XCloseDisplay(window.display);
                _exit(0);
        }
    }

}




