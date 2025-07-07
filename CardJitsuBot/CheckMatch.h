#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include "Card.h"


bool CheckMatch(cv::Mat screenshot, Card& card);
