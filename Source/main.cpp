// Лабораторная работа №3
//
// Вариант №6:
// Реализовать простейшую игрушку - Тетрис. Т.к. игра должна быть игрой интересной, 
// то и оформлена она должна быть соответствующим образом - красивые кнопочки, красивый бэк, 
// все выводится без морганий и желательно без тормозов на компьютерах в л/р классе. Да, 
// желательно использовать GDI, т.к. я не могу обещать последних версий драйверов для 
// видеокарт (OpenGL) и установленного DirectX 9.0 (соотв. DirectX). Помимо графики, игрушка 
// должна пищать, т.е. воспроизводить какие-нибудь звуки на какие-нибудь события.
//
// Выполнил: Федотов Данила Владимирович, ПРИ-41
#include "resource.h"
#include "game.h"
#include "keyboard.h"

const TCHAR szCaption[] = TEXT("Суперский тетрис");

HINSTANCE hInstance; 
cGame game;

LRESULT APIENTRY WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_COMMAND:
			switch (wParam)
			{
				case ID_NEWGAME:
					game.Start();
					break;
				case ID_PAUSE:
					game.Pause();
					break;
				case ID_EXIT:
					PostQuitMessage(0);
					break;
				default:
					break;
			}
			break;
		case WM_KEYUP:
			switch (wParam)
			{
				case KEY_LEFT:
					game.LeftMove();
					break;
				case KEY_RIGHT:
					game.RightMove();
					break;
				case KEY_DOWN:
					game.DownMove();
					break;
				case KEY_ROTATECW:
					game.RotateClockWise();
					break;
				case KEY_ROTATECCW:
					game.RotateCounterClockWise();
					break;
				case KEY_NEWGAME:
					game.Start();
					break;
				case KEY_PAUSE:
					game.Pause();
					break;
				default:
					break;
			}
			break;
		case WM_ERASEBKGND:
			return (1);
		case WM_PAINT:
		{
			RECT rc;
			PAINTSTRUCT ps;
			GetClientRect(hWnd, &rc);
			HDC hdc = BeginPaint(hWnd, &ps);
				HDC hMemDC = CreateCompatibleDC(hdc);
				HBITMAP hMemBMP = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
				HBITMAP hOldBMP = (HBITMAP)SelectObject(hMemDC, hMemBMP);
				game.Draw(hMemDC);
				BitBlt(hdc, 0, 0, rc.right, rc.bottom, hMemDC, 0, 0, SRCCOPY);
				SelectObject(hMemDC, hOldBMP);
				DeleteObject(hMemBMP);
				DeleteDC(hMemDC);
			EndPaint(hWnd, &ps);
			break;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int nShowCmd)
{
	hInstance = hInst;

	WNDCLASSEX wcx = {0};
	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
    wcx.lpfnWndProc = &WndProc;
    wcx.hInstance = hInst;
    wcx.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR));
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcx.lpszClassName = szCaption;
	wcx.lpszMenuName =MAKEINTRESOURCE(IDR_MENU);
	if ( !RegisterClassEx(&wcx) ) return (0);

	HWND hWnd = CreateWindow(szCaption, szCaption, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, 0,	480, 652, 0, 0, hInst, 0);
	if ( !hWnd ) return (0);

	if (!game.Init(hInst))
		return (0);

	ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

	MSG msg = {0};

	while (true)
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			game.MainProc();
			InvalidateRect(hWnd, 0, FALSE);
		}
	return (1);
}