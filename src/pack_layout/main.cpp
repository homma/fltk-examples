#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
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

  Fl_Pack *pack;
  {
    auto left = 100;
    auto top = 40;
    auto width = 100;
    auto height = 400;
    pack = new Fl_Pack(left, top, width, height);
  }

  int cell_height = 40;

  auto b0 = new Fl_Button(0, 0, 0, cell_height, "Button 0");
  b0->type(FL_NORMAL_BUTTON);
  b0->color(FL_WHITE);

  auto b1 = new Fl_Button(0, 0, 0, cell_height, "Button 1");
  b1->type(FL_NORMAL_BUTTON);
  b1->color(FL_WHITE);

  auto b2 = new Fl_Button(0, 0, 0, cell_height, "Button 2");
  b2->type(FL_NORMAL_BUTTON);
  b2->color(FL_WHITE);

  auto b3 = new Fl_Button(0, 0, 0, cell_height * 3, "Button 3");
  b3->type(FL_NORMAL_BUTTON);
  b3->color(FL_WHITE);

  pack->type(Fl_Pack::VERTICAL);
  pack->end();

  win->end();
  win->show();

  return Fl::run();
}
