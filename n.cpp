
#include <stdio.h>
#include <iostream>
#include <vector>
#include "log.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/names.h>
#include <FL/fl_draw.H>

#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>



class CustomWindow :public Fl_Window {
private:
	std::vector<std::pair<int,int>> rectangles;
public:
	CustomWindow(int W, int H, const char *L = 0) : Fl_Window(W,H,L) {}



	int handle(int e) override {
		switch (e) {
			case FL_PUSH:
				if (Fl::event_button() == FL_LEFT_MOUSE) {
					rectangles.push_back(std::make_pair(Fl::event_x(),Fl::event_y()));
					redraw();
				}
				return 1;
			default:
				return Fl_Window::handle(e);	
		}
	}



	void draw() override {
		Fl_Window::draw();

		fl_color(FL_RED);
		for (const auto& rect : rectangles) {
			fl_rectf(rect.first - 5, rect.second -5,10,10);
		}
	}
};



int
main(int argc, char **argv) {

	CustomWindow *window = new CustomWindow(400,300,"Button Test");



	window->end();
	window->show(argc,argv);

	return Fl::run();
	return 0;
}



