#pragma once
#include "Shape.h"
class CilinderShape :
	public Shape
{
public:
	CilinderShape();
	~CilinderShape();
	void Show(HDC,int xk, int yk);
};

