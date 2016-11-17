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
	//HBRUSH hBrush, hBrushOld;
	//hBrush = (HBRUSH)CreateSolidBrush(RGB(0,255,0));	
	//hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc,xs1, ys1, xs2, ys2);
	//SelectObject(hdc, hBrushOld);
	//DeleteObject(hBrush);
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
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	FrameRect(hdc, &rt, hBrush);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}
