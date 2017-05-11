#ifndef FELTVIZSG_HPP_INCLUDED
#define FELTVIZSG_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include "string"
#include <vector>

using namespace std;
using namespace genv;
 void feltvizsg(int focus,vector<Sudoku*>& widgets,event ev,bool& tovabb);

#endif // FELTVIZSG_HPP_INCLUDED
