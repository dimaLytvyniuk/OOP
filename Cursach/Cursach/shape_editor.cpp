#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectEditor::ShapeObjectEditor(void)
{

}

ShapeObjectEditor:: ~ShapeObjectEditor()
{

}

/*
	* створює новий об'єкт RombEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor:: StartRombEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new RombEditor(brushColor,peColor);
}

/*
	* створює новий об'єкт LineEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new LineEditor(brushColor, peColor);
}

/*
	* створює новий об'єкт PuncktLineEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartPuncktLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new PuncktLineEditor(brushColor, peColor);
}

/*
	* створює новий об'єкт CilinderEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartCilinderEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new CilinderEditor(brushColor, peColor);
}

/*
	* створює новий об'єкт CubeEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartCubeEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new CubeEditor(brushColor, peColor);
}

/*
	* створює новий об'єкт RectEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartRectEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new RectEditor(brushColor, peColor);
}

/*
	* створює новий об'єкт EllipseEditor
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
void ShapeObjectEditor::StartEllipseEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
		pse = NULL;
	pse = new EllipseEditor(brushColor, peColor);
}

/*
	* виконується запис у файл 
	* name - ім'я
	*/
void ShapeObjectEditor::StartWriteFile(TCHAR* name)
{
	if (pse)
		pse->PrintInFile(name);
}

/*
	* виконується зчитування з файлу
	* name - ім'я
	*/
void ShapeObjectEditor::StartReadFile(TCHAR* name)
{
	if (pse)
		pse = NULL;
	pse = new ShapeEditor();
	pse->ReadFromFile(name);
}

//функція орбробки повідомлення натиснення лівої клавіши миші
void ShapeObjectEditor::OnLBdown(HWND hWnd)
{
	if (pse)
	{
		pse->OnLBdown(hWnd);
		onLBdown = true;
		onLBup = false;
	}
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void ShapeObjectEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	if (pse)
	{
		pse->OnLBup(hWnd,xk,yk);
		onLBup = true;
		onLBdown = false;
	}
}

//функція орбробки повідомлення руху миші
void ShapeObjectEditor::OnMosuseMove(HWND hWnd)
{
	if (pse && !onLBup && onLBdown)
		pse->OnMosuseMove(hWnd);
}

/*
* функція малювання фігур
* xk - зміщення по х
* yk - зміщення по у
*/
void ShapeObjectEditor::OnPaint(HWND hWnd,HDC hdc,int xk, int yk)
{
	if (pse)
		pse->OnPaint(hWnd,hdc,xk,yk);
}

//позначає вибраний елемент у меню
void ShapeObjectEditor::OninitMenuPopup(HWND hWnd, WPARAM hWparam)
{
	if (pse)
		pse->OnInitMenuPopup(hWnd, hWparam);
}

//позначає вибраний елемент на панелі інструментів 
void ShapeObjectEditor::PressButton(HWND hWnd)
{
	if (pse)
		pse->PressButton(hWnd);
}

//перевантаження
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