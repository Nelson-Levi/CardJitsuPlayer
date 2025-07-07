#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Card
{
private:
	string src;
	string cardName;
	int cardValue;
	int xPos;
	int yPos;

public:
	Card(string src);
	void SetCardValue();
	void SetCardName();
	string GetCardName() { return cardName; }
	int GetCardValue() { return cardValue; }
	string GetCardSrc() { return src; }
	void setXpos(int x) { xPos = x; }
	void setYpos(int y) { yPos = y; }
	int getXpos() { return xPos; }
	int  getYpos() { return yPos; }
};
