#ifndef XWS_TOOLKIT_TEXT_BOX_H
#define XWS_TOOLKIT_TEXT_BOX_H

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




int TextBox(Display *display,const char *title, const char *text);


#endif //XWS_TOOLKIT_TEXT_BOX_H
