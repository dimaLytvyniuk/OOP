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
	static Shape *pcshape[MY_SHAPE_ARRAY_SIZE];//масив фігур 
	POINT pt_old;//початкові координати
	POINT pt_start;//кінцеві координати
	COLORREF brColor,//колір заливки
		penColor;//колір контуру
public:
	ShapeEditor(COLORREF,COLORREF);
	ShapeEditor();
    void OnLBdown(HWND);
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnPaint(HWND,HDC,int xk, int yk);
	void PrintInFile(char *);//записує у файл масив pcshape
	void ReadFromFile(char*);//зчитує з файлу у масив pcshape
	virtual void OnInitMenuPopup(HWND, WPARAM);//позначає вибраний елемент у меню
	virtual void PressButton(HWND);//позначає вибраний елемент на панелі інструментів
	void OverMeesage();//повідомлення про закінчення місця у масиві pcshape
	void CreateNewScene();//створення нової сцени
};
#endif !defined(SHAPEDITOR_H)
