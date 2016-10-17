#pragma once

#if !defined(SHAPE_H)
#define SHAPE_H
class Shape
{
	protected:
		long xs1, ys1, xs2, ys2;
	public:
		void Set(long x1,long y1, long x2, long y2);
		virtual void Show(HDC) = 0;
};
#endif !defined(SHAPE_H)
