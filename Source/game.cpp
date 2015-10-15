#include "game.h"

const DWORD dwDelay = 500;
HANDLE hTimer;
HANDLE hStartTimer;
HANDLE hEndTimer;
bool bDestroyTimer = 1;

cWinStr::cWinStr()
{
	vStr.reserve(4);
}
cWinStr::~cWinStr()
{
}
void cWinStr::AddStr(int iVal)
{
	vStr.push_back(iVal);
}

DWORD WINAPI TimerProc(LPVOID lParam)
{
	while (bDestroyTimer)
	{
		WaitForSingleObject(hStartTimer, INFINITE);
		Sleep(dwDelay);
		SetEvent(hEndTimer);
	}
	return(0);
}
cGame::cGame()
{
	srand((unsigned)time(NULL));
	hStartTimer = CreateEvent(0, FALSE, FALSE, 0);
	hEndTimer = CreateEvent(0, FALSE, FALSE, 0);
	hTimer = CreateThread(0, 0, TimerProc,(LPVOID) 1, 0, 0);
	Screen();
	FPause.NewPause();
	FGameOver.NewGameOver();
}
cGame::~cGame()
{
}
bool cGame::Init(HINSTANCE hInst)
{
	bool f(0);
	f = f | IFon.Load("data/fon.BMP", hInst);
	f = f | ICells[0].Load("data/red.BMP", hInst);
	f = f | ICells[1].Load("data/green.BMP", hInst);
	f = f | ICells[2].Load("data/blue.BMP", hInst);
	f = f | ICells[3].Load("data/yellow.BMP", hInst);
	f = f | ICells[4].Load("data/gray.BMP", hInst);
	f = f | ICells[5].Load("data/pause.BMP", hInst);
	f = f | ICells[6].Load("data/gameover1.BMP", hInst);
	f = f | ICells[7].Load("data/gameover2.BMP", hInst);
	return f;
}
void cGame::Draw(HDC hdc)
{
	IFon.Draw(hdc, 0, 0);
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			if (vField[i][j] != 0)
 				ICells[vField[i][j] - 1].Draw(hdc, j * 30, i * 30);
	if (FCur.bFlag)
		for (int i = 0 ; i < FCur.n ; i++)
			for (int j = 0;j < FCur.m ; j++)
				if (FCur.vField[i][j] != 0)
					ICells[FCur.iColor - 1].Draw(hdc, (j + FCur.y) * 30, (i + FCur.x) * 30);
		for (int i = 0 ; i < FNext.n ; i++)
			for (int j = 0;j < FNext.m ; j++)
				if (FNext.vField[i][j] != 0)
					ICells[FNext.iColor - 1].Draw(hdc, (j + FNext.y + 8) * 30, (i + FNext.x + 1) * 30);
	if (iAction > 2)
		Sleep(200);
	if (iAction == -1)
		for (int i = 0 ; i < FPause.n ; i++)
			for (int j = 0;j < FPause.m ; j++)
				if (FPause.vField[i][j] != 0)
					ICells[FPause.iColor - 1].Draw(hdc, j * 20 + 50, i * 20 + 250);
	if (iAction == 5)
		for (int i = 0 ; i < FGameOver.n ; i++)
			for (int j = 0;j < FGameOver.m ; j++)
				if (FGameOver.vField[i][j] != 0)
					ICells[FGameOver.iColor - 1].Draw(hdc, j * 20 + 60, i * 20 + 200);
}
void cGame::MainProc()
{
	switch (iAction)
	{
		case 0:			// заставка
			Screen();
			break;
		case 1:			// пока не знаю
			if (!FCur.bFlag)
			{
				FCur = FNext;
				FNext.NewGenerate();
			}
			if (!Check())
			{
				FCur.bFlag = 0;
				iAction = 5;
				break;
			}
			SetEvent(hStartTimer);
			iAction = 2;
			break;
		case 2:
			{
				int dwDelay = WaitForSingleObject(hEndTimer, 10);
				if (dwDelay != WAIT_TIMEOUT)
				{
					FCur.x++;
					if (!Check())
					{
						FCur.x--;
						AddField();
						if (CheckWin())
							break;
					}
					iAction = 1;
				}
			}
			break;
		case 3:
			{
				int x = (int)WStr.vStr.size() - 1;
				if (x == -1)
				{
					iAction = 1;
					break;
				}
				for (int i = 0 ; i < m ; i++)
					vField[WStr.vStr[x]][i] = 0;
				for (int i = 0 ; i < x ; i++) 
					WStr.vStr[i]++;
				iAction = 4;
			}
			break;
		case 4:
			for (int i = WStr.vStr[WStr.vStr.size() - 1] ; i > 0 ; i--)
				for (int j = 0 ; j < m ; j++)
					vField[i][j] = vField[i - 1][j];
			WStr.vStr.pop_back();
			iAction = 3;
			break;
		case 5:
			FGameOver.iColor = 56 / FGameOver.iColor;
			Sleep(150);
			break;
		default:
			break;
	}
}
void cGame::Start()
{
	NullField();
	iAction = 1;
	iActionUtil = -1;
	FCur.bFlag = 0;
	FNext.NewGenerate();
}
void cGame::LeftMove()
{
	if (iAction > 0 && FCur.bFlag != 0)
	{
		FCur.y--;
		if (!Check())
			FCur.y++;
	}
}
void cGame::RightMove()
{
	if (iAction > 0 && FCur.bFlag != 0)
	{
		FCur.y++;
		if (!Check())
			FCur.y--;
	}
}
void cGame::DownMove()
{
	if (iAction > 0 && FCur.bFlag != 0)
	{
		FCur.x++;
		if (!Check())
			FCur.x--;
	}
}
void cGame::RotateClockWise()
{
	if (iAction > 0 && FCur.bFlag != 0)
	{
		FCur.RotateClockwise();
		if (!Check())
			FCur.RotateCounterClockwise();
	}
}
void cGame::RotateCounterClockWise()
{
	if (iAction > 0 && FCur.bFlag != 0)
	{
		FCur.RotateCounterClockwise();
		if (!Check())
			FCur.RotateClockwise();
	}
}
void cGame::Screen()
{
	NullField();
	vField[6][4] = 4; vField[6][5] = 4;
	vField[7][3] = 3; vField[7][4] = 3; vField[7][5] = 3; vField[7][6] = 3;
	vField[8][2] = 3; vField[8][7] = 3;
	vField[8][3] = 2; vField[8][4] = 2; vField[8][5] = 2; vField[8][6] = 2;
	vField[9][1] = 4; vField[9][2] = 3; vField[9][7] = 3; vField[9][8] = 4;
	vField[9][3] = 2; vField[9][4] = 1; vField[9][5] = 1; vField[9][6] = 2;
	vField[13][4] = 4; vField[13][5] = 4;
	vField[12][3] = 3; vField[12][4] = 3; vField[12][5] = 3; vField[12][6] = 3;
	vField[11][2] = 3; vField[11][7] = 3;
	vField[11][3] = 2; vField[11][4] = 2; vField[11][5] = 2; vField[11][6] = 2;
	vField[10][1] = 4; vField[10][2] = 3; vField[10][7] = 3; vField[10][8] = 4;
	vField[10][3] = 2; vField[10][4] = 1; vField[10][5] = 1; vField[10][6] = 2;
}
void cGame::NullField()
{
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			vField[i][j] = 0;
}
bool cGame::Check()
{
	int res = 0;
	for (int i = 0 ; i < FCur.n ; i++)
		for (int j = 0 ; j < FCur.m ; j++)
		{
			if (((i + FCur.x) > n - 1) && (FCur.vField[i][j] != 0)) 
				return (0);
			if (((j + FCur.y) > m - 1) && (FCur.vField[i][j] != 0))
			{
				FCur.y--;
				if (!Check())
					FCur.y++;
				continue;
			}
			if (((j + FCur.y) < 0) && (FCur.vField[i][j] != 0))
			{
				FCur.y++;
				if (!Check())
					FCur.y--;
				continue;
			}
			res += FCur.vField[i][j] * vField[i + FCur.x][j + FCur.y];
		}
	return (res==0?1:0);
}
void cGame::GameOver()
{
}
void cGame::AddField()
{
	for (int i = 0 ; i < FCur.n ; i++)
		for (int j = 0 ; j < FCur.m ; j++)
			vField[i + FCur.x][j + FCur.y] += FCur.vField[i][j] * FCur.iColor;
	FCur.bFlag = 0;
}
bool cGame::CheckWin()
{
	int res;
	bool Flag = 0;
	for (int i = 0 ; i < FCur.n ; i++)
	{
		res = 1;
		for (int j = 0 ; j < m ; j++)
			res *= vField[i + FCur.x][j];
		if (res != 0)
		{
			for (int j = 0 ; j < m ; j++)
				vField[i + FCur.x][j] = 5;
			WStr.AddStr(i + FCur.x);
			Flag = 1;
			iAction = 3;
		}
	}
	return Flag;
}
void cGame::Pause()
{
	if (iActionUtil == -1)
	{
		iActionUtil = iAction;
		iAction = -1;
	}
	else
	{
		iAction = iActionUtil;
		iActionUtil = -1;
	}
}