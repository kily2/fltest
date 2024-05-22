
#include "jbutton.h"
#include <FL/fl_draw.H>


JButton::JButton(int x, int y, int w, int h, const char *label)
: Fl_Button(x,y,w,h,label) {

	//...
}



int JButton::handle(int e) {
	//...
	return 1;
}



void JButton::draw() {
	//...
}
