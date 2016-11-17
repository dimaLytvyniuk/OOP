#include "stdafx.h"
#include "PuncktLineShape.h"


PuncktLineShape::PuncktLineShape()
{
}


PuncktLineShape::~PuncktLineShape()
{
}

void PuncktLineShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	LineShape::Show(hdc);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}