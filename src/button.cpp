#include "../include/button.h"

//TODO: implement init, draw and expose
void Button::init(int x, int y, const char *text) {};

void Button::draw() {};

void Button::expose() {};


// TODO: implement helper functions
int Button::is_point_inside(int px, int py) {};

int Button::button_mouseover_changed(const XMotionEvent *xmotion) {};

button_clicked_state_t Button::is_button_clicked(const XButtonEvent *xbutton) {};
