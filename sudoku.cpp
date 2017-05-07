#include "sudoku.hpp"
#include "graphics.hpp"
#include "string"

using namespace genv;
using namespace std;
const int XX=360;
const int YY=360;
Sudoku::Sudoku(int x, int y, int meret,int szam,int szin)
    : Widget(x,y,meret)
{
    _szam=szam;
    _szin=szin;
}

void Sudoku::draw() const
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_meret,_meret);
    if(_szin==2) gout<<color(255,0,0);//piros ha hibas
    else if (_szin==1)        gout<< color(255,255,255);//feher ha atirhato
    else gout<< color(220,220,220);//szurke ha nem modosithato
    gout << move_to(_x+2, _y+2) << box(_meret-4, _meret-4);
    gout << color(0,0,0);
    gout << move_to(_x+15, _y+25) << text(_szam);
}

void Sudoku::handle(event ev)
{

    if (ev.type==ev_key && _meret<XX-16  && ev.keycode>0 && (ev.keycode>='1' && ev.keycode<='9') && _szin!=0)
    {
        _szam=ev.keycode;
    }
    if(ev.type==ev_key && ev.keycode==key_backspace && _szin!=0)
    {
        _szam=0;
        gout<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_meret-4,_meret-4);
        _szin=1;
    }

}

bool Sudoku::egyezes(int aktualis)
{
    if (_szam==aktualis)
        return true;
    else return false;
}

void Sudoku::set__szin(int k)
{
    _szin=k;
}
