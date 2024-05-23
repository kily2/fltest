
#include <stdio.h>
#include <iostream>
#include <vector>
#include "src/log.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/names.h>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include "src/UI/UserInterface.h"



int
main(int argc, char **argv) {

	MainWindow *window = new MainWindow(400,300,"Test 12321");



	window->end();
	window->show(argc,argv);

	return Fl::run();
	return 0;
}



