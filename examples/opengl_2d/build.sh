#!/bin/sh -x

FLTK_INC="-I$(brew --prefix fltk)/include"
FLTK_LIB="-L$(brew --prefix fltk)/lib"
FLTK_OPT="${FLTK_INC} ${FLTK_LIB} -lfltk"
OPENGL_OPT="-lfltk_gl -framework OpenGL"

c++ main.cpp -o fltk_opengl_2d -std=c++2c ${FLTK_OPT} ${OPENGL_OPT}
