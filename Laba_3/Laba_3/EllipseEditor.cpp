#include "stdafx.h"
#include "EllipseEditor.h"


EllipseEditor::EllipseEditor()
{
}


EllipseEditor::~EllipseEditor()
{
}

void EllipseEditor::OnLBup(HWND hWnd)
{

}

void EllipseEditor::OnMosuseMove(HWND hWnd)
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

	Ellipse(hdc, xstart - (pt.x - xstart), ystart - (pt.y - ystart), pt.x, pt.y);

	EndPaint(hWnd, &ps);
}

void EllipseEditor::OnPaint(HWND hWnd)
{

}

void EllipseEditor::OnInitMenuPopup(HWND, WPARAM)
{

}