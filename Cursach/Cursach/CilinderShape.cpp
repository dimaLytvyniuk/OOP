#include "stdafx.h"
#include "CilinderShape.h"


CilinderShape::CilinderShape()
{
	type = "Cilinder";
}


CilinderShape::~CilinderShape()
{
}

void CilinderShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	int xs_1 = xs1 + xk,
		xs_2 = xs2 + xk,
		ys_1 = ys1 + yk,
		ys_2 = ys2 + yk,
		xs_A = xs_2,
		xs_B = xs_1,
		ys_A = ys_1 + (ys_2 - ys_1) / 6,
		ys_B = ys_2 - (ys_2 - ys_1) / 6,
		xs_C = xs_1,
		xs_D = xs_2,
		ys_C = ys_1 + (ys_2 - ys_1) / 12,
		ys_D = ys_2 - (ys_2 - ys_1) / 12,
		xs_E = xs_B,
		ys_E = ys_D,
		koef = -2;
	Ellipse(hdc, xs_B, ys_B, xs_2, ys_2);//нижний еллипс
	Rectangle(hdc, xs_C, ys_C, xs_D, ys_D);
	Ellipse(hdc, xs_1, ys_1, xs_A, ys_A);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

	hPen = CreatePen(PS_SOLID, 2, brColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	if (xs_1 > xs_2)
		koef = 2;

	MoveToEx(hdc, xs_E + koef / (-2), ys_E, NULL);
	LineTo(hdc, xs_D + koef, ys_D);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}