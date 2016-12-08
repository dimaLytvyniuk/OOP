#pragma once
#include "ShapeEditor.h"
class RombEditor :
	public ShapeEditor
{
public:
	RombEditor(COLORREF, COLORREF);
	~RombEditor();
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
};

