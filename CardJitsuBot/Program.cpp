#include <iostream>
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <filesystem>
#include "opencv2/imgproc.hpp"
#include "Pixel.h"
#include "FullscreenCapture.h"
#include <vector>
#include "Card.h"
#include <string>
#include "CheckMatch.h"
#include "FindBestCard.h"
#include "SelectCard.h"
#include "CreateCardsVector.h"
#include "CreateMatchedCardsVector.h"
#include "Globals.h"

using namespace cv;
using namespace std;
namespace fs = std::filesystem;
HWND consoleWindow = GetConsoleWindow();


int main()
{
	SetProcessDPIAware();
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
	vector<Card> cards = CreateCardsVector();

	while (true) {
		Mat screenshot = FullscreenCapture();
		vector<Card> matchedCards = CreateMatchedCardsVector(cards);

		Card bestCard = FindBestCard(matchedCards);
		SelectCard(bestCard);

		SetForegroundWindow(consoleWindow);
		cout << "Sleeping..." << endl;
		Sleep(10000);
	}

	waitKey(0);
	return 0;
}