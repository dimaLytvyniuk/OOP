#pragma once

#if !defined(SHAPE_H)
#define SHAPE_H
#include <string>

class Shape
{
	protected:
		long xs1, ys1, xs2, ys2;//���������� ������
		std::string type;//��� ������
		COLORREF brColor,//���� �������
			penColor;//���� �������
	public:
		void Set(long x1,long y1, long x2, long y2,COLORREF,COLORREF,int xk,int yk);//�������� ��'��� shape
		virtual void Show(HDC,int xk, int yk) = 0; //����� ��'��� shape
		std::string RetData();//������� ��� ��� ��'��� shape
};
#endif !defined(SHAPE_H)
