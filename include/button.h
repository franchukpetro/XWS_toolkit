#ifndef XWS_TOOLKIT_BUTTON_H
#define XWS_TOOLKIT_BUTTON_H


#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include <string.h>
#include "window.h"

struct button_t {

    int x, y;
    unsigned int width, height;
    int mouseover;
    int clicked;
    const char* text;
    XFontStruct* font;
    GC gc;
    Display *dpy;
    Window win;

};


void init_button(button_t *b, const char in_text[], Display *in_dpy, Window in_win, int in_x, int in_y);
void draw_button(button_t *b, int fg, int bg);
void free_button(button_t *b);
int button_mouseover_changed(button_t *b, const XMotionEvent* xmotion);

button_t add_button(const char *in_text, window_info wi, int in_x, int in_y);
void handler(window_info wi, button_t button);

typedef enum {BTN_IGNORE_CLICK = 0, BTN_IS_CLICKED = 1, BTN_OTHER1 = 2, BTN_OTHER2 = 3 } button_clicked_state_t;
button_clicked_state_t is_button_clicked(button_t *b, const XButtonEvent* xbutton );




#endif //XWS_TOOLKIT_BUTTON_H
