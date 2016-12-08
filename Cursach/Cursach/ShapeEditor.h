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
	static int curr_length;//������� ������� ������ pcshape
	static Shape *pcshape[MY_SHAPE_ARRAY_SIZE];//����� ����� 
	POINT pt_old;//�������� ����������
	POINT pt_start;//����� ����������
	COLORREF brColor,//���� �������
		penColor;//���� �������
public:
	ShapeEditor(COLORREF,COLORREF);
	ShapeEditor();
    void OnLBdown(HWND);
	void OnLBup(HWND, int xk, int yk);
	void OnMosuseMove(HWND);
	void OnPaint(HWND,HDC,int xk, int yk);
	void PrintInFile(char *);//������ � ���� ����� pcshape
	void ReadFromFile(char*);//����� � ����� � ����� pcshape
	virtual void OnInitMenuPopup(HWND, WPARAM);//������� �������� ������� � ����
	virtual void PressButton(HWND);//������� �������� ������� �� ����� �����������
	void OverMeesage();//����������� ��� ��������� ���� � ����� pcshape
	void CreateNewScene();//��������� ���� �����
};
#endif !defined(SHAPEDITOR_H)
