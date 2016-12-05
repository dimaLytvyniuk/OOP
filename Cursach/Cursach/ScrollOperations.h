#pragma once
#include <windows.h>

class ScrollOperations
{
	int xStep; // ������� ������ ������� 
	int yStep; // ������ (���) ������ 
	int lineLenMax; // ������������ ����� ������ 
	SCROLLINFO vsi; // ������������ ��������� 
	int vertRange; // �������� ������������ ������ ��������� 
	SCROLLINFO hsi; // �������������� ��������� 
	int horzRange; // �������� �������������� ������ ��������� 

	public:
		void ScrollSettings(HWND hwnd, int width, int height);//��������� �������
		void UpdateHscroll(HWND hwnd, int xlnc);//������� �������������� �����
		void UpdateVscroll(HWND hwnd, int ylnc);//������� ������������ �����
		int GetHSIpos();//������� hsi.nPos
		int GetVSIpos();//������� vsi.nPos
		int GetxStep();//������� xStep
		int GetyStep();//������� yStep
		int GetyPage();//������� vsi.nPage
		int GetxPage();//������� vsi.nPage
		ScrollOperations();
		~ScrollOperations();
};

