#include "stdafx.h"
#include "CubeShape.h"


CubeShape::CubeShape()
{
}


CubeShape::~CubeShape()
{
}

void CubeShape::Show(HDC hdc)
{
	int xs_1 = xs1,
		xs_2 = xs2,
		ys_1 = ys1,
		ys_2 = ys2,
		xs_B = xs2 + (xs1 - xs2) / 3,
		ys_B = ys2 - (ys2 - ys1) / 3,
		xs_D = xs1 - (xs1 - xs2) / 3,
		ys_D = ys1 + (ys2 - ys1) / 3;

	Set(xs_B, ys_B, xs_1, ys_1);
	RectShape::Show_1(hdc);
	Set(xs_D, ys_D, xs_2, ys_2);
	RectShape::Show_1(hdc);
	Set(xs_2, ys_2, xs_B, ys_B);
	LineShape::Show(hdc);
	Set(xs_2, ys_D, xs_B, ys_1);
	LineShape::Show(hdc);
	Set(xs_D, ys_2, xs_1, ys_B);
	LineShape::Show(hdc);

	Set(xs_D, ys_D, xs_1, ys_1);
	LineShape::Show(hdc);
	Set(xs_1, ys_1, xs_2, ys_2);
}

