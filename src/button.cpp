#include "../include/button.h"


// load text font
static XFontStruct *get_default_button_font(Display *display) {
    return XLoadQueryFont(display, "fixed");
}

void Button::draw_button(int fg, int bg) {

    XClearArea(in_window.display, in_window.window, x, y, width, height, False);

    // change color of the button if mouse is over the button
    if (mouseover) {
        XFillRectangle(in_window.display, in_window.window, gc, clicked + x, clicked + y, width, height);
        XSetForeground(in_window.display, gc, bg);
        XSetBackground(in_window.display, gc, fg);
    } else {
        XSetForeground(in_window.display, gc, fg);
        XSetBackground(in_window.display, gc, bg);
        XDrawRectangle(in_window.display, in_window.window, gc, x, y, width, height);
    }

    // text coordinates relatively to button size
    int textx, texty;
    textx = x + 15;
    texty = y + height - 3;

    // draw text inside button
    XDrawString(in_window.display, in_window.window, gc, clicked + textx, clicked + texty,
                text, strlen(text));

    XSetForeground(in_window.display, gc, fg);
    XSetBackground(in_window.display, gc, bg);
}

void Button::init_button(MyWindow window, const char in_text[], int in_x, int in_y) {

    font = get_default_button_font(window.display);
    gc = XCreateGC(window.display, window.window, 0, NULL);
    XSetFont(window.display, window.gc, font->fid);

    text = in_text;

    int height = 0, direction = 0, ascent = 0, descent = 0;
    XCharStruct overall;
    XTextExtents(font, text, strlen(text), &direction, &ascent, &descent, &overall);

    // Compute the shape of the button_t
    width = overall.width + 30;
    height = ascent + descent + 5;
    x = in_x;
    y = in_y;

    mouseover = 0;
    clicked = 0;
}

void Button::free_button() {
    XFreeFont(in_window.display, font);
    XFreeGC(in_window.display, gc);
}

// checks if mosuse cursor is inside of the button
int Button::is_point_inside(int px, int py) {
    return px >= x && px <= (x + (int) width - 1) &&
           py >= y && py <= (y + (int) height - 1);
}

// checks whether mouseover state was changed
int Button::button_mouseover_changed(const XMotionEvent *xmotion) {
    int res = 0;

    if (is_point_inside(xmotion->x, xmotion->y)) {
        if (!mouseover)
            res = 1;
        mouseover = 1;
    } else {
        if (mouseover)
            res = 1;
        mouseover = 0;
        clicked = 0;
    }
    return res;
}

// checks whether button was clicked and returns appropriate value
button_clicked_state_t Button::is_button_clicked(const XButtonEvent *xbutton) {
    if (xbutton->button != Button1)
        return BTN_IGNORE_CLICK;

    if (mouseover) {
        clicked = xbutton->type == ButtonPress ? 1 : 0;

        if (!clicked) {
            return BTN_IS_CLICKED;
        }
        return BTN_OTHER1;
    } else {
        clicked = 0;
        return BTN_OTHER2;
    }
}


void Button::add_button() {
    int blackColor = BlackPixel(in_window.display, DefaultScreen(in_window.display));
    int whiteColor = WhitePixel(in_window.display, DefaultScreen(in_window.display));

    XSelectInput(in_window.display, in_window.window,
                 ExposureMask | KeyPressMask | KeyReleaseMask | KeymapStateMask | StructureNotifyMask |
                 PointerMotionMask | ButtonPressMask | ButtonReleaseMask);

    XFontStruct *font = XLoadQueryFont(in_window.display, "fixed");
    XSetFont(in_window.display, gc, font->fid);

    draw_button(blackColor, whiteColor);
}


void Button::handler() {

    int blackColor = BlackPixel(in_window.display, DefaultScreen(in_window.display));
    int whiteColor = WhitePixel(in_window.display, DefaultScreen(in_window.display));
    Atom wm_delete_window = XInternAtom(in_window.display, "WM_DELETE_WINDOW", False);

    int do_exit = 0;
    XEvent event;
    int temp_res;

    while (1) {

        XNextEvent(in_window.display, &event);

        if (event.type == MotionNotify) {
            if (button_mouseover_changed(&event.xmotion)) {
                event.type = Expose;
            }
        }

        switch (event.type) {
            case Expose: {
                draw_button(blackColor, whiteColor);
                XFlush(in_window.display);
            }
                break;
            case ConfigureNotify: {
                XConfigureEvent xce = event.xconfigure;
                if (xce.width != WIDTH ||
                    xce.height != HEIGHT) {
                    //WIDTH = xce.width;
                    //HEIGHT = xce.height;
                }
            }
                break;
            case ButtonPress:
            case ButtonRelease:

                temp_res = is_button_clicked(&(event.xbutton));
                if (temp_res == BTN_IS_CLICKED) {
                    std::cout << "Button is clicked!!!" << std::endl;
                }
                break;
            case ClientMessage: {
                if ((Atom) event.xclient.data.l[0] == wm_delete_window) {
                    do_exit = 1;
                }
            }
                break;
        }
        if (do_exit)
            break; // Event loop
    }
    free_button();

    XDestroyWindow(in_window.display, in_window.window);
    //XFreeFont(in_window.display, font);
    XCloseDisplay(in_window.display);


}

