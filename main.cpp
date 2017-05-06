#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;
const int XX=360;
const int YY=360;
void event_loop(vector<Sudoku*>& widgets)
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
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
        if (ev.keycode>='1' && ev.keycode<='9')
        {

            int sor=(focus)/9;
            int k=sor*9;
            sor=k+9;
            bool tf= false;
            while(k<sor && tf==false)
            {
                if(k!=focus)
                    tf=widgets[k]->egyezes(ev.keycode);

                k++;
            }
            k=focus%9;
            int oszlop=80;
            while(k-1<oszlop && tf==false)
            {
                if(k!=focus)
                    tf=widgets[k]->egyezes(ev.keycode);
                k+=9;
            }
            if(tf==true)
                widgets[focus]->set__szin(2);
            else
                widgets[focus]->set__szin(1);
        }
        gout << refresh;
    }

}


int main()
{

    gin.timer(20);
    gout.open(XX,YY);
    vector<Sudoku*> w;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            Sudoku * b1 = new Sudoku(j*40,i*40,40,0,1);
            w.push_back(b1);
        }
    event_loop(w);
    return 0;
}
