#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Window.H>
#include <FL/gl.h>
#include <cmath>
#include <numbers>

int fps = 30;

auto draw(Fl_Gl_Window &win) -> void {
  win.mode(FL_RGB);
  win.make_current();

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);

  auto radius = 0.9;
  auto deg2rad = std::numbers::pi / 180;

  {
    glColor3f(1.0, 0.0, 0.0);
    auto theta = 90 * deg2rad;
    auto x = std::cos(theta) * radius;
    auto y = std::sin(theta) * radius;
    glVertex2f(x, y);
  }

  {
    glColor3f(0.0, 1.0, 0.0);
    auto theta = -30 * deg2rad;
    auto x = std::cos(theta) * radius;
    auto y = std::sin(theta) * radius;
    glVertex2f(x, y);
  }

  {
    glColor3f(0.0, 0.0, 1.0);
    auto theta = -150 * deg2rad;
    auto x = std::cos(theta) * radius;
    auto y = std::sin(theta) * radius;
    glVertex2f(x, y);
  }

  glEnd();

  glFlush();
}

auto update(void *gl_win) -> void {
  Fl_Gl_Window &win = *(Fl_Gl_Window *)gl_win;
  draw(win);
  Fl::repeat_timeout(1.0 / fps, update, gl_win);
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

  Fl_Gl_Window *gl_win;
  {
    auto width = 300;
    auto height = 300;
    auto left = (win->w() - width) / 2.0;
    auto top = (win->h() - height) / 2.0;
    gl_win = new Fl_Gl_Window(left, top, width, height);

    gl_win->color(FL_WHITE);
    gl_win->end();
  }

  win->end();
  win->show();

  Fl::add_timeout(1.0 / fps, update, gl_win);

  return Fl::run();
}
