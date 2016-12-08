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
	virtual void OnLBdown(HWND) = 0;//функція орбробки повідомлення натиснення лівої клавіши миші
	virtual void OnLBup(HWND, int xk, int yk) = 0;//функція орбробки повідомлення відпусксання лівої клавіши миші
	virtual void OnMosuseMove(HWND) = 0;//функція орбробки повідомлення руху миші
	virtual void OnPaint(HWND,HDC, int xk, int yk) = 0;//функція малювання фігур
};
#endif !defined(EDITOR_H)

