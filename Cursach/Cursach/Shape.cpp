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
	/*
	char buffer[10],
		buffer_1[255];
	buffer[0] = '\0';
	buffer_1[0] = '\0';
	strcat_s(buffer_1,100, type);
	_itoa_s(xs1, buffer, 10, 10);
	strcat_s(buffer_1, 255, "\t");
	strcat_s(buffer_1, 255, buffer);
	_itoa_s(ys1, buffer, 10, 10);
	strcat_s(buffer_1, 255, "\t");
	strcat_s(buffer_1, 255, buffer);
	_itoa_s(xs2, buffer, 10, 10);
	strcat_s(buffer_1, 255, "\t");
	strcat_s(buffer_1, 255, buffer);
	_itoa_s(ys2, buffer, 10, 10);
	strcat_s(buffer_1, 255, "\t");
	strcat_s(buffer_1, 255, buffer);
	(*str) = buffer_1;
	*/
	std::string value = "";
	value = type + "\t" + std::to_string(xs1) + "\t" + std::to_string(ys1) + "\t" + std::to_string(xs2) + "\t" + std::to_string(ys2);
	return value;
}