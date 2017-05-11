#ifndef EVLOOP_HPP_INCLUDED
#define EVLOOP_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "string"
class EventHandler
{

public:
    void event_loop(vector<Sudoku*>& widgets);
};

#endif // EVLOOP_HPP_INCLUDED
