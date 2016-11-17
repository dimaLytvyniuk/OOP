#pragma once
#include "ShapeEditor.h"
class RombEditor :
	public ShapeEditor
{
public:
	RombEditor();
	~RombEditor();
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
};

