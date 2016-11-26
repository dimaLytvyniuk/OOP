#pragma once
#include "LineEditor.h"
class PuncktLineEditor :
	public LineEditor
{
public:
	PuncktLineEditor(COLORREF, COLORREF);
	~PuncktLineEditor();
	void OnLBup(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void PressButton(HWND);
};

