#pragma once
#include "LineEditor.h"
class LineOOEditor :
	public LineEditor
{
public:
	LineOOEditor();
	~LineOOEditor();
	void OnLBup(HWND hWnd);
	void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
	void PressButton(HWND hWnd);
	void OnMosuseMove(HWND hWnd);
};

