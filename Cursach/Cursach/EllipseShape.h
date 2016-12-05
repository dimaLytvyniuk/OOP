#pragma once
#include "Shape.h"
class EllipseShape :
	virtual public Shape
{
public:
	EllipseShape();
	~EllipseShape();
	void Show(HDC, int xk, int yk);
};

