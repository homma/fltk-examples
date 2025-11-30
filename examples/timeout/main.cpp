#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <print>

auto update(void *data) -> void {
  std::println("ping.");
  Fl::repeat_timeout(1.0, update);
}

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

  Fl::add_timeout(1.0, update);

  win->end();
  win->show();

  return Fl::run();
}
