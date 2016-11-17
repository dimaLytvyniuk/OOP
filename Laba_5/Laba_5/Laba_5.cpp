// Laba_5.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Laba_5.h"
#include "ToolBar.h"

#define MAX_LOADSTRING 100

TBBUTTON tbb_1[] = {
	{ 0,IDB_RECT,TBSTATE_ENABLED,TBSTYLE_BUTTON,0,0,0,0 },
	{ 1, IDB_ELLIPSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 2, IDB_POINT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 3, IDB_LINE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 4, IDB_CUBE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{ 5, IDB_LINEOO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
};

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LABA_5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA_5));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA_5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA_5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hWndToolBar;

    switch (message)
    {
	case WM_CREATE:
		hWndToolBar = CreateToolbarEx(hWnd, TBSTYLE_TOOLTIPS | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP, 1, 6,
			hInst, IDB_BITMAP1, tbb_1, 6, 25, 25, 25, 25, sizeof(TBBUTTON));
		break;
	case WM_SIZE:
		OnSize(hWnd, hWndToolBar);
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
			case IDB_POINT:
				pText = "Point";
				break;
			case IDB_LINE:
				pText = "Line";
				break;
			case IDB_RECT:
				pText = "Rectangle";
				break;
			case IDB_ELLIPSE:
				pText = "Ellipse";
				break;
			case IDB_CUBE:
				pText = "Cube";
				break;
			case IDB_LINEOO:
				pText = "LineOO";
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
            // Разобрать выбор в меню:
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
			case IDB_POINT:
				obj_editor.StartPointEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_CUBE:
				obj_editor.StartCubeEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_LINEOO:
				obj_editor.StartLineOOEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_POINT:
				obj_editor.StartPointEditor();
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
			case IDM_LINEOO:
				obj_editor.StartLineOOEditor();
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_KARCAS:
				obj_editor.StartCubeEditor();
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

// Обработчик сообщений для окна "О программе".
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