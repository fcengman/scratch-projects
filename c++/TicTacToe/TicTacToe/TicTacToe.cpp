// TicTacToe.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "TicTacToe.h"
#include <windowsx.h>

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
    LoadStringW(hInstance, IDC_TICTACTOE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TICTACTOE));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TICTACTOE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TICTACTOE);
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
// Global Variables for the game.
const int CELL_SIZE = 100;
HBRUSH hbr1, hbr2;
int turn = 1;
int board[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int winner = 0;

BOOL GetGameBoardRect(HWND hWnd, RECT* pRect) {
    RECT rc;
    if (GetClientRect(hWnd, &rc))
    {
        int width = rc.right - rc.left;
        int height = rc.bottom - rc.top;
        pRect->left = (width - CELL_SIZE * 3) / 2;
        pRect->top = (height - CELL_SIZE * 3) / 2;
        pRect->right = pRect->left + CELL_SIZE * 3;
        pRect->bottom = pRect->top + CELL_SIZE * 3;
        return TRUE;
    }
    SetRectEmpty(pRect);
    return FALSE;
}

void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}

int ClickOnBoard(HWND hwnd, int x, int y)
{
    RECT rc;
    POINT pt = { x, y };
    if (GetGameBoardRect(hwnd, &rc))
    {
        if (PtInRect(&rc, pt))
        {
            //User clicked inside game board
            //Reference point on CELL_SIZE
            x = pt.x - rc.left;
            y = pt.y - rc.top;
            int column = x / CELL_SIZE;
            int row = y / CELL_SIZE;
            int cell = row *3 + column;
            return cell;
        }
    }
    return -1;
}

BOOL GetCellRect(HWND hwnd, int index, RECT* pRect)
{
    RECT rcBoard;
    SetRectEmpty(pRect);
    if (index < 0 || index > 8)
    {
        return FALSE;
    }

    if (GetGameBoardRect(hwnd, &rcBoard))
    {
        //Convert index to x, y pair
        int x = index / 3; //Row Numnber
        int y = index % 3; //Column Number

        pRect->left = rcBoard.left + y * CELL_SIZE + 1;
        pRect->top = rcBoard.top + x * CELL_SIZE +1;
        pRect->right = pRect->left + CELL_SIZE -1 ;
        pRect->bottom = pRect->top + CELL_SIZE -1;
        return TRUE;
    }
    
    return FALSE;
}

/*
* Returns:
* 0 - No Winner
* 1 - Player wins
* 2 - Player wins
* 3 - draw
*/
int CheckWinner(int wins[3])
{
    int cells[] = { 0, 1, 2,   3, 4, 5,    6, 7, 8,   0, 3, 6,   1, 4, 7,   2, 5, 8,   0, 4, 8,  2, 4, 6 };
    for (int i = 0; i < ARRAYSIZE(cells); i += 3)
    {
        if (board[cells[i]]!=0 && board[cells[i]] == board[cells[i + 1]] && board[cells[i]] == board[cells[1 + 2]]) {
            wins[0] = cells[i];
            wins[1] = cells[i + 1];
            wins[2] = cells[i + 2];
            return board[cells[i]];
        }
    }

    for (int i = 0; i < ARRAYSIZE(board); ++i)
    {
        if (board[i] == 0)
        {
            return 0;
        }
    }
        
    return 3;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        hbr1 = CreateSolidBrush(RGB(255, 0, 0));
        hbr2 = CreateSolidBrush(RGB(0, 255, 0));
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
    case WM_LBUTTONDOWN:
        {
            int x = GET_X_LPARAM(lParam);
            int y = GET_Y_LPARAM(lParam);
            if (turn == 0)
                break;
            
            int cell_num = ClickOnBoard(hWnd, x, y);
            
            
            HDC hdc = GetDC(hWnd);
            if (NULL != hdc)
            {
                WCHAR temp[100];
                wsprintf(temp, L"Index = %d", cell_num);
                TextOut(hdc, x, y, temp, lstrlen(temp));
                
                if (cell_num != -1)
                {
                    RECT rcCell;

                    if (board[cell_num] == 0 && GetCellRect(hWnd, cell_num, &rcCell))
                    {
                        board[cell_num] = turn;
                        FillRect(hdc, &rcCell, (turn==2) ? hbr1 : hbr2);
                    }
                    int wins[3];
                    winner = CheckWinner(wins);
                    if (winner == 1 || winner == 2)
                    {
                        MessageBox(hWnd, (winner == 1) ? L"Player 1 is the winner!" : L"Player 2 is the winner!", L"You Win!", MB_OK | MB_ICONINFORMATION);
                        turn = 0;
                    }
                    else if (winner == 3)
                    {
                        //Draw
                        MessageBox(hWnd, L"No wins this time!", L"It's a draw.", MB_OK | MB_ICONINFORMATION);
                        turn = 0;
                    }
                    else if (winner == 0)
                    {
                        turn = (turn == 1) ? 2 : 1;
                    }
                }
                
                ReleaseDC(hWnd, hdc);
            }
        }
        break;
    case WM_GETMINMAXINFO:
    {
        MINMAXINFO* pMinMax = (MINMAXINFO*)lParam;

        pMinMax->ptMinTrackSize.x = CELL_SIZE * 5;
        pMinMax->ptMinTrackSize.y = CELL_SIZE * 5;
        pMinMax->ptMaxTrackSize.x = CELL_SIZE * 10;
        pMinMax->ptMaxTrackSize.y = CELL_SIZE * 10;
    }

    
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            RECT rc;
            if (GetGameBoardRect(hWnd, &rc))
            {
                FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));
                //Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
            }
            // Draw Vertical Line
            for (int i = 0; i < 4; i++) {
                DrawLine(hdc, rc.left+(CELL_SIZE*i), rc.top, rc.left+(CELL_SIZE * i), rc.bottom);
                DrawLine(hdc, rc.left , rc.top + (CELL_SIZE * i), rc.right , rc.top + (CELL_SIZE * i));
            }
            RECT rcCell;
            for (int i = 0; i < ARRAYSIZE(board); ++i)
            {
                if ((board[i] != 0) && GetCellRect(hWnd, i, &rcCell))
                {
                    FillRect(hdc, &rcCell, (board[i] == 1 ? hbr2 : hbr1));
                }
            }
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        DeleteObject(hbr1);
        DeleteObject(hbr2);
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
