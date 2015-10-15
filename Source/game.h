#include "image.h"
#include "figure.h"

const int n = 20;
const int m = 10;

class cWinStr
{
public:
	std::vector <int> vStr;

	cWinStr();
	~cWinStr();
	void AddStr(int iVal);
};

class cGame
{
public:
	cGame();
	~cGame();
	bool Init(HINSTANCE hInst);
	void Draw(HDC hdc);
	void MainProc();
	void Start();
	void LeftMove();
	void RightMove();
	void DownMove();
	void RotateClockWise();
	void RotateCounterClockWise();
	void Pause();
private:
	int iAction, iActionUtil;
	int vField[n][m];
	cFigure FCur, FNext, FPause, FGameOver;
	cImage IFon;
	cImage ICells[8];		//RedGreenBlueYellowGray
	cWinStr WStr;

	void Screen();
	void NullField();
	bool Check();
	void GameOver();
	void AddField();
	bool CheckWin();
};