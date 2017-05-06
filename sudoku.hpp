#ifndef SUDOKU_HPP_INCLUDED
#define SUDOKU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "string"

using namespace std;

class ExampleCheckBox : public Widget {
private:
    int _szam, _szin;
public:
    ExampleCheckBox(int x, int y, int meret,int szam,int szin);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    bool egyezes(int akt);
    void set__szin(int k);

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
