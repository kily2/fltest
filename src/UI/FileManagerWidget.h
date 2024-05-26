#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H


#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include "../log.h"



class FileManagerWidget : public Fl_Group {
public:
FileManagerWidget();
~FileManagerWidget();



int handle(int e) override;
void draw() override;

private:


};







#endif //FILEMANAGERWIDGET_H
