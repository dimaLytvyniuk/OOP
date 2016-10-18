#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectEditor::ShapeObjectEditor(void)
{

}

ShapeObjectEditor:: ~ShapeObjectEditor()
{

}

void ShapeObjectEditor:: StartPointEditor()
{
	if (pse)
		delete pse;
	pse = new PointEditor;
}

void ShapeObjectEditor::StartLineEditor()
{
	if (pse)
		delete pse;
	pse = new LineEditor();
}

void ShapeObjectEditor::StartRectEditor()
{
	if (pse)
		delete pse;
	pse = new RectEditor;
}

void ShapeObjectEditor::StartEllipseEditor()
{
	if (pse)
		delete pse;
	pse = new EllipseEditor();
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

void ShapeObjectEditor::OnLBup(HWND hWnd)
{
	if (pse)
	{
		pse->OnLBup(hWnd);
		onLBup = true;
		onLBdown = false;
	}
}

void ShapeObjectEditor::OnMosuseMove(HWND hWnd)
{
	if (pse && !onLBup && onLBdown)
		pse->OnMosuseMove(hWnd);
}

void ShapeObjectEditor::OnPaint(HWND hWnd)
{
	if (pse)
		pse->OnPaint(hWnd);
}

void ShapeObjectEditor::OninitMenuPopup(HWND hWnd, WPARAM hWparam)
{
	if (pse)
		pse->OnInitMenuPopup(hWnd, hWparam);
	else
	{
		//ShapeEditor shp;
		//shp.OnInitMenuPopup(hWnd,hWparam);
	}
}

