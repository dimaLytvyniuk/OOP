#include "stdafx.h"
#include "RombShape.h"


RombShape::RombShape()
{
	type = "Romb\0";
}


RombShape::~RombShape()
{
}

void RombShape::Show(HDC hdc)
{
	POINT pt_re[4];
	int xs_A = xs1 - (xs2 - xs1),
		ys_A = ys2,
		xs_B = xs1,
		ys_B = ys1 + ((ys2 - ys1)* 2);

	pt_re[0].x = xs_A;
	pt_re[1].x = xs_B;
	pt_re[2].x = xs2;
	pt_re[3].x = xs1;
	pt_re[0].y = ys_A;
	pt_re[1].y = ys_B;
	pt_re[2].y = ys2;
	pt_re[3].y = ys1;
	Polygon(hdc, pt_re, 4);
}