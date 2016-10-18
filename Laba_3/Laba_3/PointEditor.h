#pragma once
#include "ShapeEditor.h"

class PointEditor :
	public ShapeEditor
{
public:
	PointEditor();
	~PointEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};

