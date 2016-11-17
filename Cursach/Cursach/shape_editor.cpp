#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectEditor::ShapeObjectEditor(void)
{

}

ShapeObjectEditor:: ~ShapeObjectEditor()
{

}

void ShapeObjectEditor:: StartRombEditor()
{
	if (pse)
		delete pse;
	pse = new RombEditor();
}

void ShapeObjectEditor::StartLineEditor()
{
	if (pse)
		delete pse;
	pse = new LineEditor();
}
void ShapeObjectEditor::StartPuncktLineEditor()
{
	if (pse)
		delete pse;
	pse = new PuncktLineEditor();
}

void ShapeObjectEditor::StartCilinderEditor()
{
	if (pse)
		delete pse;
	pse = new CilinderEditor();
}

void ShapeObjectEditor::StartCubeEditor()
{
	if (pse)
		delete pse;
	pse = new CubeEditor();
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
}

void ShapeObjectEditor::PressButton(HWND hWnd)
{
	if (pse)
		pse->PressButton(hWnd);
}