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
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-���� ��'����
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED); //����� ��������
		CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //��������� ��� �����
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
	}
}

void PuncktLineEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
}

void PuncktLineEditor::OnLBup(HWND hWnd)
{
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		PrintInFile("��������� ����", pt_start.x, pt_start.y, pt.x, pt.y);
		pcshape[curr_length] = new PuncktLineShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
		curr_length++;
		InvalidateRect(hWnd, NULL, TRUE);
	}
}