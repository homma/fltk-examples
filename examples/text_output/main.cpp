#include <FL/Fl.H>
#include <FL/Fl_Output.H>
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

  Fl_Output *output;
  {
    auto left = 160;
    auto top = 40;
    auto width = 400;
    auto height = 40;
    auto text = "テキストラベル:";
    output = new Fl_Output(left, top, width, height, text);
  }

  output->value("文字列の表示");

  win->end();
  win->show();

  return Fl::run();
}
