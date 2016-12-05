#include "stdafx.h"
#include "RombEditor.h"


RombEditor::RombEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


RombEditor::~RombEditor()
{
}

//позначає вибраний елемент у меню
void RombEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_CHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}

}

//позначає вибраний елемент на панелі інструментів 
void RombEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void RombEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		//PrintInFile("Ромб", pt_start.x, pt_start.y, pt.x, pt.y);
		pcshape[curr_length] = new RombShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt_old.x, pt_old.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//функція орбробки повідомлення руху миші
void RombEditor::OnMosuseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;

	//прорахунок координат фігури, яку треба замалювати
	int xs_A = pt_start.x - (pt_old.x - pt_start.x),
		xs_B = pt_start.x,
		ys_A = pt_old.y,
		ys_B = pt_start.y + ((pt_old.y - pt_start.y) * 2);

	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//замальовується стара фігура
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, xs_A, ys_A);
	LineTo(hdc, xs_B, ys_B);
	LineTo(hdc, pt_old.x, pt_old.y);
	LineTo(hdc, pt_start.x, pt_start.y);

	//Малюються лінії "гумового" сліду попереднього розташування курсору
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//прорахунок координат фігури, яку треба намалювати
	xs_A = pt_start.x - (pt_old.x - pt_start.x);
	xs_B = pt_start.x;
	ys_A = pt_old.y;
	ys_B = pt_start.y + ((pt_old.y - pt_start.y) * 2);

	//малюється новий гумовий слід
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, xs_A, ys_A);
	LineTo(hdc, xs_B, ys_B);
	LineTo(hdc, pt.x, pt.y);
	LineTo(hdc, pt_start.x, pt_start.y);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}