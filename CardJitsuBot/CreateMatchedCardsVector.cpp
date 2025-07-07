#include "CreateCardsVector.h"
#include <vector>
#include "Card.h"
#include <opencv2/opencv.hpp>
#include "CheckMatch.h"
#include "FullscreenCapture.h"
#include <iostream>

using namespace std;

vector<Card> CreateMatchedCardsVector(vector<Card>& cards) {
	vector<Card> matchedCards;
	cv::Mat screenshot = FullscreenCapture();
	for (Card card : cards) {
		if (CheckMatch(screenshot, card)) {
			matchedCards.push_back(card);
		}
	}
	if (matchedCards.empty()) {
		cout << "No matches found. Sleeping..." << endl;
		Sleep(10000);
		return CreateMatchedCardsVector(cards);
	}
	else {
		return matchedCards;
	}
}