#include <stdlib.h>
#include <time.h>
#include <vector>

class cFigure
{
public:
	bool bFlag;
	int x;
	int y;
	int n;
	int m;
	int iColor;
	std::vector < std::vector <int> > vField; // n x m

	cFigure();
	~cFigure();
	void NewGenerate();
	void RotateClockwise();
	void RotateCounterClockwise();
	void NewPause();
	void NewGameOver();
};