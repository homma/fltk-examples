#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image_Surface.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

auto fps = 60;

Fl_Box *canvas;
Fl_Image_Surface *surface;

auto pos_x = 0;

auto draw() -> void {
  Fl_Surface_Device::push_current(surface);

  // clear canvas
  fl_rectf(0, 0, canvas->w(), canvas->h(), FL_WHITE);

  fl_color(FL_BLUE);

  if (pos_x < canvas->w()) {
    pos_x += 3;
  } else {
    pos_x = 0;
  }
  fl_rect(pos_x, canvas->w() / 2.0, 30, 30);

  Fl_Surface_Device::pop_current();

  canvas->image(surface->image());
  canvas->redraw();
}

auto update(void *data) -> void {
  draw();
  Fl::repeat_timeout(1.0 / fps, update);
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

    win->color(54);
  }

  // canvas
  {
    auto width = 300;
    auto height = 300;
    auto left = (win->w() - width) / 2.0;
    auto top = (win->h() - height) / 2.0;
    canvas = new Fl_Box(left, top, width, height);

    canvas->box(FL_NO_BOX);
    canvas->color(FL_WHITE);

    surface = new Fl_Image_Surface(width, height);
  }

  win->end();
  win->show();

  Fl::add_timeout(1.0 / fps, update);

  return Fl::run();
}
