#pragma once
#include "LineShape.h"
#include "RectShape.h"

class CubeShape :
	public LineShape,public RectShape
{
public:
	CubeShape();
	~CubeShape();
	void Show(HDC);
};

