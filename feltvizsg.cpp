#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

void feltvizsg(int focus,vector<Sudoku*>& widgets,event ev)
{
    {
        int j;
         bool tf= false;
       /* //SORVIZSGALAT
        int sor=(focus)/9;
        int k=sor*9;
        sor=k+9;

        while(k<sor && tf==false)
        {
            if(k!=focus)
                tf=widgets[k]->egyezes(ev.keycode);
            k++;
        }
        //OSZLOP VIZSGALAT
        j=focus%9;
        int oszlop=80;
        while(j-1<oszlop && tf==false)
        {
            if(j!=focus)
                tf=widgets[j]->egyezes(ev.keycode);
            j+=9;
        }*/

        //NEGYZET

        j=focus%9;
        int kezdo;
        if(focus<27)
        {
            if(j<3)    kezdo=0;
            else if (j<6) kezdo=3;
            else kezdo=6;
        }
        else if(focus<54)
        {
            if(j<3)    kezdo=27;
            else if (j<6) kezdo=30;
            else kezdo=33;
        }
        else if(focus<80)
        {
            if(j<3)    kezdo=54;
            else if (j<6) kezdo=57;
            else kezdo=60;
        }
        int w=0;
        while(w<3 && tf==false)

        {
            int q=0;
            while ( q<3 && tf==false)
            {
                if(kezdo+q!=focus)
                                       tf=widgets[kezdo+q]->egyezes(ev.keycode);
                if(tf==true)

                cout<<q<<" "<<w<<" "<<kezdo+q<<' ';
                q++;
            }
            cout<<endl;
            w++;
            int szorzo=w*9;
            kezdo+=szorzo;
        }
        if(tf==true)

                widgets[focus]->set__szin(2);

        else
            widgets[focus]->set__szin(1);
    }
}
