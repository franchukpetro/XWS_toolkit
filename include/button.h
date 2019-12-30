#ifndef XWS_TOOLKIT_BUTTON_H
#define XWS_TOOLKIT_BUTTON_H


#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include <string.h>
#include "window.h"

typedef enum {BTN_IGNORE_CLICK = 0, BTN_IS_CLICKED = 1, BTN_OTHER1 = 2, BTN_OTHER2 = 3 } button_clicked_state_t;



class Button{
public:
    MyWindow in_window;
    int x;
    int y;
    unsigned int width;
    unsigned int height;
    int mouseover;
    int clicked;
    const char* text;
    XFontStruct* font;
    GC gc;

    void init_button(MyWindow window, const char in_text[], int in_x, int in_y);
    void draw_button(int fg, int bg);
    void free_button();
    int is_point_inside(int px, int py);
    int button_mouseover_changed(const XMotionEvent* xmotion);
    button_clicked_state_t is_button_clicked(const XButtonEvent* xbutton );
    void add_button();
    void handler();

};


#endif //XWS_TOOLKIT_BUTTON_H
