#include "stdafx.h"
#include "LineOOShape.h"
#include <math.h>

LineOOShape::LineOOShape()
{
}


LineOOShape::~LineOOShape()
{
}

void LineOOShape::Show(HDC hdc)
{
	LineShape::Show(hdc);

	int xs_2 = xs2,
		ys_2 = ys2,
		xs_1 = xs1,
		ys_1 = ys1;
	int r = sqrt(pow(xs2 - xs1, 2) + pow(ys2 - ys1, 2)) / 10;

	Set(xs1 - r, ys1 - r, xs1 + r, ys1 + r);
	EllipseShape::Show(hdc);

	Set(xs_2 - r, ys_2- r,xs_2 + r,ys_2 + r);
	EllipseShape::Show(hdc);

	Set(xs_1, ys_1, xs_2, ys_2);
}

