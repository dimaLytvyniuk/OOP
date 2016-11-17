﻿#include "stdafx.h"
#include "PointEditor.h"


PointEditor::PointEditor()
{
}


PointEditor::~PointEditor()
{
}



void PointEditor::OnLBup(HWND hWnd)
{
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		pcshape[curr_length] = new PointShape();
		POINT pt;
		GetCursorPos(&pt);
		ofstream fout("data_types.txt", ios_base::out | ios_base::app);
		fout << "PointShape\t" << pt_start.x << "\t" << pt_start.y << "\t" << pt.x << "\t" << pt.y << endl;
		ScreenToClient(hWnd, &pt);
		pcshape[curr_length]->Set(pt.x, pt.y, 0, 0);
		curr_length++;
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void PointEditor::OnMosuseMove(HWND hWnd)
{

}

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_POINT, MF_CHECKED); //зняти позначку
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_KARCAS, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINEOO, MF_UNCHECKED);
	}
}

void PointEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_POINT, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINEOO, false);
}