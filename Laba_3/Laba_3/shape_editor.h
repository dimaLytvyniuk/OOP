#pragma once
class ShapeObjectEditor
{
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

