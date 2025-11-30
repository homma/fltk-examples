#include <FL/Fl.H>
#include <FL/Fl_Window.H>

auto main() -> int {

  Fl::background(255, 255, 255);

  Fl_Window *win;
  {
    auto width = 640;
    auto height = 480;
    auto left = (Fl::w() - width) / 2.0;
    auto top = (Fl::h() - height) / 2.0;
    auto title = "My FLTK Window";
    win = new Fl_Window(left, top, width, height, title);
  }

  Fl_Window *sub_win;
  {
    auto width = 320;
    auto height = 240;
    auto left = 0;
    auto top = 0;
    auto title = "My Sub Window";
    sub_win = new Fl_Window(left, top, width, height, title);
  }

  sub_win->color(FL_BLUE);
  sub_win->end();

  win->end();
  win->show();

  return Fl::run();
}
