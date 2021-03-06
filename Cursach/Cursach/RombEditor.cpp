#include "stdafx.h"
#include "RombEditor.h"


RombEditor::RombEditor(COLORREF brushColor, COLORREF peColor) :ShapeEditor(brushColor, peColor)
{
}


RombEditor::~RombEditor()
{
}

//������� �������� ������� � ����
void RombEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1); //POPUP-���� ��'����
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, IDM_ROMB, MF_CHECKED); //����� ��������
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED); //��������� ��� �����
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CILINDER, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_PUNKT, MF_UNCHECKED);
	}

}

//������� �������� ������� �� ����� ����������� 
void RombEditor::PressButton(HWND hWnd)
{
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ROMB, true);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_LINE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_RECT, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_ELLIPSE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CUBE, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_CILINDER, false);
	SendMessage(hWnd, TB_PRESSBUTTON, IDB_PUNCKT, false);
}

/*
	* ������� �������� ����������� ���������� ��� ������ ����
	* xk - ������� �� �
	* yk - ������� �� �
	*/
void RombEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	//�������� �������� ���� � �����
	if (curr_length < MY_SHAPE_ARRAY_SIZE)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		//PrintInFile("����", pt_start.x, pt_start.y, pt.x, pt.y);
		pcshape[curr_length] = new RombShape();
		pcshape[curr_length]->Set(pt_start.x, pt_start.y, pt_old.x, pt_old.y, brColor, penColor, xk, yk);//������������ ����� 
		curr_length++;//��������� ��������� �������� � ������ pcshape
	}
	else
		OverMeesage();

	InvalidateRect(hWnd, NULL, TRUE);//���������� WM_PAINT
}

//������� �������� ����������� ���� ����
void RombEditor::OnMosuseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;

	//���������� ��������� ������, ��� ����� ����������
	int xs_A = pt_start.x - (pt_old.x - pt_start.x),
		xs_B = pt_start.x,
		ys_A = pt_old.y,
		ys_B = pt_start.y + ((pt_old.y - pt_start.y) * 2);

	hdc = GetDC(hWnd); //�������� �������� ���� ��� ���������
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//������������� ����� ������
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, xs_A, ys_A);
	LineTo(hdc, xs_B, ys_B);
	LineTo(hdc, pt_old.x, pt_old.y);
	LineTo(hdc, pt_start.x, pt_start.y);

	//��������� ���� "��������" ���� ������������ ������������ �������
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pt_old = pt;

	//���������� ��������� ������, ��� ����� ����������
	xs_A = pt_start.x - (pt_old.x - pt_start.x);
	xs_B = pt_start.x;
	ys_A = pt_old.y;
	ys_B = pt_start.y + ((pt_old.y - pt_start.y) * 2);

	//��������� ����� ������� ���
	MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
	LineTo(hdc, xs_A, ys_A);
	LineTo(hdc, xs_B, ys_B);
	LineTo(hdc, pt.x, pt.y);
	LineTo(hdc, pt_start.x, pt_start.y);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}