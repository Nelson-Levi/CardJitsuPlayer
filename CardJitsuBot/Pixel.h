#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Pixel
{
private:
	int xValue;
	int yValue;
	BYTE red;
	BYTE green;
	BYTE blue;

public:
	Pixel(int x, int y) {
		xValue = x;
		yValue = y;
		red = 0;
		green = 0;
		blue = 0;
	}
	void setColorValues();
};
