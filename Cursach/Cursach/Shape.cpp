#include "stdafx.h"
#include "Shape.h"

/*
	* ініціалізу об'єкт shape
	* x1 - х координата початкової точки
	* у1 - у координата початкової точки
	* x2 - х координата кінцевої точки
	* у2 - у координата кінцевої точки
	* brushColor - колір заливки
	* peColor - колір контуру
	* xk - х зміщення 
	* yk - у зміщення
	*/
void Shape::Set(long x1, long y1, long x2, long y2,COLORREF brushColor,COLORREF peColor, int xk, int yk)
{
	xs1 = x1 - xk;
	ys1 = y1 - yk;
	xs2 = x2 - xk;
	ys2 = y2 - yk;
	brColor = brushColor;
	penColor = peColor;
}

//повертає дані про об'єкт shape
std::string Shape::RetData()
{
	std::string value = "";
	value = type + "\t" + std::to_string(xs1) + "\t" + std::to_string(ys1) + "\t" + std::to_string(xs2) + "\t" + std::to_string(ys2) + "\t" + std::to_string(brColor) + "\t" + std::to_string(penColor);
	return value;
}