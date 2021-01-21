/*
 * <FLTK> Drawing Things in FLTK
 *
 * < Author > ChoiWheatley
 * < Doc Link > https://www.fltk.org/doc-1.3/drawing.html
 *
 * < ToDo >
 * <> Mac Visual Studio ��ġ�Ͽ� �ش� �������丮 ����ͼ� fltk ���� �������� Ȯ���ϱ�
 *
 *
 * < History >
 * 2021. 01. 21.
 *	-- �����쿡�� fltk �絵�� �ϱ�. Visual Studio���� ����� ���ư���.
 *	-- ��ǥ : [ Drawing Fast Shapes ] & [ Drawing Complex Shapes ] & [ Drawing Text ] & [ Fonts ]
 * 
 * < Compile Options via Visual Studio >
 * reference from : https://alf-p-steinbach.github.io/Install-FLTK-for-use-with-Visual-C-/
 * 
 */

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Window.H>

class MyWindow : public Fl_Window {
public:
	MyWindow(int w, int h, const char* label = 0) : Fl_Window{ w, h, label } {}
	~MyWindow() {}
	virtual void draw() override;
private:
};

struct Point {
	double x;
	double y;
};

Point points[] = {
	{100, 200},
	{250, 200},
	{300, 300},
	{250, 400},
	{100, 400},
	{50 , 300},
};

Point gaps[] = {
	{175, 250},
	{195, 320},
	{165, 320},
};

int main(int argc, char** argv)
{
	MyWindow* win = new MyWindow(640, 480, "My Window");
	// ToDo : Write down your own code below
	win->show();
	return Fl::run();
}

void MyWindow::draw()
{
	Fl_Window::draw();
	// Draw Complex Shapes

	
}




