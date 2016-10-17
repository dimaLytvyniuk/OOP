#pragma once
class ShapeObjectEditor
{
	int curr_length = 0,
		max_legth = 106;
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

