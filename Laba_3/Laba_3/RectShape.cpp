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
	Rectangle(hdc, xs1, ys1, xs2,ys2);
}
