#include "figure.h"

cFigure::cFigure()
{
	vField.reserve(5);
	vField.resize(5);
	for (int i = 0 ; i < 5 ; i++)
		vField[i].reserve(5);
}
cFigure::~cFigure()
{
}
void cFigure::NewGenerate()
{
	int iType = (int)(((double) rand() / (double) RAND_MAX) * 8 + 0);
	iColor = (int)(((double) rand() / (double) RAND_MAX) * 4 + 0) + 1;
	bFlag = 1;
	switch (iType)
	{
		case 0:
			x = -2; y = 3;
			n =  5; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 0 ; vField[0][2] = 0 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 0 ; vField[1][2] = 0 ; vField[1][3] = 0 ;
			vField[2][0] = 1 ; vField[2][1] = 1 ; vField[2][2] = 1 ; vField[2][3] = 1 ;
			vField[3][0] = 0 ; vField[3][1] = 0 ; vField[3][2] = 0 ; vField[3][3] = 0 ;
			vField[4][0] = 0 ; vField[4][1] = 0 ; vField[4][2] = 0 ; vField[4][3] = 0 ;
			break;
		case 1:
			x = 0; y = 4;
			n = 2; m = 2;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 1 ; vField[0][1] = 1 ;
			vField[1][0] = 1 ; vField[1][1] = 1 ;
			break;
		case 2:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 1 ; vField[0][2] = 0 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 1 ; vField[1][2] = 1 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 1 ; vField[2][2] = 0 ; vField[2][3] = 0 ;
			break;
		case 3:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 1 ; vField[0][2] = 0 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 1 ; vField[1][2] = 1 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 0 ; vField[2][2] = 1 ; vField[2][3] = 0 ;
			break;
		case 4:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 0 ; vField[0][2] = 1 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 1 ; vField[1][2] = 1 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 1 ; vField[2][2] = 0 ; vField[2][3] = 0 ;
			break;
		case 5:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 1 ; vField[0][2] = 0 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 1 ; vField[1][2] = 0 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 1 ; vField[2][2] = 1 ; vField[2][3] = 0 ;
			break;
		case 6:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 0 ; vField[0][2] = 1 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 0 ; vField[1][2] = 1 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 1 ; vField[2][2] = 1 ; vField[2][3] = 0 ;
			break;
		case 7:
			x = 0; y = 3;
			n = 3; m = 4;
			vField.resize(n);
			for (int i = 0 ; i < n ; i++)
				vField[i].resize(m);
			vField[0][0] = 0 ; vField[0][1] = 1 ; vField[0][2] = 0 ; vField[0][3] = 0 ;
			vField[1][0] = 0 ; vField[1][1] = 1 ; vField[1][2] = 1 ; vField[1][3] = 0 ;
			vField[2][0] = 0 ; vField[2][1] = 1 ; vField[2][2] = 0 ; vField[2][3] = 0 ;
			break;
	}
}
void cFigure::RotateClockwise()
{
	int k = 0;
	std::vector < std::vector <int> > vTempField;
	vTempField.resize(m);
	for (int i = 0 ; i < m ; i++)
		vTempField[i].resize(n);
	vTempField[0][1] = 1;
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			vTempField[i][j] = vField[n - j - 1][i];
	vField.resize(m);
	for (int i = 0 ; i < m ; i++)
		vField[i].resize(n);
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			vField[i][j] = vTempField[i][j];
	k = m;
	m = n;
	n = k;
}
void cFigure::RotateCounterClockwise()
{
	int k = 0;
	std::vector < std::vector <int> > vTempField;
	vTempField.resize(m);
	for (int i = 0 ; i < m ; i++)
		vTempField[i].resize(n);
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			vTempField[i][j] = vField[j][m - i - 1];
	vField.resize(m);
	for (int i = 0 ; i < m ; i++)
		vField[i].resize(n);
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			vField[i][j] = vTempField[i][j];
	k = m;
	m = n;
	n = k;
}
void cFigure::NewPause()
{
	iColor = 6;
	n = 5; m = 19;
	vField.resize(n);
	for (int i = 0 ; i < n ; i++)
		vField[i].resize(m);
	vField[0][0] = 1; vField[0][1] = 1; vField[0][2] = 1; vField[0][3] = 0;
	vField[1][0] = 1; vField[1][1] = 0; vField[1][2] = 1; vField[1][3] = 0;
	vField[2][0] = 1; vField[2][1] = 1; vField[2][2] = 1; vField[2][3] = 0;
	vField[3][0] = 1; vField[3][1] = 0; vField[3][2] = 0; vField[3][3] = 0;
	vField[4][0] = 1; vField[4][1] = 0; vField[4][2] = 0; vField[4][3] = 0;

	vField[0][4] = 1; vField[0][5] = 1; vField[0][6] = 1; vField[0][7] = 0;
	vField[1][4] = 1; vField[1][5] = 0; vField[1][6] = 1; vField[1][7] = 0;
	vField[2][4] = 1; vField[2][5] = 0; vField[2][6] = 1; vField[2][7] = 0;
	vField[3][4] = 1; vField[3][5] = 1; vField[3][6] = 1; vField[3][7] = 0;
	vField[4][4] = 1; vField[4][5] = 0; vField[4][6] = 1; vField[4][7] = 0;

	vField[0][8] = 1; vField[0][9] = 0; vField[0][10] = 1; vField[0][11] = 0;
	vField[1][8] = 1; vField[1][9] = 0; vField[1][10] = 1; vField[1][11] = 0;
	vField[2][8] = 1; vField[2][9] = 0; vField[2][10] = 1; vField[2][11] = 0;
	vField[3][8] = 1; vField[3][9] = 0; vField[3][10] = 1; vField[3][11] = 0;
	vField[4][8] = 1; vField[4][9] = 1; vField[4][10] = 1; vField[4][11] = 0;

	vField[0][12] = 1; vField[0][13] = 1; vField[0][14] = 1; vField[0][15] = 0;
	vField[1][12] = 1; vField[1][13] = 0; vField[1][14] = 0; vField[1][15] = 0;
	vField[2][12] = 1; vField[2][13] = 1; vField[2][14] = 1; vField[2][15] = 0;
	vField[3][12] = 0; vField[3][13] = 0; vField[3][14] = 1; vField[3][15] = 0;
	vField[4][12] = 1; vField[4][13] = 1; vField[4][14] = 1; vField[4][15] = 0;

	vField[0][16] = 1; vField[0][17] = 1; vField[0][18] = 1;
	vField[1][16] = 1; vField[1][17] = 0; vField[1][18] = 0;
	vField[2][16] = 1; vField[2][17] = 1; vField[2][18] = 1;
	vField[3][16] = 1; vField[3][17] = 0; vField[3][18] = 0;
	vField[4][16] = 1; vField[4][17] = 1; vField[4][18] = 1;
}
void cFigure::NewGameOver()
{
	iColor = 7;
	n = 12; m = 18;
	vField.resize(n);
	for (int i = 0 ; i < n ; i++)
		vField[i].resize(m);
	vField[0][0] = 1; vField[0][1] = 1; vField[0][2] = 1; vField[0][3] = 1; vField[0][4] = 0;
	vField[1][0] = 1; vField[1][1] = 0; vField[1][2] = 0; vField[1][3] = 0; vField[1][4] = 0;
	vField[2][0] = 1; vField[2][1] = 0; vField[2][2] = 1; vField[2][3] = 1; vField[2][4] = 0;
	vField[3][0] = 1; vField[3][1] = 0; vField[3][2] = 0; vField[3][3] = 1; vField[3][4] = 0;
	vField[4][0] = 1; vField[4][1] = 1; vField[4][2] = 1; vField[4][3] = 1; vField[4][4] = 0;
	vField[5][0] = 0; vField[5][1] = 0; vField[5][2] = 0; vField[5][3] = 0; vField[5][4] = 0;
	vField[6][0] = 0; vField[6][1] = 0; vField[6][2] = 0; vField[6][3] = 0; vField[6][4] = 0;

	vField[0][5] = 1; vField[0][6] = 1; vField[0][7] = 1; vField[0][8] = 0;
	vField[1][5] = 1; vField[1][6] = 0; vField[1][7] = 1; vField[1][8] = 0;
	vField[2][5] = 1; vField[2][6] = 0; vField[2][7] = 1; vField[2][8] = 0;
	vField[3][5] = 1; vField[3][6] = 1; vField[3][7] = 1; vField[3][8] = 0;
	vField[4][5] = 1; vField[4][6] = 0; vField[4][7] = 1; vField[4][8] = 0;
	vField[5][5] = 0; vField[5][6] = 0; vField[5][7] = 0; vField[5][8] = 0;
	vField[6][5] = 0; vField[6][6] = 0; vField[6][7] = 0; vField[6][8] = 0;

	vField[0][9] = 1; vField[0][10] = 0; vField[0][11] = 0; vField[0][12] = 0; vField[0][13] = 1;
	vField[1][9] = 1; vField[1][10] = 1; vField[1][11] = 0; vField[1][12] = 1; vField[1][13] = 1;
	vField[2][9] = 1; vField[2][10] = 0; vField[2][11] = 1; vField[2][12] = 0; vField[2][13] = 1;
	vField[3][9] = 1; vField[3][10] = 0; vField[3][11] = 0; vField[3][12] = 0; vField[3][13] = 1;
	vField[4][9] = 1; vField[4][10] = 0; vField[4][11] = 0; vField[4][12] = 0; vField[4][13] = 1;
	vField[5][9] = 0; vField[5][10] = 0; vField[5][11] = 0; vField[5][12] = 0; vField[5][13] = 0;
	vField[6][9] = 0; vField[6][10] = 0; vField[6][11] = 0; vField[6][12] = 0; vField[6][13] = 0;

	vField[0][14] = 0; vField[0][15] = 1; vField[0][16] = 1; vField[0][17] = 1;
	vField[1][14] = 0; vField[1][15] = 1; vField[1][16] = 0; vField[1][17] = 0;
	vField[2][14] = 0; vField[2][15] = 1; vField[2][16] = 1; vField[2][17] = 1;
	vField[3][14] = 0; vField[3][15] = 1; vField[3][16] = 0; vField[3][17] = 0;
	vField[4][14] = 0; vField[4][15] = 1; vField[4][16] = 1; vField[4][17] = 1;
	vField[5][14] = 0; vField[5][15] = 0; vField[5][16] = 0; vField[5][17] = 0;
	vField[6][14] = 0; vField[6][15] = 0; vField[6][16] = 0; vField[6][17] = 0;

	vField[7][0]  = 1; vField[7][1]  = 1; vField[7][2]  = 1; vField[7][3]  = 1; vField[7][4]  = 0;
	vField[8][0]  = 1; vField[8][1]  = 0; vField[8][2]  = 0; vField[8][3]  = 1; vField[8][4]  = 0;
	vField[9][0]  = 1; vField[9][1]  = 0; vField[9][2]  = 0; vField[9][3]  = 1; vField[9][4]  = 0;
	vField[10][0] = 1; vField[10][1] = 0; vField[10][2] = 0; vField[10][3] = 1; vField[10][4] = 0;
	vField[11][0] = 1; vField[11][1] = 1; vField[11][2] = 1; vField[11][3] = 1; vField[11][4] = 0;	

	vField[7][5]  = 1; vField[7][6]  = 0; vField[7][7]  = 0; vField[7][8]  = 0; vField[7][9]  = 1;
	vField[8][5]  = 1; vField[8][6]  = 0; vField[8][7]  = 0; vField[8][8]  = 0; vField[8][9]  = 1;
	vField[9][5]  = 0; vField[9][6]  = 1; vField[9][7]  = 0; vField[9][8]  = 1; vField[9][9]  = 0;
	vField[10][5] = 0; vField[10][6] = 1; vField[10][7] = 0; vField[10][8] = 1; vField[10][9] = 0;
	vField[11][5] = 0; vField[11][6] = 0; vField[11][7] = 1; vField[11][8] = 0; vField[11][9] = 0;

	vField[7][10]  = 0; vField[7][11]  = 1; vField[7][12]  = 1; vField[7][13]  = 1; vField[7][14]  = 0;
	vField[8][10]  = 0; vField[8][11]  = 1; vField[8][12]  = 0; vField[8][13]  = 0; vField[8][14]  = 0;
	vField[9][10]  = 0; vField[9][11]  = 1; vField[9][12]  = 1; vField[9][13]  = 1; vField[9][14]  = 0;
	vField[10][10] = 0; vField[10][11] = 1; vField[10][12] = 0; vField[10][13] = 0; vField[10][14] = 0;
	vField[11][10] = 0; vField[11][11] = 1; vField[11][12] = 1; vField[11][13] = 1; vField[11][14] = 0;

	vField[7][15]  = 1; vField[7][16]  = 1; vField[7][17]  = 1;
	vField[8][15]  = 1; vField[8][16]  = 0; vField[8][17]  = 1;
	vField[9][15]  = 1; vField[9][16]  = 1; vField[9][17]  = 1;
	vField[10][15] = 1; vField[10][16] = 1; vField[10][17] = 0;
	vField[11][15] = 1; vField[11][16] = 0; vField[11][17] = 1;
}