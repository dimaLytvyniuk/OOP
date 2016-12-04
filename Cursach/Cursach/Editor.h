#pragma once
#if !defined(EDITOR_H)
#define EDITOR_H
#include "Resource.h"
#include <fstream>
#include <iomanip> // манипуляторы ввода/вывода
#include <iostream>
using namespace std;

class Editor
{
public:
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND, int xk, int yk) = 0;
	virtual void OnMosuseMove(HWND) = 0;
	virtual void OnPaint(HWND,HDC, int xk, int yk) = 0;
};
#endif !defined(EDITOR_H)

