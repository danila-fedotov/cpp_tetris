#include <windows.h>

class cImage
{
public:
	cImage();
	~cImage();
	bool Load(const char* szFileName, HINSTANCE hInst);
	void Draw(HDC hdc, int x, int y);
private:
	HBITMAP hImage;
	int width;
	int height;
};