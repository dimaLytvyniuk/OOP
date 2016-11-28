#pragma once
#include "Shape.h"
class LineShape :
	virtual public Shape
{
	//BOOL WINAPI LineTo(HDC hdc, int x, int y);//рисование линии
	//BOOL WINAPI MoveToEx(HDC hdc, int x, int y, LPPOINT oldPoint);//устанавливает текущую позицию в точку с координатами (x,y) и передает в структуру POINT координаты предыдущей позиции
public:
	LineShape();
	~LineShape();
	void Show(HDC hdc);
};

