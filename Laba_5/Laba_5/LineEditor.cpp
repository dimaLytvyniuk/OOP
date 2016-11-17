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
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		ofstream fout("data_types.txt", ios_base::out | ios_base::app);
		fout << "LineShape\t" << pt_start.x << "\t" << pt_start.y << "\t" << pt.x << "\t" << pt.y << endl;
		pcshape[curr_length] = new LineShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
		curr_length++;
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void LineEditor::OnMosuseMove(HWND hWnd)
{
	
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, pt_old.x, pt_old.y);
	//Малюються лінії "гумового" сліду попереднього розташування курсору
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, pt.x, pt.y); //Малюються лінії "гумового" сліду для поточного розташування курсору
							 //ShapeShadow(hdc);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

void LineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_KARCAS, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINEOO, MF_UNCHECKED);
	}
}

void LineEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_POINT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINEOO, false);;
}