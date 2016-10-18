#include "stdafx.h"
#include "LineEditor.h"


LineEditor::LineEditor()
{
}


LineEditor::~LineEditor()
{
}

void LineEditor::OnLBup(HWND hWnd)
{

}

void LineEditor::OnMosuseMove(HWND hWnd)
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

	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, pt.x, pt.y);

	EndPaint(hWnd, &ps);
}

void LineEditor::OnPaint(HWND hWnd)
{

}

void LineEditor::OnInitMenuPopup(HWND, WPARAM hWnd)
{

}