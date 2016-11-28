#include "stdafx.h"
#include "EllipseShape.h"


EllipseShape::EllipseShape()
{
	type = "Ellipse";
}


EllipseShape::~EllipseShape()
{
}

void EllipseShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, xs1, ys1, xs2, ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}