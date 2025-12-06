#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <print>

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

  Fl_Button *button;
  {
    auto left = 100;
    auto top = 40;
    auto width = 300;
    auto height = 40;
    auto text = "ボタン";
    button = new Fl_Button(left, top, width, height, text);
  }

  button->type(FL_NORMAL_BUTTON);
  button->color(FL_WHITE);

  button->callback([](Fl_Widget *w) {
    auto reason = (int)Fl::callback_reason();
    auto event = Fl::event();
    auto button = Fl::event_button();
    auto click = Fl::event_is_click();
    std::println(
        "Repeat Button Event reason: {} event: {} button: {} clicked: {}.",
        reason, event, button, click);
  });

  win->end();
  win->show();

  return Fl::run();
}
