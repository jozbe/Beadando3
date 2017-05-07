#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;
const int XX=380;
const int YY=380;
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
        if (ev.keycode>='1' && ev.keycode<='9' && focus>-1)
        {
            //SORVIZSGALAT
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
            //OSZLOP VIZSGALAT
            int j=focus%9;
            int oszlop=80;
            while(j-1<oszlop && tf==false)
            {
                if(j!=focus)
                    tf=widgets[j]->egyezes(ev.keycode);
                j+=9;
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
    int fg=0;
    ifstream be;
    be.open("easy.txt");
    int beolvas;
    int szin;
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
            Sudoku * b1 = new Sudoku(j*40+viz,i*40+fg,40,beolvas,szin);
            w.push_back(b1);
        }

    }
    event_loop(w);
    return 0;
}
