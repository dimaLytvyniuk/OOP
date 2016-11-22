// Cursach.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "Cursach.h"
#include "ToolBar.h"

#define MAX_LOADSTRING 100

TBBUTTON tbb_1[] = {
	{ 0,IDB_RECT,TBSTATE_ENABLED,TBSTYLE_BUTTON,0,0,0,0 },
	{ 1, IDB_ELLIPSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 2, IDB_LINE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 3, IDB_CUBE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 4, IDB_PUNCKT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 5, IDB_ROMB, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 6, IDB_CILINDER, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
};

// ���������� ����������:
HINSTANCE hInst;                                // ������� ���������
WCHAR szTitle[MAX_LOADSTRING];// ����� ������ ���������
WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

ShapeObjectEditor obj_editor;
void OnSize(HWND hWnd, HWND hWndToolBar);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���������� ��� �����.

    // ������������� ���������� �����
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CURSACH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ��������� ������������� ����������:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CURSACH));

    MSG msg;

    // ���� ��������� ���������:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  �������: MyRegisterClass()
//
//  ����������: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CURSACH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CURSACH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����������: ��������� ��������� ���������� � ������� ������� ����.
//
//   �����������:
//
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

   HWND hWnd = CreateWindowW(szWindowClass, LPCWSTR("������� ������"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_HSCROLL,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   ofstream fout("data_types.txt", ios_base::out);
   fout.close();

   return TRUE;
}

//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����������:  ������������ ��������� � ������� ����.
//
//  WM_COMMAND � ���������� ���� ����������
//  WM_PAINT � ���������� ������� ����
//  WM_DESTROY � ��������� ��������� � ������ � ���������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hWndToolBar;
	int y, k;
	static int n, length, sx, sy, cx, iVscrollPos, iHscrollPos, COUNT, MAX_WIDTH;
	n = 1000;
	static SIZE size = { 8, 16 };

    switch (message)
    {
	case WM_CREATE:
		hWndToolBar = CreateToolbarEx(hWnd, TBSTYLE_TOOLTIPS | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP, 1, 7,
	    hInst, IDB_BITMAP1, tbb_1, 7, 25, 25, 25, 25, sizeof(TBBUTTON));
		break;
	case WM_SIZE:
		OnSize(hWnd, hWndToolBar);
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		k = n - sy / size.cy;
		if (k > 0) COUNT = k; else COUNT = iVscrollPos = 0;
		SetScrollRange(hWnd, SB_VERT, 0, COUNT, FALSE);
		SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
		k = length - sx / size.cx;
		if (k > 0) MAX_WIDTH = k; else MAX_WIDTH = iHscrollPos = 0;
		SetScrollRange(hWnd, SB_HORZ, 0, MAX_WIDTH, FALSE);
		SetScrollPos(hWnd, SB_HORZ, iHscrollPos, TRUE);
		break;
	case WM_VSCROLL:
		switch (LOWORD(wParam))
		{
		case SB_LINEUP: iVscrollPos--; break;
		case SB_LINEDOWN: iVscrollPos++; break;
		case SB_PAGEUP: iVscrollPos -= sy / size.cy; break;
		case SB_PAGEDOWN: iVscrollPos += sy / size.cy; break;
		case SB_THUMBPOSITION: iVscrollPos = HIWORD(wParam); break;
		}
		iVscrollPos = max(0, min(iVscrollPos, COUNT));
		if (iVscrollPos != GetScrollPos(hWnd, SB_VERT))
		{
			SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_HSCROLL:
		switch (LOWORD(wParam))
		{
		case SB_LINEUP: iHscrollPos--; break;
		case SB_LINEDOWN: iHscrollPos++; break;
		case SB_PAGEUP: iHscrollPos -= 8; break;
		case SB_PAGEDOWN: iHscrollPos += 8; break;
		case SB_THUMBPOSITION: iHscrollPos = HIWORD(wParam); break;
		}
		iHscrollPos = max(0, min(iHscrollPos, MAX_WIDTH));
		if (iHscrollPos != GetScrollPos(hWnd, SB_HORZ))
		{
			SetScrollPos(hWnd, SB_HORZ, iHscrollPos, TRUE);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_NOTIFY:
	{
		//OnNotify(hWnd, wParam, lParam);
		LPNMHDR pnmh = (LPNMHDR)lParam;
		LPSTR pText;
		if (pnmh->code == TTN_NEEDTEXT)
		{
			LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
			switch (lpttt->hdr.idFrom)
			{
			case IDB_ROMB:
				pText = "����";
				break;
			case IDB_LINE:
				pText = "˳��";
				break;
			case IDB_RECT:
				pText = "�����������";
				break;
			case IDB_ELLIPSE:
				pText = "�����";
				break;
			case IDB_CUBE:
				pText = "���";
				break;
			case IDB_CILINDER:
				pText = "������";
				break;
			case IDB_PUNCKT:
				pText = "��������� ���";
				break;
			default:
				pText = "ToolBar";
				break;
			}
			lstrcpy(lpttt->szText, pText);
		}
		break;
	}
	case WM_LBUTTONDOWN:
		obj_editor.OnLBdown(hWnd);
		break;
	case WM_LBUTTONUP:
		obj_editor.OnLBup(hWnd);
		break;
	case WM_MOUSEMOVE:
		obj_editor.OnMosuseMove(hWnd);
		break;
	case WM_INITMENUPOPUP:
		obj_editor.OninitMenuPopup(hWnd, wParam);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // ��������� ����� � ����:
            switch (wmId)
            {
			case IDB_ELLIPSE:
				obj_editor.StartEllipseEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_RECT:
				obj_editor.StartRectEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_LINE:
				obj_editor.StartLineEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_CUBE:
				obj_editor.StartCubeEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_PUNCKT:
				obj_editor.StartPuncktLineEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_ROMB:
				obj_editor.StartRombEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_CILINDER:
				obj_editor.StartCilinderEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_LINE:
				obj_editor.StartLineEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_RECT:
				obj_editor.StartRectEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_ELLIPSE:
				obj_editor.StartEllipseEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_CUBE:
				obj_editor.StartCubeEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_PUNKT:
				obj_editor.StartPuncktLineEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_ROMB:
				obj_editor.StartRombEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_CILINDER:
				obj_editor.StartCilinderEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
			obj_editor.OnPaint(hWnd);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void OnSize(HWND hWnd, HWND hWndToolBar)
{
	RECT rc, rw;
	if (hWndToolBar)
	{
		GetClientRect(hWnd, &rc);
		GetWindowRect(hWndToolBar, &rw);
		MoveWindow(hWndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
	}
}