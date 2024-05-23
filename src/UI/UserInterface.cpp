
#include "UserInterface.h"
#include "../Audio/AudioEngine.h"


MainWindow::MainWindow(int W, int H, const char *L)
: Fl_Window(W,H,L), audioManager(new AudioManager()) {


	testData.current_size = static_cast<int>(SAMPLE_RATE/440.0);

	for (unsigned i=0; i<testData.current_size; ++i) {
		testData.sine[i] = 0.60*sin(2.0*M_PI*440.0*(double)i/SAMPLE_RATE); 
	}

	testData.phase=0;

	playButton = new Fl_Button(50,50,100,30,"Play Tone");
	playButton->callback(playButtonCallback,this);
	end();	
}


MainWindow::~MainWindow() {
	delete audioManager;
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
	window->audioManager->play(&window->testData);
}




