#pragma once

#include "ShapeEditor.h"
class EllipseEditor :
	public ShapeEditor
{
public:
	EllipseEditor(COLORREF, COLORREF);
	~EllipseEditor();
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	//void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

