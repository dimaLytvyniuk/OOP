#pragma once

#if !defined(SHAPE_H)
#define SHAPE_H
#include <string>

class Shape
{
	protected:
		long xs1, ys1, xs2, ys2;//координати фігури
		std::string type;//тип фігури
		COLORREF brColor,//колір заливки
			penColor;//колір контуру
	public:
		void Set(long x1,long y1, long x2, long y2,COLORREF,COLORREF,int xk,int yk);//ініціалізу об'єкт shape
		virtual void Show(HDC,int xk, int yk) = 0; //малює об'єкт shape
		std::string RetData();//повертає дані про об'єкт shape
};
#endif !defined(SHAPE_H)
