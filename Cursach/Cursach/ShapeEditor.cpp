#include "stdafx.h"
#include "ShapeEditor.h"


Shape *ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::curr_length = 0;

ShapeEditor::ShapeEditor()
{

}

void ShapeEditor::OnPaint(HWND hWnd)
{	
	
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush, hBrushOld;

	hdc = BeginPaint(hWnd, &ps);
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
			pcshape[i]->Show(hdc);
		
	}
	EndPaint(hWnd, &ps);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start);
	pt_old = pt_start; //кудись записуємо координати початкової точки
}

void ShapeEditor::OnLBup(HWND hWnd)
{
	
}

void ShapeEditor::OnMosuseMove(HWND)
{

}
