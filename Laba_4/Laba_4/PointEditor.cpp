#include "stdafx.h"
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
	}
}