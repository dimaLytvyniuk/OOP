#include "stdafx.h"
#include "RectEditor.h"


RectEditor::RectEditor()
{
}


RectEditor::~RectEditor()
{
}

void RectEditor::OnMosuseMove(HWND hWnd)
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

	Rectangle(hdc, xstart, ystart, pt.x, pt.y);

	EndPaint(hWnd, &ps);
}

void RectEditor::OnLBup(HWND hWnd)
{
	POINT pt;
	InvalidateRect(hWnd, NULL, TRUE);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

}


void RectEditor::OnPaint(HWND)
{

}

void RectEditor::OnInitMenuPopup(HWND, WPARAM)
{

}