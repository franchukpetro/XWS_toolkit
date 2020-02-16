#include <iostream>
#include "include/window.h"
#include "include/widget.h"
#include "include/text.h"
#include "include/button.h"
#include "include/MyDialog.h"

int main() {
    MyDialog dialog;
    dialog.init("Example", 20, 20, 300, 200);

    Text text_box;
    text_box.init(dialog.wi, "Error, proceed?", 20,20, 10, 10);
    text_box.draw();

    Button button1;
    button1.init(dialog.wi, 35, 35, "Ok");
    button1.draw();


    Button button2;
    button2.init(dialog.wi, 100, 35, "Cancel");
    button2.draw();

    dialog.add_widget(text_box);
    dialog.add_widget(button1);
    dialog.add_widget(button2);


    XEvent report;
    int temp_res1, temp_res2;

    // loop, for active listening of any events
    while (1) {
        // take event from query
        XNextEvent(dialog.wi.display, &report);

        if (report.type == MotionNotify) {
            if (button1.button_mouseover_changed(&report.xmotion) || button2.button_mouseover_changed(&report.xmotion)) {
                report.type = Expose;
            }
        }

        switch (report.type) {
            // expose event
            case Expose :
                // wait untill all expose events will come
                //next 2 rows are commented as temporary fix -  allow to redraw button
                /*
               if (report.xexpose.count != 0) {
                    break;
               }
                 */
                dialog.wi.gc = XCreateGC(dialog.wi.display, dialog.wi.window, 0, NULL);
                XSetForeground(dialog.wi.display, dialog.wi.gc, BlackPixel (dialog.wi.display, 0));


                //TODO: rewrite with dialog expose
                //dialog.expose();

                text_box.expose();
                button1.expose();
                button2.expose();


                XFreeGC(dialog.wi.display, dialog.wi.gc);
                XFlush(dialog.wi.display);
                break;
            case ButtonPress:
            case ButtonRelease:
                temp_res1 = button1.is_button_clicked(&(report.xbutton));
                temp_res2 = button2.is_button_clicked(&(report.xbutton));
                if (temp_res1 == BTN_IS_CLICKED) {
                    std::cout << "Button 1 is clicked!!!" << std::endl;
                }
                else if (temp_res2 == BTN_IS_CLICKED) {
                    std::cout << "Button 2 is clicked!!!" << std::endl;
                }
                break;
            case KeyPress :
                // in case of press of any key, close connection and exit from the program
                XCloseDisplay(dialog.wi.display);
                _exit(0);
        }
    }

    return 0;
}