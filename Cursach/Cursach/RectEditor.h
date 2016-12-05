#pragma once
#include "ShapeEditor.h"
class RectEditor :
	public ShapeEditor
{
public:
	RectEditor(COLORREF, COLORREF);
	~RectEditor();
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

