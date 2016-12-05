// Cursach.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "Cursach.h"
#include "ToolBar.h"
#include <fstream>
#include <commdlg.h>
#include "ScrollOperations.h"

#define MAX_LOADSTRING 100



// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
ShapeObjectEditor obj_editor;					// керуючий об'єкт
ScrollOperations doc;							// керрування скроллінгом

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	// Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CURSACH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CURSACH));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CURSACH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CURSACH);
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
   hInst = hInstance;  // Сохранить дескриптор экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, LPCWSTR("Курсова робота"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL,
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
	static HWND hWndToolBar;// панель інструментів
	static TCHAR name[256] = _T(""); //ім'я файлу для запису та зберігання
	static OPENFILENAME file;
	static CHOOSECOLOR ccs,//заливка
		penCCS;//контур
	static COLORREF acrCustClr[16];
	static HBRUSH hBrush;
	int xClient = 0,
		yClient = 0;
	static int xInc, yInc,
		currX = 0,//х позиція скролл бару
		currY = 0;//у позиція скролл бару
	static COLORREF stdColor = RGB(255, 255, 255);//початковий колір заливки
	static COLORREF penColor = RGB(0, 0, 0);//початковий колір контуру
	HDC hDc;

    switch (message)
    {
	case WM_CREATE:
		hWndToolBar = CreateToolbarEx(hWnd, TBSTYLE_TOOLTIPS | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS , 1, 9,hInst, IDB_BITMAP1, tbb_1, 9, 25, 25, 25, 25, sizeof(TBBUTTON));//створення панелі інструментів

		//ініціалізація file
		file.lStructSize = sizeof(OPENFILENAME);
		file.hInstance = hInst;
		file.lpstrFilter = _T("Text\0*.txt");
		file.lpstrFile = name;
		file.nMaxFile = 256;
		file.lpstrInitialDir = _T(".\\");
		file.lpstrDefExt = _T("txt");

		//ініціалізація ccs
		ccs.lStructSize = sizeof(CHOOSECOLOR);
		ccs.hwndOwner = hWnd;
		ccs.rgbResult = stdColor;
		ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
		ccs.lpCustColors = (LPDWORD)acrCustClr;

		//ініціалізація penCCS
		penCCS.lStructSize = sizeof(CHOOSECOLOR);
		penCCS.hwndOwner = hWnd;
		penCCS.rgbResult = penColor;
		penCCS.Flags = CC_RGBINIT | CC_FULLOPEN;
		penCCS.lpCustColors = (LPDWORD)acrCustClr;
		break;
	case WM_SIZE:
		SendMessage(hWndToolBar,TB_AUTOSIZE, 0,0);
		hDc = GetDC(hWnd);
		xClient = LOWORD(lParam);
		yClient = HIWORD(lParam);
		if (xClient > 0)
			doc.ScrollSettings(hWnd, xClient, yClient);
		ReleaseDC(hWnd, hDc);
		break;
	case WM_VSCROLL:
		switch (LOWORD(wParam)) {
		case SB_LINEUP:
			yInc = -1; 
			break;
		case SB_LINEDOWN:
			yInc = 1;
			break;
		case SB_PAGEUP:
			yInc = -(int)doc.GetyPage(); 
			break;
		case SB_PAGEDOWN:
			yInc = (int)doc.GetyPage(); 
			break;
		case SB_THUMBTRACK:
			yInc = HIWORD(wParam) - doc.GetVSIpos();
			break;
		default: yInc = 0;
		}
		doc.UpdateVscroll(hWnd, yInc);
		currY = -doc.GetVSIpos() * doc.GetyStep();
		SendMessage(hWndToolBar, TB_AUTOSIZE, 0, 0);
		break;
	case WM_HSCROLL:
			switch (LOWORD(wParam)) 
			{
			case SB_LINELEFT:
				xInc = -1; break;
			case SB_LINERIGHT:
				xInc = 1; 
				break;
			case SB_PAGELEFT:
				xInc = -doc.GetxPage();
				break;
			case SB_PAGERIGHT:
				xInc = doc.GetxPage(); 
				break;
			case SB_THUMBTRACK:
				xInc = HIWORD(wParam) - doc.GetHSIpos();
			break;
			default: xInc = 0;
			}
			doc.UpdateHscroll(hWnd, xInc);
			currX = -doc.GetHSIpos() * doc.GetxStep();
			SendMessage(hWndToolBar, TB_AUTOSIZE, 0, 0);
			break;
	case WM_NOTIFY:
	{
		//TOOLTIPS
		LPNMHDR pnmh = (LPNMHDR)lParam;
		LPSTR pText;
		if (pnmh->code == TTN_NEEDTEXT)
		{
			LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
			switch (lpttt->hdr.idFrom)
			{
			case IDB_ROMB:
				pText = "Ромб";
				break;
			case IDB_LINE:
				pText = "Лінія";
				break;
			case IDB_RECT:
				pText = "Прямокутник";
				break;
			case IDB_ELLIPSE:
				pText = "Еліпс";
				break;
			case IDB_CUBE:
				pText = "Куб";
				break;
			case IDB_CILINDER:
				pText = "Циліндр";
				break;
			case IDB_PUNCKT:
				pText = "Пуктирна лінія";
				break;
			case IDB_FILL:
				pText = "Колір заливки";
				break;
			case IDB_CIRCUIT:
				pText = "Колір контуру";
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
		obj_editor.OnLBup(hWnd, currX, currY);
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
				obj_editor.StartEllipseEditor(stdColor,penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_RECT:
				obj_editor.StartRectEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_LINE:
				obj_editor.StartLineEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_CUBE:
				obj_editor.StartCubeEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_PUNCKT:
				obj_editor.StartPuncktLineEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_ROMB:
				obj_editor.StartRombEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDB_CILINDER:
				obj_editor.StartCilinderEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_LINE:
				obj_editor.StartLineEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_RECT:
				obj_editor.StartRectEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_ELLIPSE:
				obj_editor.StartEllipseEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_CUBE:
				obj_editor.StartCubeEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_PUNKT:
				obj_editor.StartPuncktLineEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_ROMB:
				obj_editor.StartRombEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
			case IDM_CILINDER:
				obj_editor.StartCilinderEditor(stdColor, penColor);
				obj_editor.PressButton(hWndToolBar);
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case IDM_SAVEFILE:
				file.lpstrTitle = _T("Открыть файл для записи");
				file.Flags = OFN_NOTESTFILECREATE;
				if (!GetSaveFileName(&file)) return 1;
				obj_editor.StartWriteFile(name);
				break;
			case IDM_OPENFILE:
				file.lpstrTitle = _T("Открыть файл для чтения");
				file.Flags = OFN_HIDEREADONLY;
				if (!GetOpenFileName(&file)) return 1;
				obj_editor.StartReadFile(name);
				InvalidateRect(hWnd, NULL, 1);
				break;
			case IDB_FILL:
			case IDM_STDCOLOR:
				if (ChooseColor(&ccs))
				{
					stdColor = ccs.rgbResult;
					obj_editor.Reset(hWndToolBar);
				}
				break;
			case IDB_CIRCUIT:
			case IDM_PENCOLOR:
				if (ChooseColor(&penCCS))
				{
					penColor = penCCS.rgbResult;
					obj_editor.Reset(hWndToolBar);
				}
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
			PAINTSTRUCT ps;
			HDC hdc;

			hdc = BeginPaint(hWnd, &ps);
			obj_editor.OnPaint(hWnd,hdc,currX,currY);
			EndPaint(hWnd, &ps);
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
