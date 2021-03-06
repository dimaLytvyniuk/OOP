﻿#include "stdafx.h"
#include "RectEditor.h"


RectEditor::RectEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


RectEditor::~RectEditor()
{
}

//функція орбробки повідомлення руху миші
void RectEditor::OnMosuseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	//замальовується стара фігура
	Rectangle(hdc, pt_start.x , pt_start.y, pt_old.x, pt_old.y);
	
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//малюється новий гумовий слід
	Rectangle(hdc, pt_start.x , pt_start.y, pt_old.x, pt_old.y);
	
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void RectEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		//PrintInFile("Прямокутник", pt_start.x, pt_start.y, pt.x, pt.y);
		pcshape[curr_length] = new RectShape();
		pcshape[curr_length]->Set(pt_start.x , pt_start.y , pt_old.x, pt_old.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//позначає вибраний елемент у меню
void RectEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}
}

//позначає вибраний елемент на панелі інструментів 
void RectEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}