#include "Card.h"
#include "SelectCard.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "StartNewGame.h"


using namespace std;

void SelectCard(Card& bestCard) {
	SetCursorPos(bestCard.getXpos() + 50, bestCard.getYpos() + 50);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	cout << "Clicked card " << bestCard.GetCardName() << endl;

	if (bestCard.GetCardName() == "o_0.png") {
		StartNewGame();
		return;
	}
	return;
}
