#pragma once
#include "ShapeEditor.h"
class RectEditor :
	public ShapeEditor
{
public:
	RectEditor();
	~RectEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	//void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};

