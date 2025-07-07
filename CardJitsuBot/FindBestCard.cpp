#include "Card.h"
#include <vector>
#include <iostream>

using namespace std;

Card FindBestCard(vector <Card> cards) {
	int bestValue = 0;
	Card& bestCard = cards[0];
	for (Card card : cards) {
		if (card.GetCardValue() > bestValue) {
			bestValue = card.GetCardValue();
			bestCard = card;
		}
		else if (card.GetCardValue() == bestValue) {
			if (card.getXpos() < bestCard.getXpos()) {
				bestValue = card.GetCardValue();
				bestCard = card;
			}
		}
		else if (card.GetCardValue() == 0) {
			bestCard = card;
			return bestCard;
		}
	}
	cout << "Best card found: " << bestCard.GetCardName() << " with value " << bestCard.GetCardValue() << endl;
	return bestCard;
}