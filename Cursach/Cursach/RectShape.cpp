#include "stdafx.h"
#include "RectShape.h"


RectShape::RectShape()
{
	type = "Rect";
}


RectShape::~RectShape()
{
}

/*
* ����� ��'��� shape
* xk - ������� �� �
* yk - ������� �� �
*/
void RectShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc,xs1 + xk, ys1 + yk, xs2 + xk, ys2+ yk);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}