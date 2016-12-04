#include "stdafx.h"
#include "Shape.h"

void Shape::Set(long x1, long y1, long x2, long y2,COLORREF brushColor,COLORREF peColor, int xk, int yk)
{
	xs1 = x1 - xk;
	ys1 = y1 - yk;
	xs2 = x2 - xk;
	ys2 = y2 - yk;
	brColor = brushColor;
	penColor = peColor;
}

std::string Shape::RetData()
{
	std::string value = "";
	value = type + "\t" + std::to_string(xs1) + "\t" + std::to_string(ys1) + "\t" + std::to_string(xs2) + "\t" + std::to_string(ys2) + "\t" + std::to_string(brColor) + "\t" + std::to_string(penColor);
	return value;
}