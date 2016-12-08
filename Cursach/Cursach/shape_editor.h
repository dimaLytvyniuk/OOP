#pragma once
#include "EllipseEditor.h"
#include "LineEditor.h""
#include "RectEditor.h"
#include "CubeEditor.h"
#include "PuncktLineEditor.h"
#include "RombEditor.h"
#include "CilinderEditor.h"

class ShapeObjectEditor
{
	ShapeEditor *pse = NULL;
	bool onLBdown = false,
		onLBup = false;
	public:
		ShapeObjectEditor(void);
		~ShapeObjectEditor();
		void StartRombEditor(COLORREF,COLORREF);//������� ����� ��'��� RombEditor
		void StartLineEditor(COLORREF, COLORREF);//������� ����� ��'��� LineEditor
		void StartRectEditor(COLORREF, COLORREF);//������� ����� ��'��� RectEditor
		void StartEllipseEditor(COLORREF, COLORREF);//������� ����� ��'��� EllipseEditor
		void StartPuncktLineEditor(COLORREF, COLORREF);//������� ����� ��'��� PuncktLineEditor
		void StartCubeEditor(COLORREF, COLORREF);//������� ����� ��'��� CubeEditor
		void StartCilinderEditor(COLORREF, COLORREF);//������� ����� ��'��� CilinderEditor
		void StartWriteFile(TCHAR*);//���������� ����� � ���� 
		void StartReadFile(TCHAR*);//���������� ���������� � �����
		void Reset(HWND);//��������������
		void OnLBdown(HWND);//������� �������� ����������� ���������� ��� ������ ����
		void OnLBup(HWND, int xk, int yk);//������� �������� ����������� ����������� ��� ������ ����
		void OnMosuseMove(HWND);//������� �������� ����������� ���� ����
		void OnPaint(HWND,HDC, int xk, int yk);//������� ��������� �����
		void OninitMenuPopup(HWND, WPARAM);//������� �������� ������� � ����
		void PressButton(HWND);//������� �������� ������� �� ����� ����������� 
		void CreateNewScene();//��������� ���� �����
};

