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
	static int curr_length;//поточна довжина масиву pcshape
	static Shape *pcshape[MY_SHAPE_ARRAY_SIZE];//масив ф≥гур 
	POINT pt_old;//початков≥ координати
	POINT pt_start;//к≥нцев≥ координати
	COLORREF brColor,//кол≥р заливки
		penColor;//кол≥р контуру
public:
	ShapeEditor(COLORREF,COLORREF);
	ShapeEditor();
    void OnLBdown(HWND);
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnPaint(HWND,HDC,int xk, int yk);
	void PrintInFile(char *);//записуЇ у файл масив pcshape
	void ReadFromFile(char*);//зчитуЇ з файлу у масив pcshape
	virtual void OnInitMenuPopup(HWND, WPARAM);//позначаЇ вибраний елемент у меню
	virtual void PressButton(HWND);//позначаЇ вибраний елемент на панел≥ ≥нструмент≥в
	void OverMeesage();//пов≥домленн€ про зак≥нченн€ м≥сц€ у масив≥ pcshape
};
#endif !defined(SHAPEDITOR_H)
