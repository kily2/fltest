
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

#include "src/UI/FileManagerWidget.h"
#include "src/UI/testButton.h"



int
main(int argc, char **argv) {

	MainWindow *window = new MainWindow(400,300,"Test 12321");
	FileManagerWidget *filemanager = new FileManagerWidget(10,10,100,100);
	//TestButton *testbutton = new TestButton(10,10,100,100,"hello");	
	window->add(filemanager);

	window->end();
	window->show(argc,argv);

	return Fl::run();
	return 0;
}



