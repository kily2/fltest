#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H

#include <dirent.h>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include "../log.h"
#include <filesystem>
#include <FL/fl_draw.H>





class FileManagerWidget : public Fl_Group {
public:
FileManagerWidget(int x, int y, int w, int h, const char* l = 0);
~FileManagerWidget();



int handle(int e) override;
void draw() override;



std::string getPath() const;
void setPath(std::string path);

private:
Fl_Scroll *scroll;
std::string path;
std::vector<std::string> files;


std::vector<std::string> get_files_from_directory(const std::string &path);

};







#endif //FILEMANAGERWIDGET_H
