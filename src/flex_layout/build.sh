#!/bin/sh -x

FLTK_INC="-I$(brew --prefix fltk)/include"
FLTK_LIB="-L$(brew --prefix fltk)/lib"
FLTK_OPT="${FLTK_INC} ${FLTK_LIB} -lfltk"

c++ main.cpp -o fltk_flex_layout -std=c++2c ${FLTK_OPT}
