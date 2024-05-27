#ifndef TESTBUTTON_H
#define TESTBUTTON_H


#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class TestButton : public Fl_Group {
public:
    TestButton(int x, int y, int w, int h, const char* label = nullptr)
        : Fl_Group(x, y, w, h) {
        button = new Fl_Button(x, y, w, h, label);
    	end();
	}

    ~TestButton() {
        delete button;
    }

	
	void draw() {
		Fl_Group::draw();
	}

	int handle(int e) {
		return Fl_Group::handle(e);
	}

private:
    Fl_Button* button;
};







#endif //TESTBUTTON_H
