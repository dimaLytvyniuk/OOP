#include "stdafx.h"
#include "EllipseEditor.h"


EllipseEditor::EllipseEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


EllipseEditor::~EllipseEditor()
{
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void EllipseEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//перевірка наявності місця у масиві
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[curr_length] = new EllipseShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y, brColor, penColor, xk, yk);//ініціалізація змінної 
		curr_length++;//збільшення лічильника елементів у массиві pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//вікликається WM_PAINT
}

//функція орбробки повідомлення руху миші
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
	
	//замальовуємо стару фігуру
	Ellipse(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y);
	
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//малюється новий гумовий слід
	Ellipse(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y);
	
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
}

//позначає вибраний елемент у меню
void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_CHECKED); 
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}

}

//позначає вибраний елемент на панелі інструментів 
void EllipseEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}