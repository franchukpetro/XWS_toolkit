#ifndef PROJECT_TEXT_H
#define PROJECT_TEXT_H


#include "widget.h"
#include "window.h"
#include "MyDialog.h"


class Text : public MyWidget {
public:

    const char* text;

    void init(window_info wi, const char * in_text, int x_in, int y_in, unsigned int Width, unsigned int Height);

    void draw();

    void expose();
};


#endif //PROJECT_TEXT_H
