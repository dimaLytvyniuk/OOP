#include "stdafx.h"
#include "RectShape.h"


RectShape::RectShape()
{
	type = "Rect";
}


RectShape::~RectShape()
{
}

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

void RectShape::Show_1(HDC hdc)
{
	RECT rt;

	if (xs1 < xs2 && ys1 < ys2)
	{
		SetRect(&rt, xs1, ys1, xs2,ys2);
	}
	else if (xs1 > xs2 && ys1 < ys2)
	{
		SetRect(&rt, xs2, ys1, xs1, ys2);
	}
	else if (xs1 < xs2 && ys1 > ys2)
	{
		SetRect(&rt, xs1, ys2, xs2, ys1);
	}
	else
	{
		SetRect(&rt, xs2, ys2, xs1, ys1);
	}

	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	FrameRect(hdc, &rt, hBrush);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}
