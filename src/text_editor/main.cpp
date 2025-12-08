#include <FL/Fl.H>
#include <FL/Fl_Text_Editor.H>
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

  auto text_buffer = new Fl_Text_Buffer();

  Fl_Text_Editor *editor;
  {
    auto left = 100;
    auto top = 40;
    auto width = 460;
    auto height = 400;
    auto text = "テキスト入力";
    editor = new Fl_Text_Editor(left, top, width, height, text);
  }

  editor->buffer(text_buffer);

  win->end();
  win->show();

  return Fl::run();
}
