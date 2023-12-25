#include "pch.h"
#include "Omin.h"

Omin::Omin()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	giatri = 0;
	mo = 0;
}

Omin::Omin(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
	giatri = 0;
	mo = 0;
}

void Omin::draw(CClientDC* pdc)
{
	if (mo == 0)
	{ 
		CBrush* Brush2 = new CBrush(RGB(211, 211, 211));
		CBrush* oldbrush;
		oldbrush= pdc-> SelectObject(Brush2);
		pdc->Rectangle(x1, y1, x2, y2);
		pdc->SelectObject(oldbrush);
	}
	else 
	{
		pdc->Rectangle(x1, y1, x2, y2);
		CString strmin, strso;
		if (giatri >0)
		{
			strso.Format(_T("%d"), giatri);
			pdc->TextOutW((x1 + x2) / 2 - 5, (y1 + y2) / 2 -10, strso);
		}
		else
		{
			if (giatri == -1)
			{
				strmin.Format(_T("#"));
				pdc->TextOutW((x1 + x2) / 2 - 5, (y1 + y2) / 2 - 10, strmin);
			}
		}
	}
}

int Omin::bamomin(CClientDC* pdc, CPoint p)
{
	if (kiemtratronghinh(p) == 1&& mo==0)
	{
		mo = 1;
		draw(pdc);
		return 1;
	}
	else
		return 0;
}
