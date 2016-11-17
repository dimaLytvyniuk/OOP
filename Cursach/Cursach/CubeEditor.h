#pragma once
#include "RectEditor.h"
class CubeEditor :
	public RectEditor
{
public:
	CubeEditor();
	~CubeEditor();
	void OnLBup(HWND hWnd);
	void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
	void PressButton(HWND hWnd);
	void OnMosuseMove(HWND hWnd);
};
