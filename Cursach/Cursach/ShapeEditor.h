#pragma once
#if !defined(SHAPEDITOR_H)
#define SHAPEDITOR_H

#define MY_SHAPE_ARRAY_SIZE 107

#include "Editor.h"
#include "EllipseShape.h"
#include "LineShape.h"
#include "RectShape.h"
#include "ToolBar.h"
#include "CubeShape.h"
#include "PuncktLineShape.h"
#include "RombShape.h"
#include "CilinderShape.h"

class ShapeEditor : 
	public Editor
{
protected:
	//int xstart, ystart, xend, yend;
	static int curr_length;
	static Shape *pcshape[MY_SHAPE_ARRAY_SIZE];
	POINT pt_old;
	POINT pt_start;
	char* name = "data_types.txt";
public:
	ShapeEditor(void);
    void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMosuseMove(HWND);
	void OnPaint(HWND);
	void PrintInFile(char *,int x1,int y1,int x2,int y2);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
	virtual void PressButton(HWND) = 0;
};
#endif !defined(SHAPEDITOR_H)
