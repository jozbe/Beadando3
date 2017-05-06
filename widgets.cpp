#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

Widget::Widget(int x, int y, int meret)
{
    _x=x;
    _y=y;
    _meret = meret;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_meret && mouse_y>_y && mouse_y<_y+_meret;
}

void Widget::draw() const {
}

void Widget::handle(event ev) {
}





