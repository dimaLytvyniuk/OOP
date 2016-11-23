#include "stdafx.h"
#include "CilinderShape.h"


CilinderShape::CilinderShape()
{
	type = "Cilinder";
}


CilinderShape::~CilinderShape()
{
}

void CilinderShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;

	int xs_A = xs2,
		xs_B = xs1,
		ys_A = ys1 + (ys2 - ys1) / 6,
		ys_B = ys2 - (ys2 - ys1) / 6,
		xs_C = xs1,
		xs_D = xs2,
		ys_C = ys1 + (ys2 - ys1) / 12,
		ys_D = ys2 - (ys2 - ys1) / 12,
		xs_E = xs_B,
		ys_E = ys_D,
		koef = -2;
	Ellipse(hdc, xs_B, ys_B, xs2, ys2);//нижний еллипс
	Rectangle(hdc, xs_C, ys_C, xs_D, ys_D);
	Ellipse(hdc, xs1, ys1, xs_A, ys_A);

	hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	if (xs1 > xs2)
		koef = 2;

	MoveToEx(hdc, xs_E + koef / (-2), ys_E, NULL);
	LineTo(hdc, xs_D + koef, ys_D);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}