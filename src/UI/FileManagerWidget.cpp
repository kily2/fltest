
#include "FileManagerWidget.h"





FileManagerWidget::FileManagerWidget(int x, int y, int w, int h, const char* l)
: Fl_Group(x,y,w,h,l) {
	//...
	
	path = ".";
	files = get_files_from_directory(path);

	scroll = new Fl_Scroll(x,y,w,h);
	scroll->box(FL_UP_BOX);

	int yy=10;
	for (const auto& file : files) {
		Fl_Box *box = new Fl_Box(10,yy,scroll->w() - 20, 20, file.c_str());
		box->box(FL_FLAT_BOX);
		box->labelfont(FL_COURIER);
		box->labelsize(14);
		scroll->add(box);
		yy+=30;
	}


	scroll->end();

	end();
}





FileManagerWidget::~FileManagerWidget() {
	// ...
	delete scroll;
}





int FileManagerWidget::handle(int e) {
	//...
	return Fl_Group::handle(e);
}





void FileManagerWidget::draw() {
	//...
	Fl_Group::draw();	
}




std::vector<std::string> FileManagerWidget::get_files_from_directory(const std::string &path) {
	std::vector<std::string> files;
	DIR *dir = opendir(path.c_str());
	if (dir == nullptr) {
		LOG("Error: opendir");
		return files;
	}

	struct dirent *entry;
	while ((entry = readdir(dir))!=nullptr) {
		if (entry->d_type == DT_REG || entry->d_type == DT_DIR) {
			std::string file_name = entry->d_name;
			files.push_back(file_name);
		}
	}

	closedir(dir);
	return files;
}









