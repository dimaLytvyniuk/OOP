#include "stdafx.h"
#include "CubeShape.h"


CubeShape::CubeShape()
{
	type = "Cube";
}


CubeShape::~CubeShape()
{
}

void CubeShape::Show(HDC hdc)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	int xs_B = xs2 + (xs1 - xs2) / 3,
		ys_B = ys2 - (ys2 - ys1) / 3,
		xs_D = xs1 - (xs1 - xs2) / 3,
		ys_D = ys1 + (ys2 - ys1) / 3,
		xs_A = xs2 + (xs1 - xs2) / 3,
		ys_A = ys1,
		xs_E = xs2,
		ys_E = ys_D,
		xs_C = xs_D,
		ys_C = ys2,
		xs_F = xs1,
		ys_F = ys_B;
	
	//паралелограм верхний
	POINT pt_re[7];
	
	pt_re[0].x = xs1;
	pt_re[1].x = xs_A;
	pt_re[2].x = xs_E;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys1;
	pt_re[1].y = ys_A;
	pt_re[2].y = ys_E;
	pt_re[3].y = ys_D;


	Polygon(hdc, pt_re, 4);
	//паралелограм боковой
	pt_re[0].x = xs1;
	pt_re[1].x = xs_F;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys1;
	pt_re[1].y = ys_F;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	//прямоугольник
	pt_re[0].x = xs_E;
	pt_re[1].x = xs2;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys_E;
	pt_re[1].y = ys2;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

