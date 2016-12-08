#pragma once
#include "ShapeEditor.h"

class LineEditor :
	public ShapeEditor
{
public:
	LineEditor(COLORREF, COLORREF);
	~LineEditor();
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

