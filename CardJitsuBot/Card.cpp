#include <iostream>
#include <Windows.h>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(string src) : src(src) {
	SetCardName();
	SetCardValue();
}

void Card::SetCardName() {
	size_t slashPos = src.find('\\');
	size_t dotPos = src.find('.');
	cardName = src.substr(slashPos + 1, dotPos);
}

void Card::SetCardValue() {
	size_t underscorePos = src.find('_');

	string valueStr = src.substr(underscorePos + 1, 1);
	int value = stoi(valueStr);
	if (value == 1) {
		cardValue = 10;
	}
	else 
		cardValue = value;
}