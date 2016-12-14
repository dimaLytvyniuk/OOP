#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectEditor::ShapeObjectEditor(void)
{

}

ShapeObjectEditor:: ~ShapeObjectEditor()
{

}

/*
	* ������� ����� ��'��� RombEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor:: StartRombEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new RombEditor(brushColor,peColor);
}

/*
	* ������� ����� ��'��� LineEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new LineEditor(brushColor, peColor);
}

/*
	* ������� ����� ��'��� PuncktLineEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartPuncktLineEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new PuncktLineEditor(brushColor, peColor);
}

/*
	* ������� ����� ��'��� CilinderEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartCilinderEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new CilinderEditor(brushColor, peColor);
}

/*
	* ������� ����� ��'��� CubeEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartCubeEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new CubeEditor(brushColor, peColor);
}

/*
	* ������� ����� ��'��� RectEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartRectEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new RectEditor(brushColor, peColor);
}

/*
	* ������� ����� ��'��� EllipseEditor
	* brushColor - ���� �������
	* peColor - ���� �������
	*/
void ShapeObjectEditor::StartEllipseEditor(COLORREF brushColor, COLORREF peColor)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new EllipseEditor(brushColor, peColor);
}

/*
	* ���������� ����� � ���� 
	* name - ��'�
	*/
void ShapeObjectEditor::StartWriteFile(TCHAR* name)
{
	if (pse)
		pse->PrintInFile(name);
}

/*
	* ���������� ���������� � �����
	* name - ��'�
	*/
void ShapeObjectEditor::StartReadFile(TCHAR* name)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}
	pse = new ShapeEditor();
	pse->ReadFromFile(name);
}

//������� �������� ����������� ���������� ��� ������ ����
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
	* ������� �������� ����������� ���������� ��� ������ ����
	* xk - ������� �� �
	* yk - ������� �� �
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

//������� �������� ����������� ���� ����
void ShapeObjectEditor::OnMosuseMove(HWND hWnd)
{
	if (pse && !onLBup && onLBdown)
		pse->OnMosuseMove(hWnd);
}

/*
* ������� ��������� �����
* xk - ������� �� �
* yk - ������� �� �
*/
void ShapeObjectEditor::OnPaint(HWND hWnd,HDC hdc,int xk, int yk)
{
	if (pse)
		pse->OnPaint(hWnd,hdc,xk,yk);
}

//������� �������� ������� � ����
void ShapeObjectEditor::OninitMenuPopup(HWND hWnd, WPARAM hWparam)
{
	if (pse)
		pse->OnInitMenuPopup(hWnd, hWparam);
}

//������� �������� ������� �� ����� ����������� 
void ShapeObjectEditor::PressButton(HWND hWnd)
{
	if (pse)
		pse->PressButton(hWnd);
}

//��������������
void ShapeObjectEditor::Reset(HWND hWndTool)
{
	if (pse)
	{
		delete pse;
		pse = nullptr;
	}


	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ROMB, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWndTool, TB_PRESSBUTTON, IDB_PUNCKT, false);
}

//��������� ���� �����
void ShapeObjectEditor::CreateNewScene()
{
	if (!pse)
		pse = new ShapeEditor();

	pse->CreateNewScene();
}