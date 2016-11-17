#pragma once
#include "LineShape.h"
#include "EllipseShape.h"
class LineOOShape :
	public LineShape, public EllipseShape
{
public:
	LineOOShape();
	~LineOOShape();
	void Show(HDC hdc);

};

