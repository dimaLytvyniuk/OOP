#pragma once
#include "LineShape.h"
class PuncktLineShape :
	public Shape
{
public:
	PuncktLineShape();
	~PuncktLineShape();
	void Show(HDC);
};

