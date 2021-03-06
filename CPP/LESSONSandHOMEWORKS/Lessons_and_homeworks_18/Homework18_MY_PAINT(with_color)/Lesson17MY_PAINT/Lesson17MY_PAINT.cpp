// Lesson17MY_PAINT.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Lesson17MY_PAINT.h"
#include "DisplayOutput.h"
#include "FileOutput.h"
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LESSON17MYPAINT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LESSON17MYPAINT));

    MSG msg;

    // Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LESSON17MYPAINT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LESSON17MYPAINT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH hbrush = nullptr; // brush handle
	static DWORD rgbCurrent = 0;    // initial color selection - from ID_TOOLS_COLOR
	static VectorShape vcpShapes;
	static int idShape = ID_SHAPES_RECTANGLE;
	char cFileName[260] = "DEFAULT_PAINT.dat";
	static SaveOpFile file(cFileName);
    switch (message)
    {
	case WM_LBUTTONDOWN:
	case WM_MOUSEMOVE:
	{
		if (wParam == MK_LBUTTON)
		{
			int xPos = LOWORD(lParam);
			int yPos = HIWORD(lParam);
			HDC hdc = GetDC(hWnd);
			if (nullptr != hbrush)
			{
				SelectBrush(hdc, hbrush);
			}
			if (idShape == ID_SHAPES_RECTANGLE)
			{
				Rectangle(hdc, xPos - 10, yPos - 5, xPos + 10, yPos + 20);
				vcpShapes.push_back(new shp::Rectangle("rect", rgbCurrent, { xPos - 10, yPos - 5 },
					{ xPos + 10, yPos + 20 }));
			}
			else if (idShape == ID_SHAPES_CIRCLE)
			{
				Ellipse(hdc, xPos - 10, yPos - 10, xPos + 10, yPos + 10);
				vcpShapes.push_back(new shp::Circle("circ", rgbCurrent, { xPos, yPos }, 10));
			}
			ReleaseDC(hWnd, hdc);
		}
	}
	break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case ID_SHAPES_RECTANGLE:
				idShape = ID_SHAPES_RECTANGLE;
				break;
			case ID_SHAPES_CIRCLE:
				idShape = ID_SHAPES_CIRCLE;
				break;
			case ID_FILE_CLEAR:
				vcpShapes.clear();
				InvalidateRect(hWnd, NULL, TRUE); //redraw the window
				break;
			case ID_FILE_OPEN:
				file.set_name(cFileName);
				file.open(vcpShapes);
				InvalidateRect(hWnd, NULL, TRUE); //redraw the window
				break;
			case ID_FILE_SAVE:
				file.set_name(cFileName);
				file.save(vcpShapes);
				break;
			case ID_FILE_OPEN32776: // Open from
			{
				OPENFILENAMEA ofn;       // common dialog box structure
				char szFile[260];       // buffer for file name
				//HWND hwnd;              // owner window
				FILE* pf;              // file handle

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFile = szFile;
				// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
				// use the contents of szFile to initialize itself.
				ofn.lpstrFile[0] = '\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; //skip certain files
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

				// Display the Open dialog box. 

				if (GetOpenFileNameA(&ofn) == TRUE)
				{
					MessageBoxA(hWnd, szFile, "path", MB_OK);
					file.set_name(szFile);
					file.open(vcpShapes);
					InvalidateRect(hWnd, NULL, TRUE); //redraw the window
				}
			}
			break;
			case ID_FILE_SAVESEC:  // Save to
			{
				OPENFILENAMEA ofn;      // common dialog box structure
				char szFile[260];       // buffer for file name
				//HWND hwnd;            // owner window
				FILE* pf;               // file handle

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFile = szFile;
				// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
				// use the contents of szFile to initialize itself.
				ofn.lpstrFile[0] = '\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; //skip certain files
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

				// Display the Open dialog box. 

				if (GetSaveFileNameA(&ofn) == TRUE)
				{
					MessageBoxA(hWnd, szFile, "path", MB_OK); 
					FileOutput fileOut(szFile);
					vcpShapes.set_object(&fileOut);
					vcpShapes.out_data();
				}
				break;
			}
			case ID_TOOLS_COLOR:
				CHOOSECOLOR cc;                 // common dialog box structure 
				static COLORREF acrCustClr[16]; // array of custom colors 
				//HWND hwnd;                    // owner window
				//static DWORD rgbCurrent;      // initial color selection
				//static BaseOutput* pOut;

				// Initialize CHOOSECOLOR 
				ZeroMemory(&cc, sizeof(cc));
				cc.lStructSize = sizeof(cc);
				cc.hwndOwner = hWnd;
				cc.lpCustColors = (LPDWORD)acrCustClr;
				cc.rgbResult = rgbCurrent;
				cc.Flags = CC_FULLOPEN | CC_RGBINIT;

				if (ChooseColor(&cc) == TRUE)
				{
					hbrush = CreateSolidBrush(cc.rgbResult);
					rgbCurrent = cc.rgbResult;

					//HDC hdc = GetDC(hWnd);
					//SelectBrush(hdc, hbrush);

					//ReleaseDC(hWnd, hdc);
				}
				//MessageBoxA(hWnd, "color", "color", MB_OK);
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
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		DisplayOutput displOut(hdc);
		vcpShapes.set_object(&displOut);
		vcpShapes.out_data(); // { m_pOut -> out_data (this->data()); }

		// TODO: Add any drawing code that uses hdc here...
		/*if (!vcpShapes.empty()) //old version of redrawing
		{
			for (auto pShape : vcpShapes)
				pShape->draw(hdc);
		}*/
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

// Message handler for about box.
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
