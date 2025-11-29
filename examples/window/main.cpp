#include <FL/Fl.H>
#include <FL/Fl_Window.H>

auto main() -> int {

  auto width = 640;
  auto height = 480;
  auto title = "My FLTK Window";
  auto win = Fl_Window(width, height, title);

  win.color(FL_WHITE);

  win.end();
  win.show();

  return Fl::run();
}
