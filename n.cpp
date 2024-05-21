
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



struct State {
	unsigned int iterations;
	bool x_turn;
};



void 
button_cb(Fl_Widget *w, void *data) {

	Fl_Button *btn = static_cast<Fl_Button*>(w);
	
	State *state = static_cast<State*>(data);
	
	if (state->iterations>=9) return;

	const char *label = btn->label();
	if (label[0]!='\0') return;

	if (state->x_turn) {
		
		btn->label("X");
	} else {
		btn->label("O");
	}
	state->x_turn = !state->x_turn;
	btn->redraw();
}



class CustomWindow :public Fl_Window {
private:
	//std::vector<std::pair<int,int>> rectangles;
	std::vector<Fl_Button*> buttons;
	State state;

public:
	CustomWindow(int W, int H, const char *L = 0) : Fl_Window(W,H,L) {
		for (unsigned i=0,j=0; i<9; i++) {	
			if (i!=0&&i%3==0) j++;
			buttons.push_back(new Fl_Button((i%3)*20,j*20,20,20,""));
			buttons.back()->callback(button_cb,&state);
		}

		state.iterations=0;
		state.x_turn=true;
	}



	int handle(int e) override {
		switch (e) {
			case FL_PUSH:
				if (Fl::event_button() == FL_LEFT_MOUSE) {
				
				}
			default:
				return Fl_Window::handle(e);	
		}
	}



	void draw() override {
		Fl_Window::draw();

		/*
		fl_color(FL_RED);
		for (const auto& rect : rectangles) {
			fl_rectf(rect.first - 5, rect.second -5,10,10);
		}
		*/
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



