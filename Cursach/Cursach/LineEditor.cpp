#include "stdafx.h"
#include "LineEditor.h"


LineEditor::LineEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


LineEditor::~LineEditor()
{
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void LineEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		//PrintInFile("Лінія", pt_start.x, pt_start.y, pt.x, pt.y);
		pcshape[curr_length] = new LineShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//функція орбробки повідомлення руху миші
void LineEditor::OnMosuseMove(HWND hWnd)
{
	
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	//замальовується стара фігура
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, pt_old.x, pt_old.y);

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//малюється новий гумовий слід
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, pt.x, pt.y); 

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

//позначає вибраний елемент у меню
void LineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}
}

//позначає вибраний елемент на панелі інструментів 
void LineEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}