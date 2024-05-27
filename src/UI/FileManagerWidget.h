#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Scroll.H>
#include "../log.h"
#include <filesystem>
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_draw.H>





class FileManagerWidget : public Fl_Group {
public:
FileManagerWidget(int x, int y, int w, int h, const char* l = 0);
~FileManagerWidget();



int handle(int e) override;
void draw() override;



private:
Fl_Scroll *scroll;
Fl_Shared_Image *background;


};







#endif //FILEMANAGERWIDGET_H
