#pragma once
#include "EllipseEditor.h"
#include "LineEditor.h""
#include "PointEditor.h"
#include "RectEditor.h"

class ShapeObjectEditor
{
	ShapeEditor *pse = NULL;
	bool onLBdown = false,
		onLBup = false;
	public:
		ShapeObjectEditor(void);
		~ShapeObjectEditor();
		void StartPointEditor();
		void StartLineEditor();
		void StartRectEditor();
		void StartEllipseEditor();
		void OnLBdown(HWND);
		void OnLBup(HWND);
		void OnMosuseMove(HWND);
		void OnPaint(HWND);
		void OninitMenuPopup(HWND, WPARAM);

};

