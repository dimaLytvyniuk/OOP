﻿#include "stdafx.h"
#include "EllipseEditor.h"


EllipseEditor::EllipseEditor()
{
}


EllipseEditor::~EllipseEditor()
{
}

void EllipseEditor::OnLBup(HWND hWnd)
{
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[curr_length] = new EllipseShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
		curr_length++;
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void EllipseEditor::OnMosuseMove(HWND hWnd)
{
	//Ellipse(hdc, xstart - (pt.x - xstart), ystart - (pt.y - ystart), pt.x, pt.y);
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;
	Ellipse(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_CHECKED); //позначити цей пункт
	}

}