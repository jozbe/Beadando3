#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include "feltvizsg.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include "evhandler.hpp"


const int XX=380;
const int YY=380;


void EventHandler::event_loop(vector<Sudoku*>& widgets)
{
    gin.timer(20);
    gout.open(XX,YY);
    bool tovabb=true;
    event ev;
    int focus = -1;
    while(gin >> ev  && ev.keycode!= key_escape)
    {
        if (ev.type == ev_mouse && ev.button==btn_left && tovabb==true)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }

        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();

        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
         if (ev.keycode>='1' && ev.keycode<='9' && focus>-1 && widgets[focus]->get__szin()!=0)
            feltvizsg(focus,widgets,ev,tovabb);
    }
}

