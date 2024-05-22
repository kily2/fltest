#ifndef MAIN_H
#define MAIN_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>


class MainWindow : public Fl_Window {
public:
	MainWindow(int W, int H, const char *L=0);



	int handle(int e) override;
	void draw() override;
};






#endif //MAIN_H

