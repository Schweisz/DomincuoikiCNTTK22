#pragma once
class CHcn
{
public:
	int x1, y1, x2, y2;
	CHcn();
	CHcn(int mx1, int my1, int mx2, int my2);
	void draw(CClientDC* pDC);
	int kiemtratronghinh(CPoint p);
};

