#include "stdafx.h"
#include "ScrollOperations.h"


ScrollOperations::ScrollOperations()
{
	xStep = 10;
	yStep = 10;
	vsi.nMin = 0;
	hsi.nMin = 0;
}


ScrollOperations::~ScrollOperations()
{
}

//налаштовує скролінг
void ScrollOperations::ScrollSettings (HWND hwnd, int width, int height) 
{
	// Вертикальный скроллинг 
	vsi.cbSize = sizeof(vsi);
	vsi.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	vsi.nPage = height / yStep - 1;
	vsi.nMax = 199;
	if (vsi.nPage > vsi.nMax)
		vsi.nPos = vsi.nMin;

	vertRange = vsi.nMax - vsi.nMin + 1;
	SetScrollInfo(hwnd, SB_VERT, &vsi, TRUE);

	// Горизонтальный скроллинг 
	hsi.cbSize = sizeof(SCROLLINFO);
	hsi.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	hsi.nPage = width / xStep - 2;
	hsi.nMax = 198;
	if (hsi.nPage > hsi.nMax)
		hsi.nPos = hsi.nMin;
	horzRange = hsi.nMax - hsi.nMin + 1;
	SetScrollInfo(hwnd, SB_HORZ, &hsi, TRUE);
}

//оновлює вертикальний скрол
void ScrollOperations::UpdateVscroll(HWND hwnd, int yInc)
{
	// ограничение на положительное приращение 
	yInc = min(yInc, vertRange - (int)vsi.nPage - vsi.nPos);
		// ограничение на отрицательное приращение 
	yInc = max(yInc,vsi.nMin - vsi.nPos);

	if (yInc) 
	{
		ScrollWindow(hwnd, 0, -yStep * yInc, NULL, NULL);
		vsi.nPos += yInc;
		SetScrollInfo(hwnd, SB_VERT, &vsi, TRUE);
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
	}
}

//оновлює горизонтальний скрол
void ScrollOperations::UpdateHscroll(HWND hwnd, int xInc)
{
	// ограничение на положительное приращение 
	xInc = min(xInc,horzRange - (int)hsi.nPage - hsi.nPos);
	// ограничение на отрицательное приращение 
	xInc = max(xInc, hsi.nMin - hsi.nPos);
	if (xInc) {
		ScrollWindow(hwnd, -xStep * xInc, 0, NULL, NULL);
		hsi.nPos += xInc;
		SetScrollInfo(hwnd, SB_HORZ, &hsi, TRUE);
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
	}
}

//повертає hsi.nPos
int ScrollOperations::GetHSIpos()
{
	return hsi.nPos;
}

//повертає vsi.nPos
int ScrollOperations::GetVSIpos()
{
	return vsi.nPos;
}

//повертає xStep
int ScrollOperations::GetxStep()
{
	return xStep;
}

//повертає yStep
int ScrollOperations::GetyStep()
{
	return yStep;
}

//повертає vsi.nPage
int ScrollOperations::GetyPage()
{
	return vsi.nPage;
}

//повертає vsi.nPage
int ScrollOperations::GetxPage()
{
	return hsi.nPage;
}