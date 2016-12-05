#pragma once
#include "Shape.h"
class LineShape :
	virtual public Shape
{
public:
	LineShape();
	~LineShape();
	void Show(HDC hdc, int xk, int yk);
};

