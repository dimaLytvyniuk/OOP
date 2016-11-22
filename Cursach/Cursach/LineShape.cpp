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
	MoveToEx(hdc,xs1 ,ys1 , NULL);
	LineTo(hdc, xs2, ys2);
}