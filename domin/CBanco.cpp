#include "pch.h"
#include "CBanco.h"

CBanco::CBanco()
{
	int i = 0, j = 0;
	 dk = 1;
	 thang = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			ds[i][j] = Omin(XDAU + DAI * j, YDAU + DAI * i, XDAU + DAI * (j+1), YDAU + DAI * (i+1));
		}
	}
	int dem = 0;
	while (dem < SOLUONG)
	{
		i = ((double)rand() / RAND_MAX) * (19) + 0;
		j = ((double)rand() / RAND_MAX) * (19) + 0;

		if (ds[i][j].giatri != -1)
		{
			ds[i][j].giatri = -1;
			//ds[i][j].mo = 1;//hien bay
			dem++;
		}
	}
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri != -1)
				ds[i][j].giatri = demominxungquanh(i, j);
			
		}
	}
}

void CBanco::draw(CClientDC* pdc)
{
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			ds[i][j].draw(pdc);
		}
	}
	CString strsomin;
	strsomin.Format(_T("SO MIN: 80"));
	CRect rect1(50, 0, (XDAU*XDAU)/4 , 40);
	pdc->DrawText(strsomin, rect1, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

int CBanco::demominxungquanh(int mi, int mj)
{
	int dem = 0;
	int inho = mi - 1;
	int ilon = mi + 1;
	int jnho = mj - 1;
	int jlon = mj + 1;
	if (inho < 0)
		inho = 0;
	if (jnho < 0)
		jnho = 0;
	if (ilon > COT-1)
		ilon = COT - 1;
	if (jlon > COT - 1)
		jlon = COT - 1;
	int i = 0, j = 0;
	for (i = inho; i <= ilon; i++)
	{
		for (j = jnho; j <= jlon; j++)
		{
			if (ds[i][j].giatri == -1)
				dem++;
		}
	}
	return dem;
}

int CBanco::ktthang()
{
	int i = 0, j = 0;
	int dem = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].mo == 0)
				dem++;
		}
	}
	if (dem == SOLUONG && thang == 0)
	{
		thang = 1;
		return 1;
	}
	else
	{ 
		return 0;
		}
}

void CBanco::Thongbaoketqua(CClientDC* pdc)
{
	CString strthang, strthua;
	strthang.Format(_T("Nguoi choi thang"));
	strthua.Format(_T("Nguoi choi  Thua"));
	if (thang == 1)
		pdc->TextOutW(50, 20, strthang);
	if (thang == -1)
		pdc->TextOutW(50, 20, strthua);


}

void CBanco::bambanco(CClientDC* pdc, CPoint p)
{
	if (dk == 0)
		return;
	int i = 0,j = 0;
	for (int i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].bamomin(pdc,p) == 1)//tuc la o min o vi tri i j dc bam
			{
				if (ds[i][j].giatri == -1)
				{
					thang = -1;
					dk = 0;
					Thongbaoketqua(pdc);
				}
				if (ds[i][j].giatri == 0)
				{
					//mo cac o co gia tri bang 0 lan can
					m8oxungquanh(i, j, pdc);
					//m4oxungquanh(i, j, pdc);
				}
				//kiem tra thang
				if (ktthang() == 1)
				{
					Thongbaoketqua(pdc);
				}
			}
		}
	}
}

void CBanco::m8oxungquanh(int mi, int mj, CClientDC* pdc)
{
	int inho = mi - 1;
	int ilon = mi + 1;
	int jnho = mj - 1;
	int jlon = mj + 1;
	if (inho < 0)
		inho = 0;
	if (jnho < 0)
		jnho = 0;
	if (ilon > COT - 1)
		ilon = COT - 1;
	if (jlon > COT - 1)
		jlon = COT - 1;
	int i = 0, j = 0;
	if (ds[mi][mj].giatri == 0)
	{
		for (i = inho; i <= ilon; i++)
		{
			for (j = jnho; j <= jlon; j++)
			{
				if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
				{
					ds[i][j].mo = 1;
					ds[i][j].draw(pdc);
					//goi lai phuong thuc mo 8 xunng quanh cho o vua moi mo
					m8oxungquanh(i, j, pdc);
				}
			}
		}
	}
}

void CBanco::m4oxungquanh(int mi, int mj, CClientDC* pdc)
{
	int i = 0, j = 0;
	//truong hop 1
	i = mi - 1;
	j = mj;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		ds[i][j].draw(pdc);	
		m4oxungquanh(i, j, pdc);
	}
	//truong hop 2
	i = mi + 1;
	j = mj;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		ds[i][j].draw(pdc);
		m4oxungquanh(i, j, pdc);
	}
	//truong hop 3
	i = mi ;
	j = mj-1;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		ds[i][j].draw(pdc);
		m4oxungquanh(i, j, pdc);
	}
	//truong hop 4
	i = mi;
	j = mj +1;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		ds[i][j].draw(pdc);
		m4oxungquanh(i, j, pdc);
	}
}
