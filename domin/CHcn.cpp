#include "pch.h"
#include "CHcn.h"

CHcn::CHcn()
{
	x1 = 0; 
	y1 = 0; 
	x2 = 0;
	y2 = 0;
}

CHcn::CHcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void CHcn::draw(CClientDC* pDC)
{

	pDC->Rectangle(x1, y1, x2, y2);
}

int CHcn::kiemtratronghinh(CPoint p)
{
	if (p.x > x1 && p.x < x2 && p.y > y1 && p.y <y2)
		return 1;
	else
		return 0;
}
