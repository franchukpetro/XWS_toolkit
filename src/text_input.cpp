#include "../include/text_input.h"
#include "../include/MyDialog.h"

//TODO: implement init, draw, expose
void TextInput::init(window_info wi, int window_x, int window_y, int window_width, int window_height) {
    display = wi.display;
    window = wi.window;
    gc = wi.gc;
    width = window_width;
    height = window_height;
    x = window_x;
    y = window_y;
//    XSelectInput(display, window, ExposureMask |  KeyPressMask);
};

void TextInput::draw() {
//    gc = XCreateGC ( display, window, 0 , NULL );
    XDrawRectangle(display, window, gc, x, y, width, height);
//    XFreeGC ( display, gc );
};

void TextInput::expose() {
    draw();
};

void TextInput::key_pressed(XEvent* event){
    char * buff = (char *)malloc(sizeof(char)*8);
    XLookupString(&event->xkey, buff, sizeof(buff), &symLS, 0);
    typeInWord.emplace_back(buff);
//    gc = XCreateGC ( display, window, 0 , NULL );
    for (size_t i = 0; i < typeInWord.size(); ++i){
        XDrawString ( display, window, gc, x + 10 + i*8, (( y + height/2)) ,
                      typeInWord[i], strlen(typeInWord[i]) );
        if (10 + i*8 >= width-30){
            break;
        }

    }
//    XFreeGC ( display, gc );
//                if ( (XLookupKeysym(&event.xkey, 0)) == XK_BackSpace )
//                    printf( "KeyRelease: %x\n", event.xkey.keycode );
//                    typeInWord.pop_back();

};


//TODO: implement helper functions if there are such
