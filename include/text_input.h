#ifndef PROJECT_TEXT_INPUT_H
#define PROJECT_TEXT_INPUT_H


#include "widget.h"
#include "MyDialog.h"

class TextInput : public MyWidget {
public:
    int s;
    KeySym symLS;
    std::vector< char*> typeInWord;
    //TODO: if you need, also add 'width' and 'height' attributes for sizes of text input box
    const char * text;

    void init(window_info wi, int x, int y, int window_width, int window_height);

    void draw();

    void expose();
    //TODO: add any helper functions if needed
    void key_pressed(XEvent* event);

};


#endif //PROJECT_TEXT_INPUT_H
