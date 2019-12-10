#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include "./include/text_box.h"


int main(){

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        _exit(1);
    }

    TextBox(display,"Example", "Hello");

}