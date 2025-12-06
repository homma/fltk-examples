#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <print>

struct Push_Button : public Fl_Button {
  Push_Button(int x, int y, int w, int h, const char *label = 0);
  auto handle(int event) -> int;
};

Push_Button::Push_Button(int x, int y, int w, int h, const char *label)
    : Fl_Button(x, y, w, h, label) {}

auto Push_Button::handle(int event) -> int {
  switch (event) {
  case FL_PUSH:
    value(1);
    do_callback(FL_REASON_SELECTED);
    return 1;
  case FL_RELEASE:
    value(0);
    do_callback(FL_REASON_RELEASED);
    return 1;
  default:
    return Fl_Button::handle(event);
  }
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

  win->color(54);

  Fl_Button *button;
  {
    auto width = 300;
    auto height = 40;
    auto left = (win->w() - width) / 2.0;
    auto top = win->h() / 2.0 - height;
    auto text = "プッシュボタン";
    button = new Push_Button(left, top, width, height, text);
  }

  button->type(FL_NORMAL_BUTTON);
  button->color(FL_WHITE);

  button->callback([](Fl_Widget *w) {
    auto reason = (int)Fl::callback_reason();
    std::println("Push Button Event with Reason: {}.", reason);
  });

  win->end();
  win->show();

  return Fl::run();
}
