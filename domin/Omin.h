#pragma once
#include "CHcn.h"
class Omin :
    public CHcn
{
public:
    int giatri;
    int mo;
    Omin();
    Omin(int mx1, int my1, int mx2, int my2);
    void draw(CClientDC* pdc);
    int bamomin(CClientDC* pdc, CPoint p);
};

