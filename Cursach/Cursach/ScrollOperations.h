#pragma once
#include <windows.h>

class ScrollOperations
{
	int xStep; // средн€€ ширина символа 
	int yStep; // высота (шаг) строки 
	int lineLenMax; // максимальна€ длина строки 
	SCROLLINFO vsi; // вертикальный скроллинг 
	int vertRange; // диапазон вертикальной полосы прокрутки 
	SCROLLINFO hsi; // горизонтальный скроллинг 
	int horzRange; // диапазон горизонтальной полосы прокрутки 

	public:
		void ScrollSettings(HWND hwnd, int width, int height);//налаштовуЇ скрол≥нг
		void UpdateHscroll(HWND hwnd, int xlnc);//оновлюЇ горизонтальний скрол
		void UpdateVscroll(HWND hwnd, int ylnc);//оновлюЇ вертикальний скрол
		int GetHSIpos();//повертаЇ hsi.nPos
		int GetVSIpos();//повертаЇ vsi.nPos
		int GetxStep();//повертаЇ xStep
		int GetyStep();//повертаЇ yStep
		int GetyPage();//повертаЇ vsi.nPage
		int GetxPage();//повертаЇ vsi.nPage
		ScrollOperations();
		~ScrollOperations();
};

