#include <iostream>
#include <Windows.h>

using namespace std;

#include "Pixel.h"

void Pixel::setColorValues()
{
	// Set the screen barriers
	HDC hdc = GetDC(NULL);
	COLORREF color = GetPixel(hdc, xValue, yValue);

	red = GetRValue(color);
	green = GetGValue(color);
	blue = GetBValue(color);

	cout << "Red" << (int)red << endl;
	cout << "Green" << (int)green << endl;
	cout << "Blue" << (int)blue << endl;

	ReleaseDC(NULL, hdc);
};