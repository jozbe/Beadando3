#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include "feltvizsg.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;
const int XX=380;
const int YY=380;
void event_loop(vector<Sudoku*>& widgets)
{
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
        if (ev.keycode>='1' && ev.keycode<='9' && focus>-1 && widgets[focus]->get__szin()!=0)
            feltvizsg(focus,widgets,ev,tovabb);
        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();

        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }


    }

}


int main()
{

    gin.timer(20);
    gout.open(XX,YY);
    vector<Sudoku*> w;
    ifstream be;
    be.open("easy.txt");
    int beolvas;
    int szin;
    int fg=0;
    for(int i=0; i<9; i++)
    {
        int viz=0;
        if((i)%3==0)
            fg+=5;
        for(int j=0; j<9; j++)
        {
            if((j)%3==0)
                viz+=5;
            be>>beolvas;
            if (beolvas==0)
                szin=1;
            else szin=0;
            Sudoku * b1 = new Sudoku(j*40+viz,i*40+fg,40,beolvas+48,szin);
            w.push_back(b1);
        }
    }
    be.close();
    event_loop(w);
    return 0;
}
