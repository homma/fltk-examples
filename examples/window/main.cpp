#include <FL/Fl.H>
#include <FL/Fl_Window.H>

auto centralize(Fl_Window &win) -> void {
  auto window_width = win.w();
  auto window_height = win.h();

  auto screen_width = Fl::w();
  auto screen_height = Fl::h();

  auto top = (screen_height - window_height) / 2.0;
  auto left = (screen_width - window_width) / 2.0;

  win.position(left, top);
}

auto main() -> int {

  auto width = 640;
  auto height = 480;
  auto title = "My FLTK Window";
  auto win = Fl_Window(width, height, title);

  win.color(FL_WHITE);

  win.end();
  win.show();
  centralize(win);

  return Fl::run();
}
