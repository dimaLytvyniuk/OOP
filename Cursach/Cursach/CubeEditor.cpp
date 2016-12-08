#include "stdafx.h"
#include "CubeEditor.h"


CubeEditor::CubeEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


CubeEditor::~CubeEditor()
{
}

/*
* функція орбробки повідомлення натиснення лівої клавіши миші
* xk - зміщення по х
* yk - зміщення по у
*/
void CubeEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[curr_length] = new CubeShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt_old.x, pt_old.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//функція орбробки повідомлення руху миші
void CubeEditor::OnMosuseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;

	//прорахунок координат фігури, яку треба замалювати
	int xs_B = pt_old.x + (pt_start.x - pt_old.x) / 3,
		ys_B = pt_old.y - (pt_old.y - pt_start.y) / 3,
		xs_D = pt_start.x - (pt_start.x - pt_old.x) / 3,
		ys_D = pt_start.y + (pt_old.y - pt_start.y) / 3;

	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//замальовуємо стару фігуру
	Rectangle(hdc, xs_B, ys_B, pt_start.x, pt_start.y);
	Rectangle(hdc, xs_D, ys_D, pt_old.x, pt_old.y);
	MoveToEx(hdc, pt_old.x, pt_old.y, NULL);
	LineTo(hdc, xs_B, ys_B);
	MoveToEx(hdc, pt_old.x, ys_D, NULL);
	LineTo(hdc, xs_B, pt_start.y);
	MoveToEx(hdc, xs_D, pt_old.y, NULL);
	LineTo(hdc, pt_start.x, ys_B);
	MoveToEx(hdc, xs_D, ys_D, NULL);
	LineTo(hdc, pt_start.x, pt_start.y);

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//прорахунок координат фігури, яку треба намалювати
	xs_B = pt_old.x + (pt_start.x - pt_old.x) / 3;
	ys_B = pt_old.y - (pt_old.y - pt_start.y) / 3;
	xs_D = pt_start.x - (pt_start.x - pt_old.x) / 3;
	ys_D = pt_start.y + (pt_old.y - pt_start.y) / 3;

	//малюється новий гумовий слід
	Rectangle(hdc, xs_B, ys_B, pt_start.x, pt_start.y);
	Rectangle(hdc, xs_D, ys_D, pt_old.x, pt_old.y);
	MoveToEx(hdc, pt_old.x, pt_old.y, NULL);
	LineTo(hdc, xs_B, ys_B);
	MoveToEx(hdc, pt_old.x, ys_D, NULL);
	LineTo(hdc, xs_B, pt_start.y);
	MoveToEx(hdc, xs_D, pt_old.y, NULL);
	LineTo(hdc, pt_start.x, ys_B);
	MoveToEx(hdc, xs_D, ys_D, NULL);
	LineTo(hdc, pt_start.x, pt_start.y);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

//позначає вибраний елемент у меню
void CubeEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}
}

//позначає вибраний елемент на панелі інструментів 
void CubeEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}