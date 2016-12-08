#pragma once
#include "ShapeEditor.h"
class CubeEditor :
	public ShapeEditor
{
public:
	CubeEditor(COLORREF,COLORREF);
	~CubeEditor();
	void OnLBup(HWND hWnd, int xk, int yk);
	void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
	void PressButton(HWND hWnd);
	void OnMosuseMove(HWND hWnd);
};
