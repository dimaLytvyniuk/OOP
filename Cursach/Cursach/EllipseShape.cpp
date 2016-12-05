#include "stdafx.h"
#include "EllipseShape.h"


EllipseShape::EllipseShape()
{
	type = "Ellipse";
}


EllipseShape::~EllipseShape()
{
}

/*
* малює об'єкт shape
* xk - зміщення по х
* yk - зміщення по у
*/
void EllipseShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, xs1 + xk, ys1 + yk, xs2 + xk, ys2 + yk);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}