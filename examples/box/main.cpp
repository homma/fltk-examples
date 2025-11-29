#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

auto main() -> int {

  Fl_Window *win;
  {
    auto width = 640;
    auto height = 480;
    auto title = "My FLTK Window";
    win = new Fl_Window(width, height, title);
  }

  win->color(FL_WHITE);

  Fl_Box *box;
  {
    auto left = 40;
    auto top = 40;
    auto width = 300;
    auto height = 100;
    auto text = "こんにちは FLTK!";
    box = new Fl_Box(left, top, width, height, text);
  }

  box->box(FL_BORDER_BOX);
  box->color(FL_WHITE);
  box->labelsize(32);

  win->end();
  win->show();

  return Fl::run();
}
