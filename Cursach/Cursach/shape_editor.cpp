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
		pse = NULL;
	pse = new RombEditor(brushColor,peColor);
}

void ShapeObjectEditor::StartLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new LineEditor(brushColor, peColor);
}
void ShapeObjectEditor::StartPuncktLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new PuncktLineEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartCilinderEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new CilinderEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartCubeEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new CubeEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartRectEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new RectEditor(brushColor, peColor);
}

void ShapeObjectEditor::StartEllipseEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
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
		pse = NULL;
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

void ShapeObjectEditor::Reset(HWND hWndTool)
{
	if (pse)
		pse = NULL;


	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_PUNCKT, false);
}