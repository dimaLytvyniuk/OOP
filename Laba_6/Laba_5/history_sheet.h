#pragma once
INT_PTR CALLBACK SheetDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void OnInit(HWND hDlg);
void AddToTable(char* type, int xs1, int ys1, int xs2, int ys2);