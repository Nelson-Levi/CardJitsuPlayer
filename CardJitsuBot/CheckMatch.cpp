#include <opencv2/opencv.hpp>
#include <string>
#include "CheckMatch.h"
#include "Card.h"

using namespace std;
using namespace cv;

bool CheckMatch(Mat img, Card& card) {
	string src = card.GetCardSrc();
	Mat templ = imread(src);
	//imshow("Template Image", templ);
	cvtColor(img, img, COLOR_BGR2GRAY);
	cvtColor(templ, templ, COLOR_BGR2GRAY);

	GaussianBlur(img, img, Size(3, 3), 0);
	GaussianBlur(templ, templ, Size(3, 3), 0);

	Mat result;
	Mat img_display;
	Scalar redColor(0, 0, 255);

	img.copyTo(img_display);

	int result_cols = img.cols - templ.cols + 1;
	int result_rows = img.rows - templ.rows + 1;

	result.create(result_rows, result_cols, CV_32FC1);

	matchTemplate(img, templ, result, TM_SQDIFF);

	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	matchLoc = minLoc;

	rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), redColor, 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), redColor, 2, 8, 0);
	//imshow("Source Image", img_display);
	if (matchLoc.y > 800 && matchLoc.y <= 900) {
	//if (card.GetCardName() != "o_0.png") {
		cout << "Match found for " << card.GetCardName() << " at " << matchLoc << endl;
		cout << matchLoc.y << endl;
		//imshow("Source Image", img_display);
		//cout << card.GetCardName() << " is at position: " << matchLoc.x << "," << matchLoc.y << endl;
		card.setXpos(matchLoc.x);
		card.setYpos(matchLoc.y);
		return true;
	}
	else if (card.GetCardName() == "o_0.png" && matchLoc.y > 600 && matchLoc.y <= 700) {
		//646
		//cout << card.GetCardName() << " is at position: " << matchLoc.x << "," << matchLoc.y << endl;
		//cout << "Match found for OK, game ending." << endl;
		card.setXpos(matchLoc.x);
		card.setYpos(matchLoc.y);
		return true;
	}
	else {
		cout << "No match found for " << card.GetCardName() << endl;
		return false;
	}

	return true;
}