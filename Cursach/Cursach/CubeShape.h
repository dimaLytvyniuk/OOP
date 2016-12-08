#pragma once
#include "Shape.h"

class CubeShape :
	public Shape
{
public:
	CubeShape();
	~CubeShape();
	void Show(HDC, int xk, int yk);
};

