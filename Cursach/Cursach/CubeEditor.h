#pragma once
#include "ShapeEditor.h"
class CubeEditor :
	public ShapeEditor
{
public:
	CubeEditor();
	~CubeEditor();
	void OnLBup(HWND hWnd);
	void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
	void PressButton(HWND hWnd);
	void OnMosuseMove(HWND hWnd);
};