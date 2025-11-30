#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>

auto main() -> int {

  Fl_Window *win;
  {
    auto width = 640;
    auto height = 480;
    auto left = (Fl::w() - width) / 2.0;
    auto top = (Fl::h() - height) / 2.0;
    auto title = "My FLTK Window";
    win = new Fl_Window(left, top, width, height, title);
  }

  win->color(FL_WHITE);

  Fl_Input *input;
  {
    auto left = 100;
    auto top = 40;
    auto width = 300;
    auto height = 40;
    auto text = "入力";
    input = new Fl_Input(left, top, width, height, text);
  }

  win->end();
  win->show();

  return Fl::run();
}
