#pragma once
#include "ShapeEditor.h"
class CilinderEditor :
	public ShapeEditor
{
public:
	CilinderEditor();
	~CilinderEditor();
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

