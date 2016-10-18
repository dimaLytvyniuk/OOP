#include "stdafx.h"
#include "RectShape.h"


RectShape::RectShape()
{
}


RectShape::~RectShape()
{
}

void RectShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255,255,0));	
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, xs1, ys1, xs2,ys2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}
