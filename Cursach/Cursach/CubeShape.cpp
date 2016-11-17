#include "stdafx.h"
#include "CubeShape.h"


CubeShape::CubeShape()
{
}


CubeShape::~CubeShape()
{
}

void CubeShape::Show(HDC hdc)
{
	if (xs1 < xs2)
	{
		int prom = xs2;
		xs2 = xs1;
		xs1 = prom;
		prom = ys2;
		ys2 = ys1;
		ys1 = prom;
	}

	int xs_1 = xs1,
		xs_2 = xs2,
		ys_1 = ys1,
		ys_2 = ys2,
		xs_B = xs2 + (xs1 - xs2) / 3,
		ys_B = ys2 - (ys2 - ys1) / 3,
		xs_D = xs1 - (xs1 - xs2) / 3,
		ys_D = ys1 + (ys2 - ys1) / 3,
		xs_A = xs2 + (xs1 - xs2) / 3,
		ys_A = ys1,
		xs_E = xs2,
		ys_E = ys_D,
		xs_C = xs_D,
		ys_C = ys2,
		xs_F = xs1,
		ys_F = ys_B;
		
	/*
	Set(xs_B, ys_B, xs_1, ys_1);
	RectShape::Show_1(hdc);
	Set(xs_D, ys_D, xs_2, ys_2);
	RectShape::Show_1(hdc);
	Set(xs_2, ys_2, xs_B, ys_B);
	LineShape::Show(hdc);
	Set(xs_2, ys_D, xs_B, ys_1);
	LineShape::Show(hdc);
	Set(xs_D, ys_2, xs_1, ys_B);
	LineShape::Show(hdc);

	Set(xs_D, ys_D, xs_1, ys_1);
	LineShape::Show(hdc);
	*/
	POINT pt_re[4];
	pt_re[0].x = xs1;
	pt_re[1].x = xs_A;
	pt_re[2].x = xs_E;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys1;
	pt_re[1].y = ys_A;
	pt_re[2].y = ys_E;
	pt_re[3].y = ys_D;

	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Polygon(hdc, pt_re, 4);

	pt_re[0].x = xs1;
	pt_re[1].x = xs_F;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys1;
	pt_re[1].y = ys_F;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	pt_re[0].x = xs_E;
	pt_re[1].x = xs2;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys_E;
	pt_re[1].y = ys2;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

