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
		void StartRombEditor(COLORREF,COLORREF);//створює новий об'єкт RombEditor
		void StartLineEditor(COLORREF, COLORREF);//створює новий об'єкт LineEditor
		void StartRectEditor(COLORREF, COLORREF);//створює новий об'єкт RectEditor
		void StartEllipseEditor(COLORREF, COLORREF);//створює новий об'єкт EllipseEditor
		void StartPuncktLineEditor(COLORREF, COLORREF);//створює новий об'єкт PuncktLineEditor
		void StartCubeEditor(COLORREF, COLORREF);//створює новий об'єкт CubeEditor
		void StartCilinderEditor(COLORREF, COLORREF);//створює новий об'єкт CilinderEditor
		void StartWriteFile(TCHAR*);//виконується запис у файл 
		void StartReadFile(TCHAR*);//виконується зчитування з файлу
		void Reset(HWND);//перевантаження
		void OnLBdown(HWND);//функція орбробки повідомлення натиснення лівої клавіши миші
		void OnLBup(HWND, int xk, int yk);//функція орбробки повідомлення відпусксання лівої клавіши миші
		void OnMosuseMove(HWND);//функція орбробки повідомлення руху миші
		void OnPaint(HWND,HDC, int xk, int yk);//функція малювання фігур
		void OninitMenuPopup(HWND, WPARAM);//позначає вибраний елемент у меню
		void PressButton(HWND);//позначає вибраний елемент на панелі інструментів 
		void CreateNewScene();//створення нової сцени
};

