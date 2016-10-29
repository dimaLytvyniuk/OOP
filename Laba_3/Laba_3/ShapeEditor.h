#pragma once
#if !defined(SHAPEDITOR_H)
#define SHAPEDITOR_H

#define MY_SHAPE_ARRAY_SIZE 106

#include "Editor.h"
#include "EllipseShape.h"
#include "LineShape.h"
#include "PointShape.h"
#include "RectShape.h"

class ShapeEditor : 
	public Editor
{
protected:
	//int xstart, ystart, xend, yend;
	static int curr_length;
	static Shape **pcshape;
	POINT pt_old;
	POINT pt_start;
public:
	ShapeEditor(void);
    void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};
#endif !defined(SHAPEDITOR_H)
