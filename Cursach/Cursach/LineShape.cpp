#include "stdafx.h"
#include "LineShape.h"


LineShape::LineShape()
{
	type = "Line";
}


LineShape::~LineShape()
{
}

void LineShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc,xs1 ,ys1 , NULL);
	LineTo(hdc, xs2, ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}