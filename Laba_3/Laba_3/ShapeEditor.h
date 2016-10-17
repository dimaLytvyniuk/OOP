#pragma once
#if !defined(SHAPEDITOR_H)
#define SHAPEDITOR_H

#include "Editor.h"
class ShapeEditor :
	public Editor
{
public:
	ShapeEditor();
    void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};
#endif !defined(SHAPEDITOR_H)
