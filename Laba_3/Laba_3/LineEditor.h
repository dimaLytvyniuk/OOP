#pragma once
#include "ShapeEditor.h"
class LineEditor :
	public ShapeEditor
{
public:
	LineEditor();
	~LineEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};

