#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Window.H>
#include <FL/gl.h>
#include <cmath>
#include <functional>
#include <numbers>

// Lt_Gl_Window
struct Lt_Gl_Window : public Fl_Gl_Window {
  Lt_Gl_Window(int x, int y, int w, int h, const char *label = 0);
  auto draw_callback(std::function<void(Lt_Gl_Window &)>) -> void;

protected:
  auto draw() -> void;

private:
  std::function<void(Lt_Gl_Window &)> draw_callback_fn = [](Lt_Gl_Window &win) {
  };
};

Lt_Gl_Window::Lt_Gl_Window(int x, int y, int w, int h, const char *label)
    : Fl_Gl_Window(x, y, w, h, label) {}

auto Lt_Gl_Window::draw_callback(std::function<void(Lt_Gl_Window &win)> draw_cb)
    -> void {
  this->draw_callback_fn = draw_cb;
}

auto Lt_Gl_Window::draw() -> void {
  this->draw_callback_fn(*this);
  Fl_Gl_Window::draw();
}

// Point
struct Point {
  float x;
  float y;
};

auto point_from_angle_distance(float degree, float distance) -> Point {
  auto deg2rad = std::numbers::pi / 180;

  auto theta = degree * deg2rad;
  float x = std::cos(theta) * distance;
  float y = std::sin(theta) * distance;

  return Point{x, y};
}

// draw callback function
auto draw(Lt_Gl_Window &win) -> void {
  win.make_current();
  if (not win.valid()) {
    win.valid(1);
  };

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);

  auto radius = 0.9;
  Point p;

  glColor3f(1.0, 0.0, 0.0);
  p = point_from_angle_distance(90, radius);
  glVertex2f(p.x, p.y);

  glColor3f(0.0, 1.0, 0.0);
  p = point_from_angle_distance(-30, radius);
  glVertex2f(p.x, p.y);

  glColor3f(0.0, 0.0, 1.0);
  p = point_from_angle_distance(-150, radius);
  glVertex2f(p.x, p.y);

  glEnd();

  glFlush();
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

  Lt_Gl_Window *gl_win;
  {
    auto width = 300;
    auto height = 300;
    auto left = (win->w() - width) / 2.0;
    auto top = (win->h() - height) / 2.0;
    gl_win = new Lt_Gl_Window(left, top, width, height);

    gl_win->color(FL_WHITE);
    gl_win->mode(FL_RGB);
    gl_win->draw_callback(draw);
    gl_win->end();
  }

  win->end();
  win->show();

  return Fl::run();
}
