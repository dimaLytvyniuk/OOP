#include "stdafx.h"
#include "history_sheet.h"
#include "Commctrl.h"

HWND hTable;
int count = 0;

INT_PTR CALLBACK SheetDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_CREATE:
		OnInit(hDlg);
		break;
	case WM_INITDIALOG:
		OnInit(hDlg);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	default:
		break;
	}
	return (INT_PTR)FALSE;
}

void OnInit(HWND hDlg)
{
	RECT rcClient;

	GetClientRect(hDlg, &rcClient);
	hTable = CreateWindow(WC_LISTVIEW,"",WS_VISIBLE | WS_BORDER | WS_CHILD |LVS_REPORT | LVS_EDITLABELS | LVS_NOCOLUMNHEADER,0, 0,
		rcClient.right,rcClient.bottom,hDlg,(HMENU)1008,NULL,NULL);

	ListView_SetExtendedListViewStyleEx(hTable,
		LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);

	ListView_SetExtendedListViewStyleEx(hTable,
		LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);


	LVCOLUMN lvc;
	memset(&lvc, 0, sizeof(LV_COLUMN));
	lvc.mask = LVCFMT_LINE_BREAK | LVCF_WIDTH | LVCF_TEXT;
	lvc.iSubItem = 0;
	lvc.cx = 100;
	lvc.fmt = LVCFMT_LEFT;
	ListView_InsertColumn(hTable, 0, &lvc);


	lvc.cx = 100;
	lvc.iSubItem = 1;
	ListView_InsertColumn(hTable, 1, &lvc);

	lvc.cx = 100;
	lvc.iSubItem = 2;
	ListView_InsertColumn(hTable, 2, &lvc);

	lvc.cx = 100;
	lvc.iSubItem = 1;
	ListView_InsertColumn(hTable, 3, &lvc);

	lvc.cx = 100;
	lvc.iSubItem = 2;
	ListView_InsertColumn(hTable, 4, &lvc);


	LV_ITEM lvI;
	memset(&lvI, 0, sizeof(LVITEM));
	lvI.mask = LVIF_TEXT | LVIF_STATE | LVIF_COLUMNS | LVIF_COLFMT;
	lvI.stateMask = 0;
	lvI.iSubItem = 0;
	lvI.state = 0;
	lvI.iItem = 0;
	ListView_InsertItem(hTable, &lvI);
	lvI.iSubItem = 1;
	lvI.iItem = 1;
	ListView_InsertItem(hTable, &lvI);

	ListView_SetItemText(hTable, 0, 0, TEXT("Назва"));
	ListView_SetItemText(hTable, 0, 1, TEXT("x початок"));
	ListView_SetItemText(hTable, 0, 2, TEXT("y початок"));
	ListView_SetItemText(hTable, 0, 3, TEXT("x кінець"));
	ListView_SetItemText(hTable, 0, 4, TEXT("y кінець"));

}

void AddToTable(char* type,int xs1,int ys1,int xs2,int ys2)
{
	count++;
	char* strbuffer = new char[10];

	LV_ITEM lvI;
	memset(&lvI, 0, sizeof(LVITEM));
	lvI.mask = LVIF_TEXT | LVIF_STATE | LVIF_COLUMNS | LVIF_COLFMT;
	lvI.stateMask = 0;
	lvI.iSubItem = 0;
	lvI.state = 0;
	lvI.iItem = count;

	ListView_InsertItem(hTable, &lvI);

	ListView_SetItemText(hTable, count, 0, type)
	_itoa_s(xs1, strbuffer, 10, 10);
	ListView_SetItemText(hTable, count, 1, strbuffer);
	_itoa_s(ys1, strbuffer, 10, 10);
	ListView_SetItemText(hTable, count, 2, strbuffer);
	_itoa_s(xs2, strbuffer, 10, 10);
	ListView_SetItemText(hTable, count, 3, strbuffer);
	_itoa_s(ys2, strbuffer, 10, 10);
	ListView_SetItemText(hTable, count, 4, strbuffer);

	ListView_EnsureVisible(hTable, count, false);
}
