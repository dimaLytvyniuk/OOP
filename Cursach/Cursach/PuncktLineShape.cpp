#include "stdafx.h"
#include "PuncktLineShape.h"


PuncktLineShape::PuncktLineShape()
{
	type = "PuncktLine";
}


PuncktLineShape::~PuncktLineShape()
{
}

void PuncktLineShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;

	hPen = CreatePen(PS_DOT, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}