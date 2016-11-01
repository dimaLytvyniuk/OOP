#include "stdafx.h"
#include "EllipseShape.h"


EllipseShape::EllipseShape()
{
}


EllipseShape::~EllipseShape()
{
}

void EllipseShape::Show(HDC hdc)
{
	Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);
}