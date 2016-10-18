#include "stdafx.h"
#include "PointEditor.h"


PointEditor::PointEditor()
{
}


PointEditor::~PointEditor()
{
}



void PointEditor::OnLBup(HWND)
{

}

void PointEditor::OnMosuseMove(HWND hWnd)
{
	InvalidateRect(hWnd, NULL, TRUE);

	POINT pt;
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);


	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;

	SetPixel(hdc, pt.x, pt.y, RGB(255, 128, 0));;

	EndPaint(hWnd, &ps);
}

void PointEditor::OnPaint(HWND)
{

}

void PointEditor::OnInitMenuPopup(HWND, WPARAM)
{

}