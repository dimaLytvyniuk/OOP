#include "stdafx.h"
#include "PuncktLineEditor.h"


PuncktLineEditor::PuncktLineEditor()
{
}


PuncktLineEditor::~PuncktLineEditor()
{
}

void PuncktLineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		//CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		//CheckMenuItem(hSubMenu, IDM_LINEOO, MF_UNCHECKED);
	}
}

void PuncktLineEditor::PressButton(HWND hWnd)
{
	//SendMessage(hWnd, TB_PRESSBUTTON, IDB_POINT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	//SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINEOO, false);;
}

void PuncktLineEditor::OnLBup(HWND hWnd)
{
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		ofstream fout("data_types.txt", ios_base::out | ios_base::app);
		fout << "PuncktLineShape " << pt_start.x << "  " << pt_start.y << "  " << pt.x << "  " << pt.y << endl;
		pcshape[curr_length] = new PuncktLineShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
		curr_length++;
		InvalidateRect(hWnd, NULL, TRUE);
	}
}