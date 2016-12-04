#include "stdafx.h"
#include "RombShape.h"


RombShape::RombShape()
{
	type = "Romb";
}


RombShape::~RombShape()
{
}

void RombShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	POINT pt_re[4];
	int xs_1 = xs1 + xk,
		xs_2 = xs2 + xk,
		ys_1 = ys1 + yk,
		ys_2 = ys2 + yk,
		xs_A = xs_1 - (xs_2 - xs_1),
		ys_A = ys_2,
		xs_B = xs_1,
		ys_B = ys_1 + ((ys_2 - ys_1)* 2);

	pt_re[0].x = xs_A;
	pt_re[1].x = xs_B;
	pt_re[2].x = xs_2;
	pt_re[3].x = xs_1;
	pt_re[0].y = ys_A;
	pt_re[1].y = ys_B;
	pt_re[2].y = ys_2;
	pt_re[3].y = ys_1;
	Polygon(hdc, pt_re, 4);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}