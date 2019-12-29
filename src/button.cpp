#include "../include/button.h"


// load text font
static XFontStruct *get_default_button_font(Display *display) {
    return XLoadQueryFont(display, "fixed");
}

void draw_button(button_t *b, int fg, int bg) {

    XClearArea(b->dpy, b->win, b->x, b->y, b->width, b->height, False);

    // change color of the button if mouse is over the button
    if (b->mouseover) {
        XFillRectangle(b->dpy, b->win, b->gc, b->clicked + b->x, b->clicked + b->y,
                       b->width, b->height);
        XSetForeground(b->dpy, b->gc, bg);
        XSetBackground(b->dpy, b->gc, fg);
    } else {
        XSetForeground(b->dpy, b->gc, fg);
        XSetBackground(b->dpy, b->gc, bg);
        XDrawRectangle(b->dpy, b->win, b->gc, b->x, b->y, b->width, b->height);
    }

    // text coordinates relatively to button size
    int textx, texty;
    textx = b->x + 15;
    texty = b->y + b->height - 3;

    // draw text inside button
    XDrawString(b->dpy, b->win, b->gc, b->clicked + textx, b->clicked + texty,
                b->text, strlen(b->text));

    XSetForeground(b->dpy, b->gc, fg);
    XSetBackground(b->dpy, b->gc, bg);
}

void init_button(button_t *b, const char in_text[], Display *in_dpy, Window in_win, int in_x, int in_y) {
    b->dpy = in_dpy;
    b->win = in_win;

    b->font = get_default_button_font(b->dpy);
    b->gc = XCreateGC(b->dpy, b->win, 0, NULL);
    XSetFont(b->dpy, b->gc, b->font->fid);

    b->text = in_text;

    int height = 0, direction = 0, ascent = 0, descent = 0;
    XCharStruct overall;
    XTextExtents(b->font, b->text, strlen(b->text), &direction, &ascent, &descent, &overall);

    // Compute the shape of the button_t
    b->width = overall.width + 30;
    b->height = ascent + descent + 5;
    b->x = in_x;
    b->y = in_y;

    b->mouseover = 0;
    b->clicked = 0;
}

void free_button(button_t *b) {
    XFreeFont(b->dpy, b->font);
    XFreeGC(b->dpy, b->gc);
}

// checks if mosuse cursor is inside of the button
static int is_point_inside(button_t *b, int px, int py) {
    return px >= b->x && px <= (b->x + (int) b->width - 1) &&
           py >= b->y && py <= (b->y + (int) b->height - 1);
}

// checks whether mouseover state was changed
int button_mouseover_changed(button_t *b, const XMotionEvent *xmotion) {
    int res = 0;

    if (is_point_inside(b, xmotion->x, xmotion->y)) {
        if (!b->mouseover)
            res = 1;
        b->mouseover = 1;
    } else {
        if (b->mouseover)
            res = 1;
        b->mouseover = 0;
        b->clicked = 0;
    }
    return res;
}

// checks whether button was clicked and returns appropriate value
button_clicked_state_t is_button_clicked(button_t *b, const XButtonEvent *xbutton) {
    if (xbutton->button != Button1)
        return BTN_IGNORE_CLICK;

    if (b->mouseover) {
        b->clicked = xbutton->type == ButtonPress ? 1 : 0;

        if (!b->clicked) {
            return BTN_IS_CLICKED;
        }
        return BTN_OTHER1;
    } else {
        b->clicked = 0;
        return BTN_OTHER2;
    }
}


button_t add_button(const char *in_text, window_info wi, int in_x, int in_y) {

    int blackColor = BlackPixel(wi.display, DefaultScreen(wi.display));
    int whiteColor = WhitePixel(wi.display, DefaultScreen(wi.display));

    XSelectInput(wi.display, wi.window,
                 ExposureMask | KeyPressMask | KeyReleaseMask | KeymapStateMask | StructureNotifyMask |
                 PointerMotionMask | ButtonPressMask | ButtonReleaseMask);

    XFontStruct *font = XLoadQueryFont(wi.display, "fixed");
    XSetFont(wi.display, wi.gc, font->fid);

    button_t button;

    init_button(&button, in_text, wi.display, wi.window, in_x, in_y);
    draw_button(&button, blackColor, whiteColor);

    return button;

}


void handler(window_info wi, button_t button) {


    int blackColor = BlackPixel(wi.display, DefaultScreen(wi.display));
    int whiteColor = WhitePixel(wi.display, DefaultScreen(wi.display));
    Atom wm_delete_window = XInternAtom(wi.display, "WM_DELETE_WINDOW", False);

    int do_exit = 0;
    XEvent event;
    int temp_res;

    while (1) {

        XNextEvent(wi.display, &event);

        if (event.type == MotionNotify) {
            if (button_mouseover_changed(&button, &event.xmotion)) {
                event.type = Expose;
            }
        }

        switch (event.type) {
            case Expose: {
                draw_button(&button, blackColor, whiteColor);
                XFlush(wi.display);
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

                temp_res = is_button_clicked(&button, &(event.xbutton));
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
    free_button(&button);

    XDestroyWindow(wi.display, wi.window);
    //XFreeFont(wi.display, font);
    XCloseDisplay(wi.display);


}

