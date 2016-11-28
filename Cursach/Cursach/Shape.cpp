#include "stdafx.h"
#include "Shape.h"

void Shape::Set(long x1, long y1, long x2, long y2,COLORREF brushColor,COLORREF peColor)
{
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
	brColor = brushColor;
	penColor = peColor;
}

std::string Shape::RetData()
{
	std::string value = "";
	value = type + "\t" + std::to_string(xs1) + "\t" + std::to_string(ys1) + "\t" + std::to_string(xs2) + "\t" + std::to_string(ys2) + "\t" + std::to_string(brColor) + "\t" + std::to_string(penColor);
	return value;
}