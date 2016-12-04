#pragma once
#include <windows.h>

class ScrollOperations
{
public:
	void Initialize(LPTEXTMETRIC tm);
	void ScrollSettings(HWND hwnd, int width, int height);
	void UpdateHscroll(HWND hwnd, int xlnc);
	void UpdateVscroll(HWND hwnd, int ylnc);
	void PutText(HWND hwnd, HDC hd);

	int xStep; // ������� ������ ������� 
	int yStep; // ������ (���) ������ 
	int lineLenMax; // ������������ ����� ������ 
	SCROLLINFO vsi; // ������������ ��������� 
	int vertRange; // �������� ������������ ������ ��������� 
	SCROLLINFO hsi; // �������������� ��������� 
	int horzRange; // �������� �������������� ������ ��������� 
	ScrollOperations();
	~ScrollOperations();
};

