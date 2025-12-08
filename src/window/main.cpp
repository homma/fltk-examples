#include <FL/Fl.H>
#include <FL/Fl_Window.H>

auto main() -> int {

  auto width = 640;
  auto height = 480;
  auto left = (Fl::w() - width) / 2.0;
  auto top = (Fl::h() - height) / 2.0;
  auto title = "My FLTK Window";
  auto win = Fl_Window(left, top, width, height, title);

  win.color(FL_WHITE);

  win.end();
  win.show();

  return Fl::run();
}
