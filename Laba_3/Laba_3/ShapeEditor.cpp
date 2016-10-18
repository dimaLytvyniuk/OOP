#include "stdafx.h"
#include "ShapeEditor.h"

Shape **ShapeEditor::pcshape = new Shape * [MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::curr_length = 0;

ShapeEditor::ShapeEditor()
{

}

void ShapeEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
	
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
