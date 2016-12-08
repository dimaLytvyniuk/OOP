#pragma once
#include "ShapeEditor.h"
class CilinderEditor :
	public ShapeEditor
{
public:
	CilinderEditor(COLORREF,COLORREF);
	~CilinderEditor();
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

