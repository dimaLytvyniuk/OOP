#pragma once
#include "Shape.h"
class EllipseShape :
	public Shape
{
public:
	EllipseShape();
	~EllipseShape();
	BOOL WINAPI Ellipse(HDC hdc, int x1, int y1, int x2, int y2);
};

