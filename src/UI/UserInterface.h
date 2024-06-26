#ifndef MAIN_H
#define MAIN_H



#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "../Audio/AudioEngine.h"
#include "FileManagerWidget.h"


class MainWindow : public Fl_Window {
public:
	MainWindow(int W, int H, const char *L=0);
	~MainWindow();


	int handle(int e) override;
	void draw() override;



private:
	FileManagerWidget *fileManager;
	Fl_Button *playButton;
	AudioManager *audioManager;


	
	static void playButtonCallback(Fl_Widget* widget, void *data);
};






#endif //MAIN_H

