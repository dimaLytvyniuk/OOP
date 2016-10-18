#pragma once
#include "ShapeEditor.h"
class EllipseEditor :
	public ShapeEditor
{
public:
	EllipseEditor();
	~EllipseEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};

