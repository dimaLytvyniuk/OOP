#pragma once
#include "Shape.h"
class RectShape :
	public Shape
{
public:
	RectShape();
	~RectShape();
	void Show(HDC, int xk, int yk);
};

