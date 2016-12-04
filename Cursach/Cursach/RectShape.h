#pragma once
#include "Shape.h"
class RectShape :
	public virtual Shape
{
public:
	RectShape();
	~RectShape();
	//BOOL WINAPI Rectangle(HDC hdc, int x1, int y1, int x2, int y2);
	void Show(HDC, int xk, int yk);
	void Show_1(HDC);
};

