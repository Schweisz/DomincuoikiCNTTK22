#pragma once
#include"Omin.h"
#define COT 20
#define DAI 30
#define XDAU 50
#define YDAU 50
#define SOLUONG 80
class CBanco
{
public:
	Omin ds[COT][COT];
	int dk;
	int thang;
	CBanco();
	void draw(CClientDC* pdc);
	int demominxungquanh(int mi, int mj);
	int ktthang();
	void Thongbaoketqua(CClientDC *pdc);
	void bambanco(CClientDC* pdc, CPoint p);
	void m8oxungquanh(int mi, int mj, CClientDC* pdc);
	void m4oxungquanh(int mi, int mj, CClientDC* pdc);
};

