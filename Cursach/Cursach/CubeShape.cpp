#include "stdafx.h"
#include "CubeShape.h"


CubeShape::CubeShape()
{
	type = "Cube";
}


CubeShape::~CubeShape()
{
}

/*
* малює об'єкт shape
* xk - зміщення по х
* yk - зміщення по у
*/
void CubeShape::Show(HDC hdc, int xk, int yk)
{
	HPEN hPenOld, hPen;
	HBRUSH hBrush, hBrushOld;

	hPen = CreatePen(PS_SOLID, 1, penColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	hBrush = (HBRUSH)CreateSolidBrush(brColor);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	//прорахунок координат фігури
	int xs_1 = xs1 + xk,
		xs_2 = xs2 + xk,
		ys_1 = ys1 + yk,
		ys_2 = ys2 + yk,
		xs_B = xs_2 + (xs_1 - xs_2) / 3,
		ys_B = ys_2 - (ys_2 - ys_1) / 3,
		xs_D = xs_1 - (xs_1 - xs_2) / 3,
		ys_D = ys_1 + (ys_2 - ys_1) / 3,
		xs_A = xs_2 + (xs_1 - xs_2) / 3,
		ys_A = ys_1,
		xs_E = xs_2,
		ys_E = ys_D,
		xs_C = xs_D,
		ys_C = ys_2,
		xs_F = xs_1,
		ys_F = ys_B;
	
	//паралелограм верхний
	POINT pt_re[7];
	
	pt_re[0].x = xs_1;
	pt_re[1].x = xs_A;
	pt_re[2].x = xs_E;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys_1;
	pt_re[1].y = ys_A;
	pt_re[2].y = ys_E;
	pt_re[3].y = ys_D;


	Polygon(hdc, pt_re, 4);
	//паралелограм боковой
	pt_re[0].x = xs_1;
	pt_re[1].x = xs_F;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys_1;
	pt_re[1].y = ys_F;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	//прямоугольник
	pt_re[0].x = xs_E;
	pt_re[1].x = xs_2;
	pt_re[2].x = xs_C;
	pt_re[3].x = xs_D;
	pt_re[0].y = ys_E;
	pt_re[1].y = ys_2;
	pt_re[2].y = ys_C;
	pt_re[3].y = ys_D;
	Polygon(hdc, pt_re, 4);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

