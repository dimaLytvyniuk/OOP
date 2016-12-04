// Cursach.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "Cursach.h"
#include "ToolBar.h"
#include <fstream>
#include <commdlg.h>
#include "ScrollOperations.h"

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

// Ãëîáàëüíûå ïåðåìåííûå:
HINSTANCE hInst;                                // òåêóùèé ýêçåìïëÿð
WCHAR szTitle[MAX_LOADSTRING];// Òåêñò ñòðîêè çàãîëîâêà
WCHAR szWindowClass[MAX_LOADSTRING];            // èìÿ êëàññà ãëàâíîãî îêíà

// Îòïðàâèòü îáúÿâëåíèÿ ôóíêöèé, âêëþ÷åííûõ â ýòîò ìîäóëü êîäà:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

ShapeObjectEditor obj_editor;
void OnSize(HWND hWnd, HWND hWndToolBar);
COLORREF stdColor = RGB(255, 255, 255);
COLORREF penColor = RGB(0, 0, 0);
ScrollOperations doc;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ðàçìåñòèòå êîä çäåñü.

    // Èíèöèàëèçàöèÿ ãëîáàëüíûõ ñòðîê
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CURSACH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Âûïîëíèòü èíèöèàëèçàöèþ ïðèëîæåíèÿ:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CURSACH));

    MSG msg;

    // Öèêë îñíîâíîãî ñîîáùåíèÿ:
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
//  ÔÓÍÊÖÈß: MyRegisterClass()
//
//  ÍÀÇÍÀ×ÅÍÈÅ: ðåãèñòðèðóåò êëàññ îêíà.
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
//   ÔÓÍÊÖÈß: InitInstance(HINSTANCE, int)
//
//   ÍÀÇÍÀ×ÅÍÈÅ: ñîõðàíÿåò îáðàáîòêó ýêçåìïëÿðà è ñîçäàåò ãëàâíîå îêíî.
//
//   ÊÎÌÌÅÍÒÀÐÈÈ:
//
//        Â äàííîé ôóíêöèè äåñêðèïòîð ýêçåìïëÿðà ñîõðàíÿåòñÿ â ãëîáàëüíîé ïåðåìåííîé, à òàêæå
//        ñîçäàåòñÿ è âûâîäèòñÿ íà ýêðàí ãëàâíîå îêíî ïðîãðàììû.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Ñîõðàíèòü äåñêðèïòîð ýêçåìïëÿðà â ãëîáàëüíîé ïåðåìåííîé

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
//  ÔÓÍÊÖÈß: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ÍÀÇÍÀ×ÅÍÈÅ:  îáðàáàòûâàåò ñîîáùåíèÿ â ãëàâíîì îêíå.
//
//  WM_COMMAND — îáðàáîòàòü ìåíþ ïðèëîæåíèÿ
//  WM_PAINT — îòðèñîâàòü ãëàâíîå îêíî
//  WM_DESTROY — îòïðàâèòü ñîîáùåíèå î âûõîäå è âåðíóòüñÿ
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hWndToolBar;
	static TCHAR name[256] = _T("");
	static OPENFILENAME file;
	static CHOOSECOLOR ccs,
		penCCS;
	static COLORREF acrCustClr[16];
	static HBRUSH hBrush;
	int xClient = 0,
		yClient = 0;
	static int xInc, yInc,
		currX = 0,
		currY = 0;
	
	HDC hDc;

    switch (message)
    {
	case WM_CREATE:
		hWndToolBar = CreateToolbarEx(hWnd, TBSTYLE_TOOLTIPS | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP, 1, 7,hInst, IDB_BITMAP1, tbb_1, 7, 25, 25, 25, 25, sizeof(TBBUTTON));

		file.lStructSize = sizeof(OPENFILENAME);
		file.hInstance = hInst;
		file.lpstrFilter = _T("Text\0*.txt");
		file.lpstrFile = name;
		file.nMaxFile = 256;
		file.lpstrInitialDir = _T(".\\");
		file.lpstrDefExt = _T("txt");

		ccs.lStructSize = sizeof(CHOOSECOLOR);
		ccs.hwndOwner = hWnd;
		ccs.rgbResult = stdColor;
		ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
		ccs.lpCustColors = (LPDWORD)acrCustClr;

		penCCS.lStructSize = sizeof(CHOOSECOLOR);
		penCCS.hwndOwner = hWnd;
		penCCS.rgbResult = stdColor;
		penCCS.Flags = CC_RGBINIT | CC_FULLOPEN;
		penCCS.lpCustColors = (LPDWORD)acrCustClr;

		break;
	case WM_SIZE:
		//OnSize(hWnd, hWndToolBar);
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
			yInc = -1; break;
		case SB_LINEDOWN:
			yInc - 1;
			break;
		case SB_PAGEUP:
			yInc = -(int)doc.vsi.nPage; break;
		case SB_PAGEDOWN:
			yInc = (int)doc.vsi.nPage; break;
		case SB_THUMBTRACK:
			yInc = HIWORD(wParam) - doc.vsi.nPos; break;
		default: yInc = 0;
		}
		doc.UpdateVscroll(hWnd, yInc);
		currY = -doc.vsi.nPos * doc.yStep;
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
				xInc = - (int)doc.hsi.nPage; 
				break;
			case SB_PAGERIGHT:
				xInc = (int)doc.hsi.nPage; 
				break;
			case SB_THUMBTRACK:
				xInc = HIWORD(wParam) - doc.hsi.nPos;
				break;
				default: xInc = 0;
			}
			doc.UpdateHscroll(hWnd, xInc);
			currX = -doc.hsi.nPos * doc.xStep;
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
				pText = "Ромб";
				break;
			case IDB_LINE:
				pText = "Лінія";
				break;
			case IDB_RECT:
				pText = "Ïðÿìî";
				break;
			case IDB_ELLIPSE:
				pText = "Åëë³ïñ";
				break;
			case IDB_CUBE:
				pText = "Êóá";
				break;
			case IDB_CILINDER:
				pText = "Öèë³íäð";
				break;
			case IDB_PUNCKT:
				pText = "Ïóíêòèðíà ë³í³ÿ";
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
            // Ðàçîáðàòü âûáîð â ìåíþ:
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
			case IDM_STDCOLOR:
				if (ChooseColor(&ccs))
				{
					stdColor = ccs.rgbResult;
					obj_editor.Reset(hWnd, wParam, hWndToolBar);
				}
				break;
			case IDM_PENCOLOR:
				if (ChooseColor(&penCCS))
				{
					penColor = penCCS.rgbResult;
					obj_editor.Reset(hWnd, wParam, hWndToolBar);
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

// Îáðàáîò÷èê ñîîáùåíèé äëÿ îêíà "Î ïðîãðàììå".
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