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
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[curr_length] = new EllipseShape();
	pcshape[curr_length]->Set(pt_start.x - (pt.x - pt_start.x), pt_start.y - (pt.y - pt_start.y), pt_old.x, pt_old.y);
	curr_length++;
	InvalidateRect(hWnd, NULL, TRUE);
}

void EllipseEditor::OnMosuseMove(HWND hWnd)
{
	//Ellipse(hdc, xstart - (pt.x - xstart), ystart - (pt.y - ystart), pt.x, pt.y);
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, pt_start.x - (pt_old.x - pt_start.x), pt_start.y - (pt_old.y - pt_start.y), pt_old.x, pt_old.y);  //Малюються лінії "гумового" сліду попереднього розташування курсору
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;
	Ellipse(hdc, pt_start.x - (pt.x - pt_start.x), pt_start.y - (pt.y - pt_start.y), pt_old.x, pt_old.y); //Малюються лінії "гумового" сліду для поточного розташування курсору															//ShapeShadow(hdc);
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