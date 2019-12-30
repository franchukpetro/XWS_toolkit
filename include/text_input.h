#ifndef XWS_TOOLKIT_TEXT_INPUT_H
#define XWS_TOOLKIT_TEXT_INPUT_H

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "window.h"


class TextInput{
public:
    MyWindow in_window;
    std::vector<char*> input;
    int x;
    int y;

    void init_text_input(MyWindow window, int in_x, int in_y);
    void draw_text_input();
    void handler();
};


#endif //XWS_TOOLKIT_TEXT_INPUT_H
