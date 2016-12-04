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
	COLORREF brColor,
		penColor;
public:
	ShapeEditor(COLORREF,COLORREF);
	ShapeEditor();
    void OnLBdown(HWND);
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnPaint(HWND,HDC,int xk, int yk);
	void PrintInFile(char *);
	void ReadFromFile(char*);
	virtual void OnInitMenuPopup(HWND, WPARAM);
	virtual void PressButton(HWND);
};
#endif !defined(SHAPEDITOR_H)
