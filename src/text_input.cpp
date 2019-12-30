#include "../include/text_input.h"


/*
int main()
{
    Display *display;
    Window window;
    XEvent event;
    int s;
    GC gc;
    // open connection with the server
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
    s = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1,
                                 BlackPixel(display, s), WhitePixel(display, s));
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask | ExposureMask );
    XMapWindow(display, window);
    KeySym symLS;
    vector< char*> typeInWord;
    vector<char> arr;
    while (true)
    {
        char * buff = (char *)malloc(sizeof(char)*8);

        XNextEvent(display, &event);
        switch ( event.type ) {

            case  KeyPress:
                printf( "KeyPress: %s\n", XKeysymToString(XLookupKeysym(&event.xkey, 0)) );
                XLookupString(&event.xkey, buff, sizeof(buff), &symLS, 0);
                typeInWord.emplace_back(buff);
                gc = XCreateGC ( display, window, 0 , NULL );
                for (size_t i = 0; i < typeInWord.size(); ++i){
                    XDrawString ( display, window, gc, 20 + i*10,50,
                                  typeInWord[i], strlen(typeInWord[i]) );
                }
                XFreeGC ( display, gc );
                if ( XKeysymToString(XLookupKeysym(&event.xkey, 0)) == "Escape" )
                    exit(0);
            case KeyRelease:
                printf( "KeyRelease: %x\n", event.xkey.keycode );
                break;
        }
    }

    return 0;
}

*/
void TextInput::init_text_input(MyWindow window, int in_x, int in_y){
    in_window = window;
    x = in_x;
    y = in_y;

    std::vector<char*> v;
    input = v;
}

void TextInput::draw_text_input(){
    XSetForeground(in_window.display, in_window.gc, BlackPixel(in_window.display, DefaultScreen(in_window.display)));
    XSetBackground(in_window.display, in_window.gc, WhitePixel(in_window.display, DefaultScreen(in_window.display)));
    XDrawRectangle(in_window.display, in_window.window, in_window.gc, x, y, 50, 10);
}


void TextInput::handler(){
    XEvent event;
    KeySym symLS;
    while (true)
    {
        char * buff = (char *)malloc(sizeof(char)*8);

        XNextEvent(in_window.display, &event);
        switch ( event.type ) {

            case  KeyPress:
                printf( "KeyPress: %s\n", XKeysymToString(XLookupKeysym(&event.xkey, 0)) );
                XLookupString(&event.xkey, buff, sizeof(buff), &symLS, 0);
                input.emplace_back(buff);
                in_window.gc = XCreateGC (in_window.display, in_window.window, 0 , NULL );
                for (size_t i = 0; i < input.size(); ++i){
                    XDrawString ( in_window.display, in_window.window, in_window.gc, x + i*10,y,
                                  input[i], strlen(input[i]) );
                }
                XFreeGC ( in_window.display, in_window.gc );
                if ( XKeysymToString(XLookupKeysym(&event.xkey, 0)) == "Escape" )
                    exit(0);
            case KeyRelease:
                printf( "KeyRelease: %x\n", event.xkey.keycode );
                break;
        }
    }
}

