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
	fl_begin_line();
	// The reason why I couldn't draw any lines was not calling 
	// both fl_begin_line() and fl_end_line() functions.
	fl_color(FL_RED);
	fl_line_style(FL_DOT, 10);
	fl_line(1, 1, 100, 100);
	fl_line(5, 1, 105, 100);
	fl_line(10, 1, 110, 100);
	fl_line(30, 1, 130, 100);
	fl_line_style(0);
	fl_end_line();

	fl_color(FL_BLUE);
	// start and end drawing a complex filled polygon.
	// This polygon may be concave, may have holes in it, 
	// or may be several disconnected pieces.
	fl_begin_complex_polygon();
	for (const Point& i : points) {
		fl_vertex(i.x, i.y);
	}
	// Call fl_gap() to separate loops of the path.
	fl_gap();
	for (const Point& i : gaps) {
		fl_vertex(i.x, i.y);
	}
	fl_end_complex_polygon();
}




