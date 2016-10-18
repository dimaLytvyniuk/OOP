#pragma once
#include "Shape.h"
class PointShape :
	public Shape
{
public:
	PointShape();
	~PointShape();
	//COLORREF WINAPI SetPixel(HDC hdc, int x, int y, COLORREF color);
	void Show(HDC);
};

