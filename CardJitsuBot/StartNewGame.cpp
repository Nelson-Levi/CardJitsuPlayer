#include <iostream>
#include <Windows.h>

using namespace std;

void StartNewGame() {
	Sleep(4000);
	cout << "Starting new game." << endl;

	// Move cursor to second mat
	SetCursorPos(1100, 800);
	Sleep(250);

	// Click the last mat
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	// We have to wait a little while for our penguin to walk over
	Sleep(4500);
	cout << "You should have walked over here" << endl;

	// Now we must click Yes to start the game
	cout << "Clicking Yes to start the game." << endl;
	SetCursorPos(800, 600);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(250);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	return;
}