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

	int xStep; // средняя ширина символа 
	int yStep; // высота (шаг) строки 
	int lineLenMax; // максимальная длина строки 
	SCROLLINFO vsi; // вертикальный скроллинг 
	int vertRange; // диапазон вертикальной полосы прокрутки 
	SCROLLINFO hsi; // горизонтальный скроллинг 
	int horzRange; // диапазон горизонтальной полосы прокрутки 
	ScrollOperations();
	~ScrollOperations();
};

