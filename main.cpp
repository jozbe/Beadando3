#include "graphics.hpp"
#include "widgets.hpp"
#include "sudoku.hpp"
#include "feltvizsg.hpp"
#include "evhandler.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

int main()
{
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
    EventHandler a;
    a.event_loop(w);
    return 0;
}
