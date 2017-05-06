#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "string"

using namespace std;

class Widget {
protected:
    int _x, _y, _meret;

public:
    Widget(int x, int y, int meret);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const;
    virtual void handle(genv::event ev);
};


#endif // WIDGETS_HPP_INCLUDED
