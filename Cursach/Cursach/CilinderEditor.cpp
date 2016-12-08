#include "stdafx.h"
#include "CilinderEditor.h"


CilinderEditor::CilinderEditor(COLORREF brushColor,COLORREF peColor):ShapeEditor(brushColor,peColor)
{

}


CilinderEditor::~CilinderEditor()
{
}
/*
	 * функція орбробки повідомлення натиснення лівої клавіши миші
	 * xk - зміщення по х
	 * yk - зміщення по у
	 */
void CilinderEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[curr_length] = new CilinderShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt_old.x, pt_old.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//функція орбробки повідомлення руху миші
void CilinderEditor::OnMosuseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;

	//прорахунок координат фігури, яку треба замалювати
	int xs_A = pt_old.x,
		xs_B = pt_start.x,
		ys_A = pt_start.y + (pt_old.y - pt_start.y) / 6,
		ys_B = pt_old.y - (pt_old.y - pt_start.y) / 6,
		xs_C = pt_start.x,
		xs_D = pt_old.x,
		ys_C = pt_start.y + (pt_old.y - pt_start.y) / 12,
		ys_D = pt_old.y - (pt_old.y - pt_start.y) / 12;

	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//замальовуємо стару фігуру
	Ellipse(hdc, xs_B, ys_B, pt_old.x, pt_old.y);
	Rectangle(hdc, xs_C, ys_C, xs_D, ys_D);
	Ellipse(hdc, pt_start.x, pt_start.y, xs_A, ys_A);

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//прорахунок координат фігури, яку треба намалювати
	xs_A = pt_old.x,
	xs_B = pt_start.x,
	ys_A = pt_start.y + (pt_old.y - pt_start.y) / 6,
	ys_B = pt_old.y - (pt_old.y - pt_start.y) / 6,
	xs_C = pt_start.x,
	xs_D = pt_old.x,
	ys_C = pt_start.y + (pt_old.y - pt_start.y) / 12,
	ys_D = pt_old.y - (pt_old.y - pt_start.y) / 12;

	//малюється новий гумовий слід
	Ellipse(hdc, xs_B, ys_B, pt_old.x, pt_old.y);//нижний еллипс
	Rectangle(hdc, xs_C, ys_C, xs_D, ys_D);
	Ellipse(hdc, pt_start.x, pt_start.y, xs_A, ys_A);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

//позначає вибраний елемент у меню
void CilinderEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); 
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_CHECKED);//позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}
}

//позначає вибраний елемент на панелі інструментів 
void CilinderEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}