#pragma once
#include "LineShape.h"
class PuncktLineShape :
	public LineShape
{
public:
	PuncktLineShape();
	~PuncktLineShape();
	void Show(HDC);
};

