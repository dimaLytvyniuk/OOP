#pragma once
#include "Shape.h"
class EllipseShape :
	public Shape
{
public:
	EllipseShape();
	~EllipseShape();
	void Show(HDC, int xk, int yk);
};

