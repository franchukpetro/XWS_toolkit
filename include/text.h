#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H


#include "widget.h"

class Text : public MyWidget {
public:

    const char* text;

    void init(int x, int y, const char * text);

    void draw();

    void expose();


};


#endif //PROJECT_WINDOW_H
