#pragma once
#include "ShapeEditor.h"
class RectEditor :
	public ShapeEditor
{
public:
	RectEditor(COLORREF, COLORREF);
	~RectEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	//void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

