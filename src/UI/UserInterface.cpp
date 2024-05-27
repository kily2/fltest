
#include "UserInterface.h"
#include "../Audio/AudioEngine.h"


MainWindow::MainWindow(int W, int H, const char *L)
: Fl_Window(W,H,L), 
audioManager(new AudioManager())
{
	fileManager = new FileManagerWidget(10,10,100,100);

	end();	
}


MainWindow::~MainWindow() {
	delete audioManager;
	delete fileManager;
}



int MainWindow::handle(int e) {
	//...
	return Fl_Window::handle(e);
}



void MainWindow::draw() {
	Fl_Window::draw();
	//...
}



void MainWindow::playButtonCallback(	Fl_Widget *widget,
										void *data	) {

	MainWindow *window = static_cast<MainWindow*>(data);
	window->audioManager->play();
}




