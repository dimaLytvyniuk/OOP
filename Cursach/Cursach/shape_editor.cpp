#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectEditor::ShapeObjectEditor(void)
{

}

ShapeObjectEditor:: ~ShapeObjectEditor()
{

}

void ShapeObjectEditor:: StartRombEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new RombEditor(brushColor,peColor);
}

void ShapeObjectEditor::StartLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new LineEditor(brushColor, peColor);
}
void ShapeObjectEditor::StartPuncktLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new PuncktLineEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartCilinderEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new CilinderEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartCubeEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new CubeEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartRectEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new RectEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartEllipseEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		delete pse;
	pse = new EllipseEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartWriteFile(TCHAR* name)
{
	if (pse)
		pse->PrintInFile(name);
}

void ShapeObjectEditor::StartReadFile(TCHAR* name)
{
	if (pse)
		delete pse;
	pse = new ShapeEditor();
	pse->ReadFromFile(name);
}

void ShapeObjectEditor::OnLBdown(HWND hWnd)
{
	if (pse)
	{
		pse->OnLBdown(hWnd);
		onLBdown = true;
		onLBup = false;
	}
}

void ShapeObjectEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	if (pse)
	{
		pse->OnLBup(hWnd,xk,yk);
		onLBup = true;
		onLBdown = false;
	}
}

void ShapeObjectEditor::OnMosuseMove(HWND hWnd)
{
	if (pse && !onLBup && onLBdown)
		pse->OnMosuseMove(hWnd);
}

void ShapeObjectEditor::OnPaint(HWND hWnd,HDC hdc,int xk, int yk)
{
	if (pse)
		pse->OnPaint(hWnd,hdc,xk,yk);
}

void ShapeObjectEditor::OninitMenuPopup(HWND hWnd, WPARAM hWparam)
{
	if (pse)
		pse->OnInitMenuPopup(hWnd, hWparam);
}

void ShapeObjectEditor::PressButton(HWND hWnd)
{
	if (pse)
		pse->PressButton(hWnd);
}

void ShapeObjectEditor::Reset(HWND hWnd, WPARAM wParam,HWND hWndTool)
{
	if (pse)
		pse = NULL;

	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-меню Об'єкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //позначити цей пункт
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
	}

	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CILINDER, false);
}