#pragma once
#if !defined(EDITOR_H)
#define EDITOR_H
class Editor
{
public:
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND) = 0;
	virtual void OnMosuseMove(HWND) = 0;
	virtual void OnPaint(HWND) = 0;
};
#endif !defined(EDITOR_H)

