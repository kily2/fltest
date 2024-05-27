
#include "FileManagerWidget.h"





FileManagerWidget::FileManagerWidget(int x, int y, int w, int h, const char* l)
: Fl_Group(x,y,w,h,l) {
	//...
	scroll = new Fl_Scroll(x,y,w,h);

	background = Fl_Shared_Image::get("/home/kali2/Downloads/img123.jpg");

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

	if (background && background->data()) {
		int imageWidth = background->w();
		int imageHeight = background->h();

		// Calculate the position to draw the image (centered)
		int posX = (w() - imageWidth) / 2;
		int posY = (h() - imageHeight) / 2;

		const uchar* imageData = reinterpret_cast<const uchar*>(background->data()[0]);
		// Draw the image
		fl_draw_image(imageData, posX, posY, imageWidth, imageHeight);
	}
}














