#include "stdafx.h"
#include "PuncktLineShape.h"


PuncktLineShape::PuncktLineShape()
{
	type = "PuncktLine";
}


PuncktLineShape::~PuncktLineShape()
{
}

void PuncktLineShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;

	hPen = CreatePen(PS_DOT, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, xs1 + xk, ys1 + yk, NULL);
	LineTo(hdc, xs2 + xk, ys2 + yk);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}