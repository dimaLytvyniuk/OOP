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
	Ellipse(hdc, xs1, ys1, xs2, ys2);
}