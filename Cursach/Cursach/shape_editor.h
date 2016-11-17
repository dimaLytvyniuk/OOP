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
		void StartRombEditor();
		void StartLineEditor();
		void StartRectEditor();
		void StartEllipseEditor();
		void StartPuncktLineEditor();
		void StartCubeEditor();
		void StartCilinderEditor();
		void OnLBdown(HWND);
		void OnLBup(HWND);
		void OnMosuseMove(HWND);
		void OnPaint(HWND);
		void OninitMenuPopup(HWND, WPARAM);
		void PressButton(HWND);
};

