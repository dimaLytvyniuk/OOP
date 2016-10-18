#include "stdafx.h"
#include "ShapeEditor.h"

Shape **ShapeEditor::pcshape;
int ShapeEditor::curr_length = 0;

ShapeEditor::ShapeEditor()
{
	//curr_length ++;
	//pcshape = new Shape * [MY_SHAPE_ARRAY_SIZE];

}

void ShapeEditor::OnPaint(HWND hWnd)
{
	/*PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i<curr_length; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
	*/
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = pt.x; //кудись записуємо координати початкової точки
	ystart  = pt.y;
}

void ShapeEditor::OnLBup(HWND)
{

}

void ShapeEditor::OnMosuseMove(HWND)
{

}


void ShapeEditor::OnInitMenuPopup(HWND, WPARAM)
{

}