#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Browser.H>
#include "../log.h"



class FileManagerWidget : public Fl_Group {
public:
FileManagerWidget(Fl_Window *w);
~FileManagerWidget();



int handle(int e) override;
void draw() override;



private:
Fl_Window *window;
Fl_Scroll *scroll;
Fl_Browser *browser;



};







#endif //FILEMANAGERWIDGET_H
