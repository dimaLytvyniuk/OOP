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
		void StartRombEditor(COLORREF,COLORREF);
		void StartLineEditor(COLORREF, COLORREF);
		void StartRectEditor(COLORREF, COLORREF);
		void StartEllipseEditor(COLORREF, COLORREF);
		void StartPuncktLineEditor(COLORREF, COLORREF);
		void StartCubeEditor(COLORREF, COLORREF);
		void StartCilinderEditor(COLORREF, COLORREF);
		void StartWriteFile(TCHAR*);
		void StartReadFile(TCHAR*);
		void Reset(HWND,WPARAM,HWND);
		void OnLBdown(HWND);
		void OnLBup(HWND);
		void OnMosuseMove(HWND);
		void OnPaint(HWND,HDC);
		void OninitMenuPopup(HWND, WPARAM);
		void PressButton(HWND);
};

