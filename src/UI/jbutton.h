#ifndef JBUTTON_H
#define JBUTTON_H



#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>



class JButton : public Fl_Button {
public:
	JButton(int x,int y, int w, int h, const char *label=0);



	int handle(int event) override;
	void draw() override;



private:
	//...
};


#endif //JBUTTON_H
