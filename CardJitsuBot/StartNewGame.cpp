#include <iostream>
#include <Windows.h>
#include "Globals.h"

using namespace std;

void StartNewGame() {
	Sleep(4000);
	cout << "Starting new game." << endl;

	// Move cursor to second mat
	SetCursorPos(1100, 800);
	Sleep(250);

	// Click the last mat
	cout << "Walking to second mat." << endl;
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetForegroundWindow(consoleWindow);

	// We have to wait a little while for our penguin to walk over
	Sleep(3500);

	// Now we must click Yes to start the game
	cout << "Clicking Yes to start the game." << endl;
	SetCursorPos(800, 600);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetForegroundWindow(consoleWindow);

	return;
}