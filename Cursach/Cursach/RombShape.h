#pragma once
#include "Shape.h"
class RombShape :
	public Shape
{
public:
	RombShape();
	~RombShape();
	void Show(HDC, int xk, int yk);
};

