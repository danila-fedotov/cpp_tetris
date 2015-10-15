#include "image.h"

cImage::cImage()
{
}
cImage::~cImage()
{
	DeleteObject(hImage);
}
bool cImage::Load(const char *szFileName, HINSTANCE hInst)
{
	BITMAP bm = {0};

	hImage = (HBITMAP)LoadImage(hInst, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (hImage == 0)
		return (0);
	GetObject(hImage, sizeof(BITMAP), (LPSTR)&bm);
	width = bm.bmWidth;
	height = bm.bmHeight;
	return (1);
}
void cImage::Draw(HDC hdc, int x, int y)
{
	HDC hImageDC = CreateCompatibleDC(hdc);
	SelectObject(hImageDC, hImage);
	BitBlt(hdc, x, y, width, height, hImageDC, 0, 0, SRCCOPY);
	DeleteDC(hImageDC);
}